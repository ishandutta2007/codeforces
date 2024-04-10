#include <iostream>
#include <vector>

#define INF 10000000000000

struct edge
{
	int v;
	long long l;
};

int N;
long long w[300001];
std::vector<edge> Adj[300001];
long long dp1[300001];
long long dp2[300001];

void dfs(int u, int p)
{
	dp1[u] = w[u]; dp2[u] = w[u];
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int v = Adj[u][i].v;
		if(v == p)
			continue;
		dfs(v, u);
		long long l = Adj[u][i].l;
		dp2[u] = std::max(dp2[v] - l + w[u], dp2[u]);
		dp1[u] = std::max(dp1[u], dp1[v]);
	}
	
	long long max = -INF;
	long long smax = -INF;
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int v = Adj[u][i].v;
		if(v == p)
			continue;
		int l = Adj[u][i].l;
		if(dp2[v] - l >= max)
		{
			smax = max;
			max = dp2[v] - l;
		}
		else if(dp2[v] - l >= smax)
			smax = dp2[v] - l;
	}
	dp1[u] = std::max(dp1[u], smax + max + w[u]);
	dp1[u] = std::max(dp1[u], dp2[u]);
}

int main()
{
	std::cin >> N;
	
	for(int i = 0; i < N; i++)
		std::cin >> w[i];
		
	for(int i = 0; i < N-1; i++)
	{
		int u, v;
		long long l;
		std::cin >> u >> v >> l; u--; v--;
		Adj[u].push_back({v, l});
		Adj[v].push_back({u, l});
	}
	
	dfs(0, -1);
	std::cout << dp1[0];
	
	return 0;
}