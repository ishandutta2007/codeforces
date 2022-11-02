#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int a[MAX_N];
int n;
int dp[MAX_N][4];
int inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0][0] = 0;
    for (int e = 1; e < 4; e++)
        dp[0][e] = inf;
    if (s[0] == 'h')
    {
        dp[0][0] = a[0];
        dp[0][1] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int e = 0; e < 4; e++)
            dp[i][e] = dp[i - 1][e];
        if (s[i] == 'h')
        {
            dp[i][1] = min(dp[i][1], dp[i][0]);
            dp[i][0] += a[i];
        }
        if (s[i] == 'a')
        {
            dp[i][2] = min(dp[i][2], dp[i][1]);
            dp[i][1] += a[i];
        }
        if (s[i] == 'r')
        {
            dp[i][3] = min(dp[i][3], dp[i][2]);
            dp[i][2] += a[i];
        }
        if (s[i] == 'd')
            dp[i][3] += a[i];
    }
    int ans = dp[n - 1][0];
    for (int e = 1; e < 4; e++)
        ans = min(ans, dp[n - 1][e]);
    cout << ans;
}