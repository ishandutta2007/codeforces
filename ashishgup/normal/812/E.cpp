#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, mx;
int a[N], val[2], cnt[2];
map<int, int> f[2];
vector<int> g[N];
 
void dfs(int u, int par, int lvl)
{
	mx = max(mx, lvl);
	f[lvl % 2][a[u]]++;
	val[lvl % 2] ^= a[u];
	cnt[lvl % 2]++;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u, lvl + 1);
	}
}
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 2; i <= n; i++)
	{
		int par;
		cin >> par;
		g[par].push_back(i);
	}
	dfs(1, 1, 0);
	mx %= 2;
	if(val[mx] == 0)
	{
		int ans = cnt[0] * (cnt[0] - 1) / 2;
		ans += cnt[1] * (cnt[1] - 1) / 2;
		for(auto &it:f[0])
			ans += it.second * f[1][it.first];
		cout << ans << endl;
	}
	else
	{
		int ans = 0;
		for(auto &it:f[0])
			ans += it.second * f[1][it.first ^ val[mx]];
		cout << ans << endl;
	}
	return 0;
}