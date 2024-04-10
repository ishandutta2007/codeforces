#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N], b[N];

long long dp[N][2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + b[i]);
    }
    for (int i = 1; i <= n; ++i)
        ans = max(ans, max(dp[i][0], dp[i][1]));
    cout << ans << endl;
    return 0;
}