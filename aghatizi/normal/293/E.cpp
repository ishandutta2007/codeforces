#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))
#define ws JeddanCheraWsReEstefadeKardan

const int maxn = 1e5 + 20;

vector<int> adj[maxn];

bool picked[maxn];

int l , W , from[maxn] , to[maxn] , sz[maxn] , h[maxn] , ws[maxn] , w[maxn];

void plant(int v , int p = -1)
{
	sz[v] = 1;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!picked[u] && u != p)
		{
			ws[u] = ws[v] + w[e];
			h[u] = h[v] + 1;
			plant(u , v);
			sz[v] += sz[u];
		}
	}
}

int find_centroid(int v , int n , int p = -1)
{
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!picked[u] && u != p && sz[u] * 2 > n)
			return find_centroid(u , n , v);
	}

	return v;
}

void dfs(int v , vector<pair<int , int> > &tmp , int p = -1)
{
	tmp.pb(make_pair(ws[v] , h[v]));
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!picked[u] && u != p)
			dfs(u , tmp , v);
	}
}

vector<int> query[maxn];

int fen[maxn];

void add(int p , int val)
{
	for(p += 5; p < maxn; p += lb(p))
		fen[p] += val;
}

int get(int p)
{
	int res = 0;
	for(p += 5; p > 0; p -= lb(p))
		res += fen[p];

	return res;
}

ll get(vector<pair<int , int> > &x)
{
	sort(x.begin() , x.end());

	int n = x.size();
	for(int i = 0; i < n; i++)
		query[i].clear();

	assert(x.back().second <= n);

	for(int i = 0; i < n; i++)
	{
		int k = lower_bound(x.begin() , x.end() , make_pair(W - x[i].first , l + 5)) - x.begin() - 1;
		k = min(k , i - 1);

		if(k >= 0)
			query[k].pb(l - x[i].second);
	}

	ll res = 0;
	for(int i = 0; i < n; i++)
	{
		add(x[i].second , 1);
		for(auto x : query[i])
			res += get(x);
	}

	for(int i = 0; i < n; i++)
		add(x[i].second , -1);

	return res;
}

ll res;

void solve(int v)
{
	plant(v);
	int n = sz[v];
	v = find_centroid(v , n);

	h[v] = ws[v] = 0;
	plant(v);

	vector<pair<int , int> > tmp;
	dfs(v , tmp);
	picked[v] = 1;

	res += get(tmp);
	tmp.clear();

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		vector<pair<int , int> > nw;
		if(!picked[u])
		{
			dfs(u , nw);
			res -= get(nw);
		}
	}

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;

		if(!picked[u])
			solve(u);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> l >> W;

	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p >> w[i];
		p--;

		adj[p].pb(i);
		adj[i].pb(i);

		from[i] = i , to[i] = p;
	}

	solve(0);

	cout << res << endl;
}