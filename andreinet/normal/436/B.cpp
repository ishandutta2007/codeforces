#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 2005;


char A[Nmax][Nmax];
int N, M, K;

int Sol[Nmax];

bool inside(const int x, const int y)
{
    if (x < 1 || x > N) return 0;
    if (y < 1 || y > M) return 0;
    return 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    scanf("%d %d %d\n", &N, &M, &K);

    for (int i = 1; i <= N; i++)
        fgets(A[i] + 1, Nmax, stdin);

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int x = i - 1;

            if (inside(i, j - x) && A[i][j - x] == 'R') Sol[j]++;
            if (inside(i, j + x) && A[i][j + x] == 'L') Sol[j]++;
            if (inside(i - x, j) && A[i - x][j] == 'D') Sol[j]++;
            if (inside(i + x, j) && A[i + x][j] == 'U') Sol[j]++;
        }
    }

    for (int i = 1; i <= M; i++)
        printf("%d ", Sol[i]);
    printf("\n");
}