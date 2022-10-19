#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1003, M = 10004;
const long long INF = 1000000009000000009;

int n, W, B, X;
int q[N], g[N];

long long dp[M], ndp[M];

int main()
{
    scanf("%d%d%d%d", &n, &W, &B, &X);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &q[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &g[i]);
    dp[0] = W;
    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= p + q[i]; ++j)
            ndp[j] = -INF;
        for (int j = 0; j <= p; ++j)
        {
            for (int k = 0; k <= q[i]; ++k)
            {
                if (dp[j] < k * 1LL * g[i])
                    break;
                ndp[j + k] = max(ndp[j + k], min(dp[j] - k * 1LL * g[i] + X, W + (j + k) * 1LL * B));
            }
        }
        p += q[i];
        for (int j = 0; j <= p; ++j)
            dp[j] = ndp[j];
    }
    for (int j = p; j >= 0; --j)
    {
        if (dp[j] >= 0)
        {
            printf("%d\n", j);
            return 0;
        }
    }
    return 0;
}