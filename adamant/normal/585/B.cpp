#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
	int n, k;
	cin >> n >> k;
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	s[0] += string(3 * s[0].size(), '.');
	s[1] += string(3 * s[1].size(), '.');
	s[2] += string(3 * s[2].size(), '.');
	int m = s[0].size();
	int dp[3][m + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= m; i++)
		for(int j = 0; j < 3; j++)
			dp[j][i] = s[j][i] == 's';
	for(int i = 3; i <= m; i++)
		for(int j = 0; j < 3; j++)
		{
			if(s[j][i] != '.' || s[j][i - 2] != '.')
				continue;
			dp[j][i] |= dp[j][i - 3];
			if(j != 0)
				if(s[j - 1][i - 2] == '.')
					dp[j][i] |= dp[j - 1][i - 3];
			if(j != 2)
				if(s[j + 1][i - 2] == '.')
					dp[j][i] |= dp[j + 1][i - 3];
			if(dp[j][i] && i > 2 * n)
			{
				cout << "YES\n";
				return;
			}
		}
		
	
	cout << "NO\n";
	
}

main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}