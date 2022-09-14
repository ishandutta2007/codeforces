#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long n, m, k, p[10000], a[10000], i, j;
    long long dp[5200][5200];
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
        cin >> p[i];
    for (i = 0; i < m; i++)
        a[1] += p[i];
    for (i = 2; i < n - m + 2; i++)
        a[i] = a[i - 1] - p[i - 2] + p[i + m - 2];
    for (i = 0; i <= n; i++)
        for (j = 0; j <= k; j++)
            dp[i][j] = 0;
    dp[m][1] = a[1];
    for (i = m + 1; i <= n; i++)
    {
        for (j = 1; j <= k; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + a[i - m + 1]);
    }
    cout << dp[n][k] << '\n';
    return 0;
}