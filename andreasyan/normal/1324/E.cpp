#include <bits/stdc++.h>
using namespace std;
const int N = 2003, INF = 1000000009;

int n, h, l, r;
int a[N];

int dp[N][N];

int main()
{
    scanf("%d%d%d%d", &n, &h, &l, &r);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < h; ++j)
        {
            int u = (j + a[i + 1] - 1) % h;
            dp[i + 1][u] = max(dp[i + 1][u], dp[i][j] + !!(l <= u && u <= r));
            u = (j + a[i + 1]) % h;
            dp[i + 1][u] = max(dp[i + 1][u], dp[i][j] + !!(l <= u && u <= r));
        }
    }
    int ans = -INF;
    for (int j = 0; j < h; ++j)
        ans = max(ans, dp[n][j]);
    printf("%d\n", ans);
    return 0;
}