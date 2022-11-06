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
int n, m, col[N], head[N], nxt[N], to[N], cnt, son[N], siz[N], Mx, sum, Son;
int tot[N], ans[N];
inline void addedge(int u, int v)
{
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt;
}
inline void dfs1(int u, int f)
{
	siz[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if(to[i] != f)
		{
			dfs1(to[i], u);
			siz[u] += siz[to[i]];
			if(siz[son[u]] < siz[to[i]]) son[u] = to[i];
		}
	return ;
}
inline void add(int u, int f, int val)
{
	tot[col[u]] += val;
	if(tot[col[u]] > Mx) Mx = tot[col[u]], sum = col[u];
	else if(tot[col[u]] == Mx) sum += col[u];
	for (int i = head[u]; i; i = nxt[i])
		if(to[i] != f && to[i] != Son)
		{
			add(to[i], u, val);
		}
}
inline void dfs2(int u, int f, int opt)
{
	for (int i = head[u]; i; i = nxt[i])
		if(to[i] != f && to[i] != son[u])
			dfs2(to[i], u, 0);
	if(son[u]) 
	{
		dfs2(son[u], u, 1);
		Son = son[u];
	}
	add(u, f, 1); Son = 0;
	ans[u] = sum;
	if(!opt)
	{
		add(u, f, -1);
		sum = 0, Mx = 0;
	}
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) col[i] = read();
	for (int i = 1; i < n; i++)
	{
		int u = read(), v = read();
		addedge(u, v);
		addedge(v, u);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}