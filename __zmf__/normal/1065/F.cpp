/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e6 + 9;
int n, k, dep[N], mn[N], dp[N][2];
vector<int> G[N];
inline void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1;
	mn[u] = 1e9;
	if(G[u].size() == 0) mn[u] = dep[u];
	for (int i = 0; i < G[u].size(); i++)
	{
		dfs1(G[u][i], u);
		mn[u] = min(mn[u], mn[G[u][i]]);
	} 
}
inline void dfs2(int u, int f)
{
	int mx = 0, sum = 0;
	if(G[u].size() == 0)
	{
		dp[u][0] = dp[u][1] = 1;
		return ;
	}
	for (int i = 0; i < G[u].size(); i++)
	{	
		dfs2(G[u][i], u);
		if(mn[G[u][i]] > dep[u] + k) mx = max(mx, dp[G[u][i]][0]);
		else sum += dp[G[u][i]][1], mx = max(mx, dp[G[u][i]][0] - dp[G[u][i]][1]);
	}
	dp[u][1] = sum;
	dp[u][0] = sum + mx;
	//cout << u << " " << dp[u][0] << " " << dp[u][1] << endl;
	return ;
}
signed main()
{
	n = read(); k = read();
	for (int i = 2; i <= n; i++)
	{
		int x = read();
		G[x].push_back(i);
	}
	dfs1(1, 0);
	//for (int i = 1; i <= n; i++) cout << mn[i] << endl;
	dfs2(1, 0);
	cout << max(dp[1][0], dp[1][1]) << endl;
}