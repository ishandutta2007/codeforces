#include <bits/stdc++.h>
using namespace std;
const int N = 152, INF = 1000000009;

int n, k, s;
int a[N];

int dp[N][N * N], ndp[N][N * N];
int main()
{
    cin >> n >> k >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    s += (k * (k + 1)) / 2;
    s = min(s, (n * (n + 1)) / 2);
    for (int j = 0; j <= k; ++j)
    {
        for (int u = 0; u <= s; ++u)
            dp[j][u] = INF;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            for (int u = 0; u <= s; ++u)
                ndp[j][u] = dp[j][u];
        }
        for (int j = 0; j <= k; ++j)
        {
            for (int u = 0; u <= s; ++u)
            {
                if (u + i <= s)
                    ndp[j + 1][u + i] = min(ndp[j + 1][u + i], dp[j][u] + a[i]);
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }
    int ans = INF;
    for (int u = 0; u <= s; ++u)
    {
        ans = min(ans, dp[k][u]);
    }
    cout << ans << endl;
    return 0;
}