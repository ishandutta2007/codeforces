#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2005;
const int M = 1e5 + 5;
const int MOD = 1e9 + 7;
 
int n, m;
string s;
int bal[N];
int cache[N][2][N];
int pref = 0, mn = 1e9;
 
int dp(int i, int cur, int bal)
{
	if(bal < 0)
		return 0;
	if(bal > 2e3)
		return 0;
	if(i == n - m && cur == 1)
		return (bal == 0);
	if(i > n - m)
		return 0;
	int &ans = cache[i][cur][bal];
	if(ans != -1)
		return ans;
	ans = 0;
	if(cur == 0)
	{
		if(mn >= 0)
			ans = dp(i, 1, bal + pref);
		else
		{
			if(bal >= abs(mn))
				ans = dp(i, 1, bal + pref);
		}
		ans += dp(i + 1, 0, bal - 1) + dp(i + 1, 0, bal + 1);
 
	}
	else
		ans += dp(i + 1, 1, bal - 1) + dp(i + 1, 1, bal + 1);
	ans %= MOD;
	return ans;
 
}
 
int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> s;
	pref = 0;
	for(int i = 0; i < s.size(); i++)
	{
		pref += (s[i] == '(');
		pref -= (s[i] == ')');
		mn = min(pref, mn);
	}
	int ans = dp(0, 0, 0);
	cout << ans;
	return 0;
}