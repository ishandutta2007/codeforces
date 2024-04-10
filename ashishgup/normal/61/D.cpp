#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int dp[N][2];
vector<pair<int, int> > g[N];

void dfs(int u, int par)
{
	int &returnBack = dp[u][0];
	int &noReturn = dp[u][1];
	for(auto &it:g[u])
	{
		if(it.first == par)
			continue;
		dfs(it.first, u);
		returnBack += it.second * 2 + dp[it.first][0];
	}	
	noReturn = returnBack;
	for(auto &it:g[u])
	{
		if(it.first == par)
			continue;
		int cur = returnBack - it.second * 2 - dp[it.first][0] + it.second + dp[it.first][1];
		noReturn = min(noReturn, cur);
	}	
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(1, 1);
	cout << dp[1][1];
	return 0;
}