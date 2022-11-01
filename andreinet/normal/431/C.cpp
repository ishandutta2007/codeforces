#include <cstdio>

using namespace std;

const int Nmax = 105, MOD = 1000000007;

int Dp[Nmax][Nmax], S[Nmax][Nmax];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    int N, K, D;
    scanf("%d%d%d", &N, &K, &D);

    Dp[0][0] = 1;
    for (int i = 0; i <= K; i++) S[0][i] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            for (int k = 1; k <= j && i - k >= 0; k++)
            {
                if (k < j) Dp[i][j] += Dp[i - k][j];
                else Dp[i][j] += S[i - k][j];

                Dp[i][j] %= MOD;
            }
            S[i][j] = (S[i][j - 1] + Dp[i][j]) % MOD;
        }
    }

    int Sol = 0;
    for (int i = D; i <= K; i++) Sol = (Sol + Dp[N][i]) %MOD;

    printf("%d\n", Sol);
}