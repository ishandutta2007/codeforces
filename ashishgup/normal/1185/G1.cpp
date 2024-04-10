#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 15;
const int MOD = 1e9 + 7;

int n, T;
int t[N], g[N];
int cache[1 << N][226][3];

int dp(int mask, int tim, int prv)
{
	if(tim == T)
		return 1;
	int &ans = cache[mask][tim][prv];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(mask >> i & 1)
			continue;
		if(prv == g[i])
			continue;
		if(tim + t[i] > T)
			continue;
		ans += dp(mask | (1 << i), tim + t[i], g[i]);
		ans %= MOD;
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> T;
	for(int i = 0; i < n; i++)
	{
		cin >> t[i] >> g[i];
		g[i]--;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(t[i] <= T)
		{
			ans += dp(1 << i, t[i], g[i]);
			ans %= MOD;
		}
	}
	cout << ans;
	return 0;
}