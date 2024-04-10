#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> adj(n, vector<bool>(n, false));
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u][v] = adj[v][u] = true;
	}
	vector<int> d(n, -1);
	d[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int to = 0; to < n; to++)
		{
			if(d[to] != -1 || adj[0][n - 1] && adj[v][to] || !adj[0][n - 1] && !adj[v][to])
			{
				continue;
			}
			d[to] = d[v] + 1;
			q.push(to);
		}
	}
	cout << d[n - 1];
}