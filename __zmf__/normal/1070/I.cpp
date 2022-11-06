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
const int N = 1e4 + 9, M = 1e6 + 9;
int n, m, s, t;
int val[M << 1], cnt = 1, head[N], nxt[M << 1], to[M << 1], ans;
int dep[N], q[N], f, e, deg[N];
inline void addedge(int u, int v, int w)
{
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt, val[cnt] = w;
	to[++cnt] = u, nxt[cnt] = head[v], head[v] = cnt, val[cnt] = 0;
}
inline bool bfs()
{
	for (int i = 1; i <= t; i++) dep[i] = 0;
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
	for (int i = head[u]; i && flow; i = nxt[i]) 
		if(dep[to[i]] == dep[u] + 1 && val[i])
		{
			int res = dfs(to[i], min(flow, val[i]));
			val[i] -= res;
			val[(i ^ 1)] += res;
			flow -= res;
			tot += res;
		}
	if(!tot) dep[u] = 0;
	return tot;
}
int x[M], y[M], k;
int col[N];
vector<int> G[N];
inline void work()
{
	memset(head, 0, sizeof(head)); cnt = 1;
	n = read(), m = read(), k = read(); ans = 0;
	int qwqaq = 0;
	s = n + m + 1, t = n + m + 2;
	for (int i = 1; i <= n; i++) deg[i] = 0, G[i].clear();
	for (int i = 1; i <= m; i++)
	{
		x[i] = read(), y[i] = read(); deg[x[i]]++, deg[y[i]]++;
		addedge(s, i, 1); addedge(i, m + x[i], 1); addedge(i, m + y[i], 1);
	}
	for (int i = 1; i <= n; i++)
	{
		if(deg[i] > k * 2) 
		{
			for (int j = 1; j <= m; j++) printf("0 "); puts("");
			return ;
		} 
		int now = max(0ll, (deg[i] - k) * 2);
		addedge(m + i, t, now); qwqaq += now;
	}
	while(bfs()) ans += dfs(s, 1e18);
	if(qwqaq != ans)
	{
		for (int i = 1; i <= m; i++) printf("0 "); puts("");
		return ;
	}
	for (int i = 1; i <= m; i++)
	{
		if(val[i * 6 - 2] == 0) G[to[i * 6 - 2] - m].push_back(i);
		else if(val[i * 6] == 0) G[to[i * 6] - m].push_back(i);
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++) col[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < G[i].size(); j += 2)
			col[G[i][j]] = col[G[i][j + 1]] = ++cnt;
	for (int i = 1; i <= m; i++)
		if(!col[i]) col[i] = ++cnt;
	for (int i = 1; i <= m; i++) printf("%lld ", col[i]); puts("");
	return ;
}
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++)
		work();
}