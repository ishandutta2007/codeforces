#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int n, m, xd[N], dx[N];

short int c[N][N];
vector<int> adj[N];
int dist[N];
bool bfs(int s, int t)
{
	for (int i = 0; i <= n + m + 1; ++ i) dist[i] = 1e9;
	dist[s] = 0;
	queue<int> Q; Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (auto v: adj[u]) if (c[u][v] > 0 && dist[v] == 1e9)
		{
			dist[v] = dist[u] + 1;
			Q.push(v);
		}
	}
	return dist[t] != 1e9;
}
int beg[N];
int dfs(int v, short int max_cap, int t)
{
	if (v == t || max_cap == 0) return max_cap;
	int res = 0;
	for (int &i = beg[v]; i < (int) adj[v].size(); ++ i)
	{
		int u = adj[v][i];
		if (c[v][u] > 0 && dist[u] == dist[v] + 1)
		{
			int x = dfs(u, min(max_cap, c[v][u]), t);
			c[v][u] -= x; c[u][v] += x;
			res += x; max_cap -= x;
		}
	}
	return res;
}
int maxflow(int s, int t)
{
	int res = 0;
	while (bfs(s,t))
	{
		for (int i = 0; i <= n + m + 1; ++ i) beg[i] = 0;
		res += dfs(s, 5000, t);
	}
	return res;
}

bool ok(int t)
{
	for (int i = 1; i <= n; ++ i)
	{
		c[0][i] = 0;
		c[i][0] = 0;
	}
	for (int i = 0; i < m; ++ i)
	{
		c[xd[i]][n+i+1] = 0;
		c[n+i+1][xd[i]] = 0;
		
		c[dx[i]][n+i+1] = 0;
		c[n+i+1][dx[i]] = 0;
		
		c[n+i+1][n+m+1] = 0;
		c[n+m+1][n+i+1] = 0;
	}	

	for (int i = 1; i <= n; ++ i)
	{
		c[0][i] = t;
	}
	for (int i = 0; i < m; ++ i)
	{
		c[xd[i]][n+i+1] += 1;		
		c[dx[i]][n+i+1] += 1;
		
		c[n+i+1][n+m+1] = 1;
	}	

	if (maxflow(0, n+m+1) == m)
		return true;
	else
		return false;
}
int bs(int p, int k)
{
	if (p == k) return p;
	int s = (p + k) / 2;
	if (ok(s))
		return bs(p, s);
	else
		return bs(s+1, k);
}

int main()
{
	scanf("%d%d", &n, &m);	
	for (int i = 0; i < m; ++ i) 
		scanf("%d%d", &xd[i], &dx[i]);
	
	for (int i = 1; i <= n; ++ i)
	{
		adj[0].push_back(i);
		adj[i].push_back(0);
	}
	for (int i = 0; i < m; ++ i)
	{
		adj[xd[i]].push_back(n+i+1);
		adj[n+i+1].push_back(xd[i]);
		
		adj[dx[i]].push_back(n+i+1);
		adj[n+i+1].push_back(dx[i]);
		
		adj[n+i+1].push_back(n+m+1);
		adj[n+m+1].push_back(n+i+1);
	}	
	for (int i = 0; i < n+m+1; ++ i)
	{
		sort(adj[i].begin(), adj[i].end());
		adj[i].resize(distance(adj[i].begin(), unique(adj[i].begin(), adj[i].end())));
	}

	int res = bs(0,n);
	printf("%d\n", res); 
	
	ok(res);
	for (int i = 0; i < m; ++ i)
	{
		if (c[xd[i]][n+i+1] == 0)
			printf("%d %d\n", xd[i], dx[i]);
		else
			printf("%d %d\n", dx[i], xd[i]);
	}	
	
	return 0;
}