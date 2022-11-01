#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 1005;

double Dp[Nmax][Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    cin >> N >> M;

    Dp[0][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            double p1 = (double) (M - j) / ((double)(N * M - (i - 1)));
            double p2 = (double) (M - j + 1) / ((double)(N * M - (i - 1)));

            Dp[i][j] = Dp[i - 1][j] * (1 - p1) + (j > 0 ? Dp[i - 1][j - 1] * p2: 0);
        }
    }

    double Sol = 0;
    for (int i = 1; i <= M; i++)
        Sol = Sol + Dp[N][i] * i * i / ((double)N);

    printf("%.14lf\n", Sol);
}