#include <bits/stdc++.h>
using namespace std;
const int N = 1503;
const long long INF = 1000000000000015;

int n, m;
int a[N][N];

long long dp[N][N];
long long p[N][N], s[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = -INF;
        if (i % 2 == 1)
        {
            long long pp = 0;
            for (int j = 1; j <= m; ++j)
            {
                pp += a[i][j];
                dp[i][j] = p[i - 1][j - 1] + pp;
            }
        }
        else
        {
            dp[i][m] = -INF;
            long long pp = 0;
            for (int j = 1; j < m; ++j)
            {
                pp += a[i][j];
                dp[i][j] = s[i - 1][j + 1] + pp;
            }
        }
        p[i][0] = dp[i][0];
        for (int j = 1; j <= m; ++j)
            p[i][j] = max(p[i][j - 1], dp[i][j]);
        s[i][m] = dp[i][m];
        for (int j = m - 1; j >= 0; --j)
            s[i][j] = max(s[i][j + 1], dp[i][j]);
    }
    cout << p[n][m] << endl;
    return 0;
}