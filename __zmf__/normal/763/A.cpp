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
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 2e5 + 9;
int n, c[N], fa[N], siz[N], col[N], ans, p[N];
vector<int> G[N];
inline void dfs(int u, int f)
{
	int flag = 0;
	fa[u] = f; siz[u] = 1; c[u] = col[u];
	for (auto v : G[u])
	{
		if(v == f) continue;
		dfs(v, u);
		if(c[u] != c[v]) c[u] = -1;
		if(c[v] == -1) flag = 1;
		siz[u] += siz[v]; 
	}
	p[col[u]]--;
	for (auto v : G[u]) 
		if(c[v] != -1 && v != f) p[c[v]] -= siz[v]; 
	if(!flag && p[col[fa[u]]] == n - siz[u]) ans = u;
	p[col[u]]++;
	for (auto v : G[u]) 
		if(c[v] != -1 && v != f) p[c[v]] += siz[v]; 
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
	for (int i = 1; i <= n; i++) col[i] = read(), p[col[i]]++;
	dfs(1, 0);
	if(!ans) puts("NO");
	else
	{
		puts("YES");
		cout << ans << endl;
	}
	return 0;
}