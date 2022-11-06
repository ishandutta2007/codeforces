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
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9, M = 2e5 + 9, INF = 1e18;
int n, m, s, t;
int head[N], nxt[M], cnt = 1, val[M], to[M], dep[N];
int ans;
int q[N];
struct point
{
	int x, y;
}p[N];
inline void addedge(int u, int v, int w)
{
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt, val[cnt] = w;
	to[++cnt] = u, nxt[cnt] = head[v], head[v] = cnt, val[cnt] = 0;
}
inline int bfs()
{
	for (int i = 1; i <= t; i++) dep[i] = 0;
	dep[s] = 1; 
	int f = 0, e = 1; q[1] = s;
	while(f < e)
	{
		int u = q[++f];
		for (int i = head[u]; i; i = nxt[i])
		{
			int v = to[i];
			if(dep[v] || val[i] == 0) continue;
			dep[v] = dep[u] + 1; q[++e] = v;
		}
	} 
	//for (int i = 1; i <= t; i++) cout << dep[i] << " "; cout << endl;
	if(dep[t]) return 1;
	else return 0;
}
inline int dfs(int u, int flow)
{
	if(u == t) return flow;
	int tot = 0;
	for (int i = head[u]; i && flow; i = nxt[i])
	{
		int v = to[i];
		if(dep[v] != dep[u] + 1 || val[i] == 0) continue;
		int res = dfs(v, min(flow, val[i]));
		val[i] -= res; val[(i ^ 1)] += res; flow -= res; tot += res;
	}
	if(!tot) dep[u] = 0;
	return tot;
}
inline bool check(int x)
{
	int qwq = 0; s = n + m + 1, t = n + m + 2;
	memset(head, 0, sizeof(head)); cnt = 1;
	for (int i = 1; i <= m; i++) 
	{
		addedge(s, i, 1); addedge(i, p[i].x + m, 1); addedge(i, p[i].y + m, 1);
	}
	for (int i = 1; i <= n; i++) addedge(i + m, t, x);
	while(bfs()) 
	{
		qwq += dfs(s, INF); //cout << qwq << endl;
	}
	return (qwq == m);
}
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++) p[i].x = read(), p[i].y = read();
	if(m == 0)
	{
		puts("0"); return 0;
	}
	int l = 1, r = n, ans = 0; 
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	if(!check(ans)) puts("nmsl");
	cout << ans << endl;
	for (int i = 1; i <= m; i++)
		if(val[i * 6] == 0) printf("%lld %lld\n", p[i].y, p[i].x);
		else printf("%lld %lld\n", p[i].x, p[i].y);
	return 0;
}