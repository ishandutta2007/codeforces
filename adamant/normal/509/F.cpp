#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    int a[n];
    for(auto &it: a) cin >> it;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)
        dp[i][i] = 1;
    for(int i = 0; i + 1 < n; i++)
        dp[i + 1][i] = 1;
    for(int j = 1; j < n; j++)
        for(int i = 0; i + j < n; i++)
        {
            dp[i][i + j] += dp[i + 1][i + j];
            for(int k = 1; k <= j; k++)
                if(a[i] < a[i + k])
                    dp[i][i + j] = (dp[i][i + j] + 1LL * dp[i + 1][i + k - 1] * dp[i + k][i + j]) % mod;
        }
    cout << dp[1][n - 1] << "\n";
}