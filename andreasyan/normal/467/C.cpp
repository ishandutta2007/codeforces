#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 5003;
const long long INF = 1000000009000000009;

int n, m, k;
int a[N];

long long p[N];

long long dp[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            dp[i][j] = dp[i - 1][j];
        }
        if (i - m + 1 >= 1)
        {
            for (int j = 1; j <= k; ++j)
            {
                dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + p[i] - p[i - m]);
            }
        }
    }
    printf("%lld\n", dp[n][k]);
    return 0;
}