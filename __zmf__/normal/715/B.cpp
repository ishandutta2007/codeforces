/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define mid ((l + r) >> 1)
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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 2e5 + 9, M = 4e5 + 9, INF = 1e15;
int n, m, s, t, l;
int cnt, head[N], nxt[M], to[M], val[M], dis[N], vis[N];
vector<int> G[N];
inline void addedge(int u, int v, int w)
{
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt, val[cnt] = w;
	to[++cnt] = u, nxt[cnt] = head[v], head[v] = cnt, val[cnt] = w;
}
struct point
{
	int u, v, w;
}p[M];
struct node
{
	int pos, dis;
	bool operator < (const node &x) const
	{
		return x.dis < dis;
	}
};
priority_queue<node> q;
inline void dijkstra()
{
	for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = 0;
	dis[s] = 0;
	q.push((node){s, 0});
	while(!q.empty())
	{
		int u = q.top().pos;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = nxt[i])
			if(dis[to[i]] > dis[u] + val[i])
			{
				dis[to[i]] = dis[u] + val[i];
				if(!vis[to[i]]) q.push((node){to[i], dis[to[i]]});
			}
	}
}
signed main()
{
	n = read(), m = read(), l = read(), s = read() + 1, t = read() + 1;
	for (int i = 1; i <= m; i++)
	{
		p[i].u = read() + 1, p[i].v = read() + 1, p[i].w = read();
		if(p[i].w != 0) addedge(p[i].u, p[i].v, p[i].w);
	}
	dijkstra();
//	cout << dis[t] << endl;
	if(dis[t] < l)
	{
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= m; i++)
		if(p[i].w == 0)
		{
			addedge(p[i].u, p[i].v, 1);
			dijkstra();
			if(dis[t] <= l)
			{
				puts("YES");
				for (int j = 1; j <= m; j++) 
					if(p[j].w == 0)
					{
						if(j < i) printf("%lld %lld %lld\n", p[j].u - 1, p[j].v - 1, 1ll);
						if(j == i) printf("%lld %lld %lld\n", p[j].u - 1, p[j].v - 1, l - dis[t] + 1);
						if(j > i) printf("%lld %lld %lld\n", p[j].u - 1, p[j].v - 1, INF);
					}
					else printf("%lld %lld %lld\n", p[j].u - 1, p[j].v - 1, p[j].w);
				return 0;
			}
		}
	if(dis[t] == l)
	{
		puts("YES");
		for (int i = 1; i <= m; i++) printf("%lld %lld %lld\n", p[i].u - 1, p[i].v - 1, p[i].w);
		return 0;
	}
	puts("NO");
	return 0;
}