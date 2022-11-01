#include <algorithm>
#include <cstdio>

using namespace std;

const int Nmax = 1005;

char A[4 * Nmax][Nmax];

int B[Nmax], V[4 * Nmax];

int main()
{
    //freopen("input", "r", stdin);
   //freopen("output", "w", stdout);

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &B[i]);

    int x = 0, y = 0, lin = 2000, col = 0;
    for (int i = 1; i <= N; i++)
    {
        x += B[i];
        if (i % 2) y += B[i];
        else y -= B[i];

        for (int j = 0; j < B[i]; j++)
        {
            if (i % 2)
                A[lin][col] = '/';
            else
                A[lin][col] = '\\';

            V[lin] = 1;

            if (j < B[i] - 1)
            {
                if (i % 2) lin++;
                else lin--;
            }
            col++;
        }
    }

    for (int i = 4 * Nmax - 3; i >= 0; i--)
    {
        if (V[i])
        {
            for (int j = 0; j < col; j++)
            {
                if (!A[i][j]) A[i][j] = ' ';
            }
            printf("%s\n", A[i]);
        }
    }
}