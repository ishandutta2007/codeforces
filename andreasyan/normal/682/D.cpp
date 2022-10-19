#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m, k;
char a[N], b[N];

int dp[11][N][N];
int p[11][N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
                dp[1][i][j] = dp[1][i - 1][j - 1] + 1;
            p[1][i][j] = max(max(p[1][i - 1][j], p[1][i][j - 1]), dp[1][i][j]);
        }
    }

    for (int kk = 2; kk <= k; ++kk)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (a[i] == b[j])
                    dp[kk][i][j] = p[kk - 1][i - dp[1][i][j]][j - dp[1][i][j]] + dp[1][i][j];
                p[kk][i][j] = max(max(p[kk][i - 1][j], p[kk][i][j - 1]), dp[kk][i][j]);
            }
        }
    }
    int ans = 0;
    for (int kk = 1; kk <= k; ++kk)
        ans = max(ans, p[kk][n][m]);
    cout << ans << endl;
    return 0;
}