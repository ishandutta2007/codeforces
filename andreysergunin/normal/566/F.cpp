#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1200000;


using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[MAXN];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int dp[MAXN];
    for (int i = 1; i <= 1e6 + 10; i++)
        dp[i] = 0;
    dp[a[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        dp[a[i]] = 1;
        for (int j = 2; j * a[i] <= 1e6 + 10; j++)
            dp[a[i]] = max(dp[a[i]], dp[j * a[i]] + 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[a[i]]);
    printf("%d", ans);
    return 0;
}