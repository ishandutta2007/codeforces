#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, p;
    cin >> n >> k >> p;
    int a[n], b[k];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < k; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + k);
    int dp[k + 1][n + 1];
    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = (int)1e16;
    dp[0][0] = 0;
    for(int i = 1; i <= k; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = min(dp[i - 1][j], j ? max(dp[i - 1][j - 1], abs(a[j - 1] - b[i - 1]) + abs(b[i - 1] - p)): 0);
    cout << dp[k][n] << endl;
    return 0;
}