#include <bits/stdc++.h>
using namespace std;
const int N = 3503;

int n, m, k;
int a[N];

int dp[N][N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int d = n - m + 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            if (d == n - m + 1)
            {
                dp[l][r] = max(a[l], a[r]);
                continue;
            }
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
        }
    }
    k = min(k, m - 1);
    int ans = 0;
    for (int i = 0; i <= k; ++i)
    {
        ans = max(ans, dp[i + 1][n - (k - i)]);
    }
    printf("%d\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}