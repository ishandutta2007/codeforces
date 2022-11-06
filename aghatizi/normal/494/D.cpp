#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;

vector<int> adj[maxn] , query[maxn];

int from[maxn] , to[maxn] , w[maxn] , n;

int st[maxn] , ft[maxn] , now = -1 , rst[maxn] , h[maxn];

int sum2[maxn * 4] , sum[maxn * 4] , lazy[maxn * 4];

int x[maxn] , y[maxn] , ans[maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

void put(int s , int e , int v , int val)
{
	mkay(val);
	sum2[v] = (sum2[v] + 2LL * val * sum[v] + (1LL * val * val % mod * (e - s))) % mod;
	sum[v] = (sum[v] + 1LL * val * (e - s)) % mod;
	mkay(lazy[v] += val);
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && lazy[v])
	{
		int m = (s + e) / 2;
		put(s , m , 2 * v , lazy[v]);
		put(m , e , 2 * v + 1 , lazy[v]);
	}

	lazy[v] = 0;
}

void add(int l , int r , int val , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
	{
		put(s , e , v , val);
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);

	int m = (s + e) / 2;
	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);

	mkay(sum2[v] = sum2[2 * v] + sum2[2 * v + 1]);
	mkay(sum[v] = sum[2 * v] + sum[2 * v + 1]);
}

int get(int l , int r , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
		return sum2[v];
	if(r <= s || e <= l)
		return 0;

	int m = (s + e) / 2 , ans = 0;
	shift(s , e , v);

	mkay(ans = get(l , r , s , m , 2 * v) + get(l , r , m , e , 2 * v + 1));
	return ans;
}

void plant(int v , int p = -1)
{
	st[v] = ++now;
	rst[st[v]] = v;

	add(st[v] , st[v] + 1 , h[v]);
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(u != p)
		{
			mkay(h[u] = h[v] + w[e]);
			plant(u , v);
		}
	}
	ft[v] = now;
}

void dfs(int v , int p = -1)
{
	for(auto ind : query[v])
	{
		int u = y[ind];
		ans[ind] = 2LL * get(st[u] , ft[u] + 1) % mod;
		mkay(ans[ind] -= sum2[1]);
	}

	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(u != p)
		{
			add(st[u] , ft[u] + 1 , -w[e]);
			add(0 , st[u] , w[e]);
			add(ft[u] + 1 , n , w[e]);

			dfs(u , v);

			add(st[u] , ft[u] + 1 , w[e]);
			add(0 , st[u] , -w[e]);
			add(ft[u] + 1 , n , -w[e]);
		}
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
		cin >> a >> b >> w[i];
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);
		
		from[i] = a , to[i] = b;
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; i++)
		cin >> x[i] >> y[i] , x[i]-- , y[i]-- , query[x[i]].pb(i);

	plant(0);
	dfs(0);

	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;
}