#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxb = 20;

vector<int> adj[maxn];

vector<pair<pair<int , int> , int> > ask[maxn];

int par[maxn][maxb] , h[maxn] , st[maxn] , ft[maxn] , now = -1;

int ans[maxn] , n;

void plant(int v , int p = -1)
{
	st[v] = ++now;

	for(auto u : adj[v])
		if(u != p)
		{
			h[u] = h[v] + 1;

			par[u][0] = v;
			for(int i = 1; i < maxb; i++)
				par[u][i] = par[par[u][i - 1]][i - 1];

			h[u] = h[v] + 1;
			plant(u , v);
		}

	ft[v] = now + 1;
}

int go(int v , int h)
{
	for(int i = 0; i < maxb; i++)
		if((h>>i)&1)
			v = par[v][i];

	return v;
}

bool is_par(int v , int u)
{
	return st[v] <= st[u] && st[u] < ft[v];
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

int dist(int v , int u)
{
	return h[v] + h[u] - 2 * h[lca(v , u)];
}

int mx[maxn * 4] , LazyAdd[maxn * 4];

void shift(int s , int e , int v)
{
	if(e - s >= 2 && LazyAdd[v])
	{
		LazyAdd[2 * v] += LazyAdd[v];
		LazyAdd[2 * v + 1] += LazyAdd[v];

		mx[2 * v] += LazyAdd[v];
		mx[2 * v + 1] += LazyAdd[v];
	}

	LazyAdd[v] = 0;
}

void Add(int l , int r , int val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		mx[v] += val;
		LazyAdd[v] += val;
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);

	int m = (s + e) / 2;

	Add(l , r , val , s , m , 2 * v);
	Add(l , r , val , m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

int get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return mx[v];
	if(r <= s || e <= l)
		return 0;

	shift(s , e , v);

	int m = (s + e) / 2;

	return max(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

void dfs(int v , int p = -1)
{
	for(auto ind : ask[v])
		ans[ind.second] = max(ans[ind.second] , get(ind.first.first , ind.first.second , 0 ,  n , 1));

	for(auto u : adj[v])
		if(u != p)
		{
			Add(0 , n , 1 , 0 , n , 1);
			Add(st[u] , ft[u] , -2 , 0 , n , 1);

			dfs(u , v);

			Add(0 , n , -1 , 0 , n , 1);
			Add(st[u] , ft[u] , 2 , 0 , n , 1);
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	plant(0);

	int q;
	cin >> q;

	for(int i = 0; i < q; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		if(h[a] > h[b])
			swap(a , b);

		int c = go(b , dist(a , b) / 2);

		if(is_par(c , a))
			c = go(b , dist(a , b) / 2 - 1);

		ask[b].pb({{st[c] , ft[c]} , i});
		ask[a].pb({{0 , st[c]} , i});
		ask[a].pb({{ft[c] , n} , i});
	}

	for(int i = 0; i < n; i++)
		Add(st[i] , st[i] + 1 , h[i] , 0 , n , 1);

	dfs(0);

	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;
}