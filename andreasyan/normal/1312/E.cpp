#include <bits/stdc++.h>
using namespace std;
const int N = 503;

int n;
int a[N];

int dp[N][N];

int dp1[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            if (l == r)
            {
                dp[l][r] = a[l];
                continue;
            }
            for (int i = l; i < r; ++i)
            {
                if (dp[l][i] && dp[i + 1][r] && dp[l][i] == dp[i + 1][r])
                {
                    dp[l][r] = dp[l][i] + 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        dp1[i] = i;
        for (int j = i; j >= 1; --j)
        {
            if (dp[j][i])
                dp1[i] = min(dp1[i], dp1[j - 1] + 1);
        }
    }
    printf("%d\n", dp1[n]);
    return 0;
}