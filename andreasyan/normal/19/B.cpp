#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
const long long INF = 2003000000009;

int n;
int t[N];
int c[N];

long long dp[N][N * 2];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> c[i];

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n + n; ++j)
        {
            dp[i][j] = INF;
        }
    }

    dp[0][n] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n + n; ++j)
        {
            if (j)
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
            dp[i + 1][min(j + t[i + 1], n + n)] = min(dp[i + 1][min(j + t[i + 1], n + n)], dp[i][j] + c[i + 1]);
        }
    }

    long long ans = INF;
    for (int j = n; j <= n + n; ++j)
        ans = min(ans, dp[n][j]);
    cout << ans << endl;
    return 0;
}