#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long INF = 1000000000000015;

int n;
int a[4][N];

long long dp[4][N];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    for (int i = 1; i <= 3; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = -INF;
    dp[1][0] = 0;
    long long maxn = dp[3][0];
    long long maxv = dp[1][0];
    for (int j = 1; j <= n; ++j)
    {
        maxn += a[1][j];
        maxn += a[2][j];
        maxn += a[3][j];
        maxv += a[1][j];
        maxv += a[2][j];
        maxv += a[3][j];

        dp[1][j] = max(dp[1][j], dp[1][j - 1] + a[1][j]);
        dp[1][j] = max(dp[1][j], dp[2][j - 1] + a[2][j] + a[1][j]);
        dp[1][j] = max(dp[1][j], maxn);
        ///////////////////////////////////////////////////////////
        dp[2][j] = max(dp[2][j], dp[1][j - 1] + a[1][j] + a[2][j]);
        dp[2][j] = max(dp[2][j], dp[2][j - 1] + a[2][j]);
        dp[2][j] = max(dp[2][j], dp[3][j - 1] + a[3][j] + a[2][j]);
        ///////////////////////////////////////////////////////////
        dp[3][j] = max(dp[3][j], maxv);
        dp[3][j] = max(dp[3][j], dp[2][j - 1] + a[2][j] + a[3][j]);
        dp[3][j] = max(dp[3][j], dp[3][j - 1] + a[3][j]);

        maxn = max(maxn, dp[3][j]);
        maxv = max(maxv, dp[1][j]);
    }
    cout << dp[3][n] << endl;
    return 0;
}