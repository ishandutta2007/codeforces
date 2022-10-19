#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int n = 8, L = 840, N = 10;

long long w;
long long q[N];

long long dp[N][L * N];

void solv()
{
    scanf("%lld", &w);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &q[i]);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < L * N; ++j)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < L * N; ++j)
        {
            if (dp[i][j] == -1)
                continue;
            for (int k = 0; k <= min((long long)L / (i + 1) - 1, q[i + 1]); ++k)
            {
                dp[i + 1][j + k * (i + 1)] = max(dp[i + 1][j + k * (i + 1)], dp[i][j] + (q[i + 1] - k) / (L / (i + 1)));
            }
        }
    }
    long long ans = 0;
    for (int j = 0; j < L * N; ++j)
    {
        if (dp[n][j] == -1)
            continue;
        if (j <= w)
        {
            ans = max(ans, j + min(dp[n][j], ((w - j) / L)) * L);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}