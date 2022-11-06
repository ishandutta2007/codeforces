#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;
const int maxb = 22;
const int inf = 1e9;

vector<int> adj[maxn];

int par[maxn][maxb] , st[maxn] , ft[maxn] , now = -1 , pr[maxn];

int from[maxn * 2] , to[maxn * 2] , w[maxn * 2];

int W[maxn] , shit[maxn][maxb] , h[maxn];

int fn(int v)
{
	return (pr[v] == -1)? v : pr[v] = fn(pr[v]);
}

void plant(int v , int p = -1)
{
	st[v] = ++now;

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(u != p)
		{
			h[u] = h[v] + 1;

			par[u][0] = v;
			for(int i = 1; i < maxb; i++)
				par[u][i] = par[par[u][i - 1]][i - 1];

			W[u] = w[e];
			plant(u , v);
		}
	}

	ft[v] = now;
}

bool is_par(int v , int u)
{
	return st[v] <= st[u] && st[u] <= ft[v];
}

int lca(int v , int u)
{
	for(int i = maxb - 1; i >= 0; i--)
		if(!is_par(par[v][i] , u))
			v = par[v][i];

	if(is_par(v , u))
		return v;
	else
		return par[v][0];
}

void handle(int v , int u , int w)
{
	if(v == u)
		return;

	int H = h[v] - h[u];

	for(int i = 0; i < maxb; i++)
		if((H>>i)&1)
			shit[v][i] = min(shit[v][i] , w) , v = par[v][i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(pr , -1 , sizeof pr);
	memset(shit , 63 , sizeof shit);

	int n , k , m;
	cin >> n >> k >> m;

	for(int i = 0; i < k; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;

		pr[fn(a)] = fn(b);
	}

	for(int i = k; i < m + k; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		a-- , b--;

		from[i] = a , to[i] = b;

		if(fn(a) == fn(b))
			continue;

		adj[a].pb(i);
		adj[b].pb(i);

		pr[fn(a)] = fn(b);
	}

	plant(0);

	for(int i = k; i < m + k; i++)
	{
		int a , b;
		a = from[i] , b = to[i];

		int c = lca(a , b);

		handle(a , c , w[i]);
		handle(b , c , w[i]);
	}

	for(int i = maxb - 1; i > 0; i--)
		for(int v = 0; v < n; v++)
		{
			shit[v][i - 1] = min(shit[v][i - 1] , shit[v][i]);

			int u = par[v][i - 1];
			shit[u][i - 1] = min(shit[u][i - 1] , shit[v][i]);
		}

	ll res = 0;

	for(int i = 1; i < n; i++)
	{
		if(!W[i] && shit[i][0] > inf)
			return cout << -1 << endl , 0;
		if(!W[i])
			res += shit[i][0];
	}

	cout << res << endl;


}