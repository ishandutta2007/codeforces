#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 15e4 + 20;
const int mod = 998244353;
const int sq = 320;
const int maxb = 19;

vector<int> adj[maxn];

int st[maxn] , ft[maxn] , now = -1 , par[maxn][maxb] , h[maxn] , sz[maxn] , lb[maxn];

int sum[maxn] , res[maxn] , n;

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

void plant(int v , int p = -1)
{
	st[v] = ++now;
	sz[v] = 1;

	for(auto u : adj[v])
		if(u != p)
		{
			par[u][0] = v;
			for(int i = 1; i < maxb; i++)
				par[u][i] = par[par[u][i - 1]][i - 1];

			h[u] = h[v] + 1;
			plant(u , v);
			sz[v] += sz[u];
		}

	ft[v] = now;
}

bool is_par(int a , int b)
{
	return st[a] <= st[b] && st[b] <= ft[a];
}

int get(int v , int h)
{
	if(!h)
		return v;

	while(h)
		v = par[v][lb[h]] , h ^= (1 << lb[h]);

	return v;
}

int shit[maxn];

void build(vector<pair<int , int> > query)
{
	if(query.empty())
		return;
	for(auto tmp : query)
	{
		int v = tmp.first , d = tmp.second;
		mkay(shit[v] += d);
	}

	for(int v = 0; v < n; v++)
	{
		int d = shit[v];
		shit[v] = 0;
		if(!d)
			continue;
		for(auto u : adj[v])
			if(u != par[v][0])
			{
				int val = 1LL * d * (n - sz[u]) % mod;
				mkay(sum[st[u]] += val);
				mkay(sum[ft[u] + 1] -= val);
			}

		int val = 1LL * d * sz[v] % mod;
		mkay(sum[0] += val);
		mkay(sum[st[v]] -= val);
		mkay(sum[ft[v] + 1] += val);
		mkay(res[st[v]] += 1LL * n * d % mod);
	}

	for(int i = 1; i < n; i++)
		mkay(sum[i] += sum[i - 1]);
	for(int i = 0; i < n; i++)
	{
		mkay(res[i] += sum[i]);
		sum[i] = 0;
	}
}

int main()
{
	for(int i = 1; i < maxn; i++)
	{
		if(i & 1)
			lb[i] = 0;
		else
			lb[i] = lb[i / 2] + 1;
	}

	int q;
	scanf("%d%d", &n, &q);

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	plant(0);

	vector<pair<int , int> > query;
	int invn = bpw(n , mod - 2);
	for(int _ = 0; _ < q; _++)
	{
		if(_ % sq == 0)
		{
			build(query);
			query.clear();
		}

		int type;
		scanf("%d", &type);
		
		if(type == 1)
		{
			int v , d;
			scanf("%d%d", &v, &d);
			v--;
			if(!d)
				continue;

			query.pb({v , d});
		}
		if(type == 2)
		{
			int u;
			scanf("%d", &u);
			u--;
			
			int ans = res[st[u]];
			for(auto tmp : query)
			{
				int v = tmp.first , d = tmp.second;
				if(v == u)
				{
					mkay(ans += 1LL * n * d % mod);
					continue;
				}

				if(is_par(v , u))
				{
					int c = get(u , h[u] - h[v] - 1);
					ans = (ans + 1LL * (n - sz[c]) * d) % mod;
				}
				else
					ans = (ans + 1LL * sz[v] * d) % mod;
			}

			ans = 1LL * ans * invn % mod;
			printf("%d\n", ans);
		}
	}
}