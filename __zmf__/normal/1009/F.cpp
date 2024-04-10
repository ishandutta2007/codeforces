/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 1e6 + 9;
int n, len[N], son[N], ans[N]; 
vector<int> G[N], dp[N];
inline void dfs1(int u, int f) 
{
	for (auto v : G[u]) 
		if(v != f)
		{
			dfs1(v, u);
			if(len[v] >= len[u]) len[u] = len[v] + 1, son[u] = v;
		}
}
inline void dfs2(int u, int f) 
{
	if(!son[u]) 
	{
		dp[u].push_back(1); ans[u] = 0; return ;
	}
	dfs2(son[u], u);
	swap(dp[u], dp[son[u]]); dp[u].push_back(1);
	ans[u] = ans[son[u]];
	if(dp[u][ans[u]] == 1) ans[u] = len[u];
	for (auto v : G[u])
		if(v != f && v != son[u]) 
		{
			dfs2(v, u);
			for (int i = 0; i <= len[v]; i++) 
			{
				int pos = i + len[u] - (len[v] + 1);
				dp[u][pos] += dp[v][i];
				if((dp[u][pos] > dp[u][ans[u]]) || (dp[u][pos] == dp[u][ans[u]] && pos > ans[u])) ans[u] = pos;
			}
		}
}
signed main()
{
	n = read();
	for (int i = 1; i < n; i++) 
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) printf("%lld\n", len[i] - ans[i]);
	return 0;
}