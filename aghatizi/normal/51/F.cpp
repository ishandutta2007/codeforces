#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> adj[maxn];

int h[maxn] , par[maxn] , dp[maxn] , from[maxn] , to[maxn];

bool is[maxn] , visited[maxn] , on[maxn];

int fn(int v)
{
	return (par[v] == -1)? v : par[v] = fn(par[v]);
}

void merge(int v , int u)
{
	v = fn(v);
	u = fn(u);

	if(u != v)
		par[v] = u;
}

void predfs(int v)
{
	visited[v] = 1;
	dp[v] = h[v];

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!visited[u])
		{
			h[u] = h[v] + 1;
			predfs(u);

			if(dp[u] <= h[v])
				merge(v , u);
			else
				is[e] = 1;

			dp[v] = min(dp[v] , dp[u]);
		}
		else if(h[u] < h[v] - 1)
			dp[v] = min(dp[v] , h[u]);
	}
}

pair<int , int> dfs(int v , int p = -1)
{
	pair<int , int> mx = {0 , v};
	visited[v] = 1;

	for(auto u : adj[v])
		if(u != p)
		{
			auto tmp = dfs(u , v);
			tmp.first++;

			mx = max(mx , tmp);
		}

	return mx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(par , -1 , sizeof par);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	int res = -1;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
			predfs(i) , res++;

		adj[i].clear();
	}

	res += n;
	for(int i = 0; i < m; i++)
		if(is[i])
		{
			int v = fn(from[i]) , u = fn(to[i]);

			adj[v].pb(u);
			adj[u].pb(v);
		}

	memset(visited , 0 , sizeof visited);
	memset(h , 0 , sizeof h);

	for(int i = 0; i < n; i++)
		if(par[i] == -1 && !visited[i])
		{
			int v = dfs(i).second;
			auto tmp = dfs(v);

			on[v] = on[tmp.second] = 1;
			res -= tmp.first + 1;
		}

	for(int i = 0; i < n; i++)
		if(visited[i] && !on[i] && (int)adj[i].size() == 1)
			res--;

	cout << res << endl;
}