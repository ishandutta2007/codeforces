#include <cstdio>
#include <iostream>

using namespace std;

int A[4][13];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 0, j = 0, k = 0; k < N; ++k) {
        if (j != 0 && i == 2)
            ++i;

        A[i][j] = 1;
        ++i;
        if (i == 4) {
            i = 0;
            ++j;
        }
    }

    printf("+------------------------+\n");
    for (int i = 0; i < 4; ++i) {
        printf("|");
        for (int j = 0; j <= 10; ++j) {
            if (i == 2 && j != 0)
                printf(".");
            else if (A[i][j])
                printf("O");
            else
                printf("#");
            printf(".");
        }

        if (i == 2)
            printf("..|");
        else if (i == 0)
            printf("|D|");
        else
            printf("|.|");

        if (i == 0 || i == 3)
            printf(")");

        printf("\n");
    }
    printf("+------------------------+\n");
}