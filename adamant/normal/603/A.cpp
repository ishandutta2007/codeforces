#include <bits/stdc++.h>

using namespace std;

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int dp[n][2][3];
	memset(dp, 0, sizeof(dp));
	for(auto &it: s)
		it -= '0';
	dp[0][ s[0]][0] = 1;
	dp[0][!s[0]][1] = 1;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			dp[i][0][j] = dp[i - 1][0][j];
			dp[i][1][j] = dp[i - 1][1][j];
		}
		dp[i][ s[i]][0] = max(dp[i][ s[i]][0], dp[i - 1][!s[i]][0] + 1);
		dp[i][!s[i]][1] = max(dp[i][!s[i]][1], max(dp[i - 1][ s[i]][0], dp[i - 1][ s[i]][1]) + 1);
		dp[i][ s[i]][2] = max(dp[i][ s[i]][2], max(dp[i - 1][!s[i]][1], dp[i - 1][!s[i]][2]) + 1);
	}
	int ans = 0;
	for(int i = 1; i <= 2; i++)
		for(int j = 0; j < 2; j++)
			ans = max(ans, dp[n - 1][j][i]);
	cout << ans << "\n";
    return 0;
}