#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 4003, T = 86400, INF = 1000000009;

int n, k;
int t[N], d[N];

int dp[N][N];

void solv()
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            dp[i][j] = INF;
        }
    }
    for (int j = 0; j <= k; ++j)
        dp[0][j] = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, t[i + 1] - dp[i][k]);
        for (int j = 0; j <= k; ++j)
        {
            if (dp[i][j] <= t[i + 1])
                dp[i + 1][j] = min(dp[i + 1][j], t[i + 1] + d[i + 1]);
            else
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + d[i + 1]);
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        }
    }
    ans = max(ans, T - dp[n][k] + 1);
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &t[i], &d[i]);
    solv();
    return 0;
}