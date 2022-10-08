#include <cstdio>

int solution[4][4] = {
    {8, 9, 1, 13},
    {3, 12, 7, 5},
    {0, 2, 4, 11},
    {6, 10, 15, 14},
};

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d", (i / 4 * (n / 4) + (j / 4)) * 16 + solution[i % 4][j % 4]);
            if (j + 1 < n)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }

    return 0;
}