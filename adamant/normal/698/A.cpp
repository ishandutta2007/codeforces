#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(auto &it: a)
    {
        cin >> it;
        it++;
    }
    int dp[3][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = !(a[0] == 2 || a[0] == 4);
    dp[2][0] = !(a[0] == 3 || a[0] == 4);
    for(int i = 1; i < n; i++)
    {
        dp[0][i] = 1 + min({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});
        dp[1][i] = (!(a[i] == 2 || a[i] == 4)) + min(dp[0][i - 1], dp[2][i - 1]);
        dp[2][i] = (!(a[i] == 3 || a[i] == 4)) + min(dp[0][i - 1], dp[1][i - 1]);
        //cout << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << endl;
    }
    cout << min({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << "\n";
	return 0;
}