/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
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
const int N = 2e5 + 9, M = 2e5 + 9;
int n, m, s, t, g;
int val[M << 1], cnt = 1, head[N], nxt[M << 1], to[M << 1], ans, cur[N];
int a[N], dep[N], q[N], f, e;
inline void addedge(int u, int v, int w)
{
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt, val[cnt] = w;
	to[++cnt] = u, nxt[cnt] = head[v], head[v] = cnt, val[cnt] = 0;
}
inline bool bfs()
{
	for (int i = s; i <= t; i++) dep[i] = 0;
	f = 0, e = 1; q[1] = s; dep[s] = 1;
	while(f < e)
	{
		f++;
		int u = q[f];
		for (int i = head[u]; i; i = nxt[i])
			if(!dep[to[i]] && val[i])
			{ 
				q[++e] = to[i];
				dep[to[i]] = dep[u] + 1;
			}
	}
	if(dep[t]) return 1;
	return 0;
}
inline int dfs(int u, int flow)
{
	int tot = 0;
	if(u == t) return flow;
	for (int i = cur[u]; i && flow; i = nxt[i]) 
	{
		cur[u] = i;
		if(dep[to[i]] == dep[u] + 1 && val[i])
		{
			int res = dfs(to[i], min(flow, val[i]));
			val[i] -= res;
			val[(i ^ 1)] += res;
			flow -= res;
			tot += res;
		}
	}
	if(!tot) dep[u] = 0;
	return tot;
}
signed main()
{
	n = read(), m = read(), g = read(), s = 0, t = n + m + 1;
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		if(a[i]) addedge(i, t, x);
		else addedge(s, i, x);
	} 
	for (int i = 1; i <= m; i++)
	{
		int p = read(), w = read(), k = read();
		ans += w;
		for (int j = 1; j <= k; j++)
		{
			int x = read();
			if(!p) addedge(n + i, x, 1e9);
			else addedge(x, n + i, 1e9);
		}
		int v = read();
		if(v) w += g;
		if(!p) addedge(s, n + i, w);
		else addedge(n + i, t, w);
	}
	while(bfs()) 
	{
		for (int i = s; i <= t; i++) cur[i] = head[i];
		ans -= dfs(s, 1e9);
	}
	cout << ans << endl;
	return 0;
}