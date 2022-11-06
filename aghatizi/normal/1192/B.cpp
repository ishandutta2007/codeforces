#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

struct node
{
	ll val[4][4] , Add;
	node()
	{
		memset(val , 0 , sizeof val);
		Add = 0;
	}
};

node seg[maxn * 4];

int n;

const int zarib[] = {1 , -2 , 1};
int Z[4][4];

vector<int> adj[maxn];

node merge(node a , node b)
{
	node c = a;
	c.Add = 0;
	for(int l = 0; l < 3; l++)
		for(int r = l + 1; r < 4; r++)
			for(int k = l; k < r; k++)
				c.val[l][r] = max(c.val[l][r] , a.val[l][k] + b.val[k][r]);
	return c;
}

void put(int v , ll val)
{
	seg[v].Add += val;
	for(int l = 0; l < 3; l++)
		for(int r = l + 1; r < 4; r++)
			seg[v].val[l][r] += Z[l][r] * val;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && seg[v].Add)
	{
		put(2 * v , seg[v].Add);
		put(2 * v + 1 , seg[v].Add);
	}
	seg[v].Add = 0;
}

void add(int l , int r , ll val , int s = 0 , int e = 2 * n - 1 , int v = 1)
{
	if(l <= s && e <= r)
	{
		put(v , val);
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);
	int m = (s + e) / 2;

	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

int frst[maxn] , last[maxn] , id;

int from[maxn] , to[maxn];
ll w[maxn] , h[maxn];

void dfs(int v , int p = -1)
{
	add(id , id + 1 , h[v]);
	frst[v] = last[v] = id++;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(u != p)
		{
			h[u] = h[v] + w[e];
			dfs(u , v);

			add(id , id + 1 , h[v]);
			last[v] = id++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int l = 0; l < 3; l++)
		for(int r = l + 1; r < 4; r++)
			Z[l][r] = Z[l][r - 1] + zarib[r - 1];

	int q;
	ll W;
	cin >> n >> q >> W;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	dfs(0);

	ll lst = 0;
	while(q--)
	{
		ll e , nw;
		cin >> e >> nw;
		e = (e + lst) % (n - 1);
		nw = (nw + lst) % W;

		int v = from[e] , u = to[e];
		if(h[v] < h[u])
			swap(v , u);

		add(frst[v] , last[v] + 1 , nw - w[e]);
		w[e] = nw;

		lst = seg[1].val[0][3];
		cout << lst << endl;
	}
}