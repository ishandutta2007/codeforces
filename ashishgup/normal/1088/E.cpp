#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, mx = -1e9, cnt = 0;
int a[N];
vector<int> g[N];

int dfs(int u, int par)
{
	int cur = a[u];
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		cur += dfs(it, u);
	}
	mx = max(mx, cur);
	return max(cur, 0LL);
}

int dfs2(int u, int par)
{
	int cur = a[u];
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		cur += dfs2(it, u);
	}
	if(cur == mx)
		cnt++, cur = 0;
	return max(cur, 0LL);
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	dfs2(1, 1);
	cout << mx * cnt << " " << cnt;
	return 0;
}