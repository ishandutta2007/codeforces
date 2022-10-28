#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
const int MOD = 998244353;

int n;
int x[N], y[N], s[N];
int dp[N], pref[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i] >> s[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int prev = y[i];
		auto it = upper_bound(x + 1, x + n + 1, y[i]) - x;
		dp[i] = (x[i] - y[i]) + pref[i - 1] - pref[it - 1] + MOD;
		dp[i] %= MOD;
		pref[i] = pref[i - 1] + dp[i];
		pref[i] %= MOD;
		if(s[i])
			ans += dp[i];
	}
	ans += x[n] + 1;
	ans %= MOD;
	cout << ans;
	return 0;
}