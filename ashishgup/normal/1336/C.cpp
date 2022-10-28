#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;
const int MOD = 998244353;

int n, m;
string s, t;
int dp[N][N];

int32_t main()
{
	IOS;
	cin >> s >> t;
	n = s.size(), m = t.size();
	for(int i = 0; i <= n; i++)
		dp[0][i] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < n - i + 1; j++)
		{
			int &ans = dp[i][j];
			if(j > m - i || s[i - 1] == t[j - 1 + i])
				ans += dp[i - 1][j];
			if(j > m - 1 || s[i - 1] == t[j])
				ans += dp[i - 1][j + 1];
			ans %= MOD;
		}
	}
	int ans = 0;
	for(int i = m; i <= n; i++)
		ans += dp[i][0];
	ans %= MOD;
	cout << ans;
	return 0;
}