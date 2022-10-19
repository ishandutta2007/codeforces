#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];
int g[N];
int p[N];

long long dp[N][N][N][2];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        p[i] = p[i - 1];
        if (a[i] == '1')
            ++p[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> g[i];
        for (int j = 1; j < i; ++j)
            g[i] = max(g[i], g[j] + g[i - j]);
    }

    for (int d = 1; d <= n; ++d)
    {
        for (int i = 1; i <= n - d + 1; ++i)
        {
            int j = (i + d - 1);
            for (int k = 1; k <= n; ++k)
            {
                for (int f = i; f <= j; ++f)
                {
                    if (i == 1 && j == 3 && k == 2 && f == 1)
                        cout << "";
                    if (a[f] == '0' && (j - f + 1) - (p[j] - p[f - 1]) >= k)
                    {
                        dp[i][j][k][0] = max(dp[i][j][k][0], dp[i][f - 1][0][0] + dp[f + 1][j][k - 1][0]);
                        dp[i][j][0][0] = max(dp[i][j][0][0], dp[i][j][k][0] + g[k]);
                    }
                    if (a[f] == '1' && p[j] - p[f - 1] >= k)
                    {
                        dp[i][j][k][1] = max(dp[i][j][k][1], dp[i][f - 1][0][1] + dp[f + 1][j][k - 1][1]);
                        dp[i][j][0][0] = max(dp[i][j][0][0], dp[i][j][k][1] + g[k]);
                    }
                }
            }
            dp[i][j][0][1] = dp[i][j][0][0];
        }
    }

    cout << dp[1][n][0][0] << endl;
    return 0;
}