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
const int N = 5009, M = 1e6 + 9, INF = 1e18;
int n, m, s, t, cnt = 1;
int to[M << 1], nxt[M << 1], val[M << 1], head[N];
struct point
{
	int x, y;
}p[N];
double cost[M << 1];
int a[N], ans, vis[N], cur[N];
double dis[N];
inline int pw(int x) {return x * x;}
inline void addedge(int u, int v, int w, double c)
{
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt; cost[cnt] = c, val[cnt] = w;
	to[++cnt] = u, nxt[cnt] = head[v], head[v] = cnt; cost[cnt] = -c, val[cnt] = 0;
}
inline int spfa()
{
	queue<int> q;
	for (int i = 1; i <= t; i++) dis[i] = INF, vis[i] = 0;
	dis[s] = 0, q.push(s); vis[s] = 1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = nxt[i])
			if(val[i] && dis[to[i]] > dis[u] + cost[i])
			{
				dis[to[i]] = dis[u] + cost[i];
				if(!vis[to[i]])
				{
					vis[to[i]] = 1; q.push(to[i]);
				}
			}
	}
	return (dis[t] - INF) < 0.0;
}
double ret;
inline int dfs(int u, int flow)
{
	if(u == t) return flow;
	vis[u] = 1;
	int res = flow, tot = 0;
	for (int i = head[u]; i; i = nxt[i])
	{
		cur[u] = i;
		if(!vis[to[i]] && val[i] && dis[to[i]] == dis[u] + cost[i])
		{
			int pp = dfs(to[i], min(res, val[i]));
			res -= pp, val[i] -= pp, val[(i ^ 1)] += pp, tot += pp;
			ret += 1.0 * pp * cost[i];
		}
	}
	vis[u] = 0;
	return tot;
}
signed main()
{
	n = read(), s = n * 2 + 1, t = n * 2 + 2;
	for (int i = 1; i <= n; i++)
	{
		p[i].x = read(), p[i].y = read();
		addedge(s, i, 2, 0);
		addedge(i + n, t, 1, 0);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(p[i].y > p[j].y)
			{
				addedge(i, j + n, 1, sqrt(pw(p[i].x - p[j].x) + pw(p[i].y - p[j].y)));
			}
	while(spfa()) 
	{
		for (int i = 1; i <= t; i++) vis[i] = 0;
		ans += dfs(s, INF);
	//	cout << ans << endl;
	}
	if(ans == n - 1) printf("%.10lf\n", ret);
	else puts("-1");
	return 0;
}