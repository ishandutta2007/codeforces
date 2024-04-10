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
const int N = 2e5 + 9, M = 2e5 + 9, INF = 1e18;
int n, m, s;
int cnt, head[N], nxt[M], to[M], val[M], dis[N], vis[N], p[N], k;
int ans1, ans2;
vector<int> G[N];
inline void addedge(int u, int v, int w)
{
	to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt, val[cnt] = w;
}
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
	for (int i = 1; i <= n; i++) dis[i] = INF;
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
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		int u = read(), v = read();
		G[u].push_back(v);
		addedge(v, u, 1);
	}
	k = read();
	for (int i = 1; i <= k; i++) p[i] = read();
	s = p[k];
	dijkstra();
	for (int i = 1; i < k; i++)
	{
		int flag1 = 0, flag2 = 0;
		for (int j = 0; j < G[p[i]].size(); j++)
		{
			int v = G[p[i]][j];
			if(dis[v] == dis[p[i]] - 1)
			{
				if(v == p[i + 1]) flag1 = 1;
				else flag2 = 1;
			}
		}
		if(flag2) ans2++;
		if(!flag1) ans1++;
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}