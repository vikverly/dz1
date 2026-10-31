/*Студент: Черных Виктория Александровна

Группа: ПИ-1-1

Вариант: 7 (Циклический сдвиг)

 

## Краткое описание прогр.

Консольная прогр. на яз. C (стандарт C11) для ввода, проверки и вычисл. осн. стат. характеристик одномерного массива целых чисел, а также вып. цикл. сдвига эл-тов вправо на k поз.
*/
 



#include <stdio.h>

#define MAX_SIZE 100

/* Прототипы осн. ф-ций по методичке */
void inputArray(int array[], int size);
void printArray(const int array[], int size);
int findMin(const int array[], int size);
int findMax(const int array[], int size);
long long calculateSum(const int array[], int size);
double calculateAverage(const int array[], int size);
void performIndividualTask(int array[], int size);

/* Доп. ф-ции для стат. характеристик */
int findFirstIndex(const int array[], int size, int value);
void printSignCounts(const int array[], int size);
void printParityCounts(const int array[], int size);
void printElementsInRange(const int array[], int size, int a, int b);

int main(void)
{
    int array[MAX_SIZE];
    int size;

    printf("Введите размер массива от 1 до %d: ", MAX_SIZE);
    // ИСПРАВЛЕНО: Добавлены операторы || для корректной проверки условий
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE)
    {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    inputArray(array, size);
    printf("Исходный массив: ");
    printArray(array, size);

    /* Поиск мин. и макс. эл-тов и их первых инд. */
    int minVal = findMin(array, size);
    int minIdx = findFirstIndex(array, size, minVal);
    printf("Минимальный элемент: %d (первый индекс: %d)\n", minVal, minIdx);

    int maxVal = findMax(array, size);
    int maxIdx = findFirstIndex(array, size, maxVal);
    printf("Максимальный элемент: %d (первый индекс: %d)\n", maxVal, maxIdx);

    /* Вычисл. суммы и сред. арифм. */
    long long sum = calculateSum(array, size);
    double avg = calculateAverage(array, size);
    printf("Сумма элементов: %lld\n", sum);
    printf("Среднее арифметическое: %.2f\n", avg);

    /* Подсчёт знаков и чётности */
    printSignCounts(array, size);
    printParityCounts(array, size);

    /* Вывод эл-тов из диап. [a, b] */
    int a, b;
    printf("Введите границы диапазона a и b: ");
    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("Ошибка: некорректный ввод границ.\n");
        return 1;
    }
    printElementsInRange(array, size, a, b);

    /* Вып. инд. задания (Вар. 7) */
    performIndividualTask(array, size);

    return 0;
}

/* Ввод эл-тов массива с клав. */
void inputArray(int array[], int size)
{
    printf("Введите %d целых чисел: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

/* Вывод массива в одной строке */
void printArray(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* Поиск знач. мин. эл-та */
int findMin(const int array[], int size)
{
    int min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

/* Поиск знач. макс. эл-та */
int findMax(const int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

/* Поиск первого инд. заданного знач. */
int findFirstIndex(const int array[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            return i;
        }
    }
    return 0;
}

/* Вычисл. суммы эл-тов массива */
long long calculateSum(const int array[], int size)
{
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

/* Вычисл. сред. арифм. как вещ. числа */
double calculateAverage(const int array[], int size)
{
    long long sum = calculateSum(array, size);
    return (double)sum / size;
}

/* Подсчёт кол-ва положит., отрицат. и нулевых эл-тов */
void printSignCounts(const int array[], int size)
{
    int pos = 0;
    int neg = 0;
    int zero = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            pos++;
        }
        else if (array[i] < 0)
        {
            neg++;
        }
        else
        {
            zero++;
        }
    }
    printf("Положительных: %d, отрицательных: %d, нулевых: %d\n", pos, neg, zero);
}

/* Подсчёт кол-ва чётных и нечётных эл-тов */
void printParityCounts(const int array[], int size)
{
    int even = 0;
    int odd = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("Чётных: %d, нечётных: %d\n", even, odd);
}

/* Вывод эл-тов, принадл. диап. [a, b] */
void printElementsInRange(const int array[], int size, int a, int b)
{
    /* Обмен знач., если левая граница больше правой */
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("Элементы в диапазоне [%d, %d]: ", a, b);
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] >= a && array[i] <= b)
        {
            printf("%d ", array[i]);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("нет таких элементов");
    }
    printf("\n");
}

/* Инд. задание — Вар. 7 (Цикл. сдвиг вправо на k поз.) */
void performIndividualTask(int array[], int size)
{
    int k;
    printf("Введите величину сдвига k: ");
    if (scanf("%d", &k) != 1)
    {
        printf("Ошибка: некорректный ввод k.\n");
        return;
    }

    /* Привед. сдвига k к диап. [0, size - 1] */
    k = k % size;
    if (k < 0)
    {
        k = k + size;
    }

    /* Пошаговый цикл. сдвиг вправо k раз по 1 поз. */
    for (int step = 0; step < k; step++)
    {
        int last = array[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            array[i] = array[i - 1];
        }
        array[0] = last;
    }

    printf("Массив после сдвига вправо на k позиций: ");
    printArray(array, size);
}
