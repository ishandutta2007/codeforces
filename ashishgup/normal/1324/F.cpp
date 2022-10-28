#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], ans[N];
int diff[N], dp[N];
vector<int> g[N];

void dfs(int u, int par)
{
	diff[u] = a[u] ? 1 : -1;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u);
		diff[u] += max(0LL, diff[it]);
	}
}

void dfsU(int u, int par)
{
	dp[u] = diff[u];
	if(par)
		dp[u] += max(0LL, dp[par] - max(0LL, diff[u]));
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfsU(it, u);
	}
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
	dfs(1, 0);
	dfsU(1, 0);
	for(int i = 1; i <= n; i++)
		cout << dp[i] << " ";
	return 0;
}