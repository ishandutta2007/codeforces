#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m, canTake = 0, best = 0;
int val[N], dp[N];
bool vis[N];
vector<int> g[N];

int dfs(int u, int par)
{
	vis[u] = 1, dp[u] = val[u];
	bool check = 1;
	int cur = val[u];
	for(auto &it:g[u])
	{
		if(vis[it] && it != par)
			check = 0;
		else if(!vis[it])
		{
			check &= dfs(it, u);
			cur = max(cur, val[u] + dp[it]);
		}
	}
	dp[u] = cur;
	if(!check)
		canTake += val[u];
	else
		best = max(best, dp[u]);
	return check;
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> val[i];
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int src;
	cin >> src;
	dfs(src, src);	
	cout << canTake + best;
	return 0;
}