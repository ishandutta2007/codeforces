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
int x1, x2, n, mx, pp, a, b, c, d;
int dep[N], to[N];
vector<int> G[N];
inline void dfs1(int u, int f)
{
	int son = 0, mx2 = 0;
	dep[u] = dep[f] + 1;
	for (int i = 0; i < G[u].size(); i++)
		if(G[u][i] != f)
		{
			dfs1(G[u][i], u);
			if(dep[to[G[u][i]]] > dep[to[u]]) mx2 = to[u], to[u] = to[G[u][i]];
			else if(dep[to[G[u][i]]] > dep[mx2]) mx2 = to[G[u][i]];
			son++;
		}
	if(!son) to[u] = u;
	if(son > 1 && (dep[u] > dep[mx] || (dep[u] == dep[mx] && dep[mx2] + dep[to[u]] > pp)))
	{
		pp = dep[mx2] + dep[to[u]];
		mx = u;
	}
}
inline void dfs2(int u)
{
	int son = 0;
	for (int i = 0; i < G[u].size(); i++)
		if(dep[G[u][i]] > dep[u])
		{
			son++;
			dfs2(G[u][i]);
		}
	if(son == 0)
	{
		if(dep[x1] < dep[u]) x2 = x1, x1 = u;
		else if(dep[x2] < dep[u]) x2 = u;
	}
}
signed main()
{
	n = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1, 0); x1 = x2 = 0;
	dfs2(mx);
	a = x1, c = x2; pp = 0; 
	int u = mx; mx = 0; x1 = x2 = 0; 
	memset(dep, 0, sizeof(dep));
	memset(to, 0, sizeof(to));
	dfs1(u, 0); 
	dfs2(mx); 
	b = x1, d = x2;
	printf("%lld %lld\n%lld %lld\n", a, b, c, d);
	return 0;
}	
// qwq