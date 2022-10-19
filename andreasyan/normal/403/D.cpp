#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1003, K = 50, M = 1000000007;

int f[N];

int c[N][N];

int dp[N][K];

int ans[N][K];

void solv()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    dp[0][0] = 1;
    for (int i = 1; i < N; ++i)
    {
        for (int j = N - 1; j >= 0; --j)
        {
            for (int k = 0; k < K; ++k)
            {
                if (j + i < N && k + 1 < K)
                    dp[i + j][k + 1] = (dp[i + j][k + 1] + dp[j][k]) % M;
            }
        }
    }
    for (int n = 0; n < N; ++n)
    {
        for (int k = 0; k < K; ++k)
        {
            dp[n][k] = (dp[n][k] * 1LL * f[k]) % M;
        }
    }
    for (int n = 0; n < N; ++n)
    {
        for (int k = 0; k < K; ++k)
        {
            for (int m = 0; m <= n; ++m)
            {
                ans[n][k] = (ans[n][k] + dp[m][k] * 1LL * c[n - m + k][k]) % M;
            }
        }
    }
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        if (k >= K)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", ans[n][k]);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}