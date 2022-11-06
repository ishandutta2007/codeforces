#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
int mod;

int k , x;

vector<int> adj[maxn];

bool hide[maxn];

int up[maxn] , down[maxn] , pw[maxn] , last[maxn] , arr[maxn] , id , val[maxn] , sz[maxn] , h[maxn];

int outb[maxn] , inb[maxn] , outw[maxn] , inw[maxn] , mp[maxn] , pm[maxn];

int req[maxn] , ind[maxn] , rpw[maxn];

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
	sz[v] = 1;
	for(auto u : adj[v])
		if(!hide[u] && u != p)
		{
			plant(u , v);
			sz[v] += sz[u];
		}
}

inline int GetCentroid(int v , int n , int p = -1)
{
	while(1)
	{
		bool f = 1;
		for(auto u : adj[v])
			if(!hide[u] && u != p && sz[u] * 2 > n)
			{
				p = v;
				v = u;
				f = 0;
				break;
			}

		if(f)
			return v;
	}
}

void dfs(int v , int p = -1)
{
	if(p == -1)
		down[v] = val[v] , up[v] = 0 , h[v] = 0;
	sz[v] = 1;

	for(auto u : adj[v])
		if(!hide[u] && u != p)
		{
			h[u] = h[v] + 1;
			up[u] = (1LL * up[v] * k + val[u]) % mod;
			down[u] = (1LL * val[u] * pw[h[u]] + down[v]) % mod;

			dfs(u , v);
			sz[v] += sz[u];
		}

	arr[id++] = v;
}

vector<int> cmp;

void solve(int v)
{
	plant(v);
	v = GetCentroid(v , sz[v]);

	id = 0;
	dfs(v);
	sz[v] = 1;
	adj[v].pb(v);

	cmp.clear();
	for(int i = 0; i < id; i++)
		cmp.pb(down[arr[i]]);
	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	for(int i = 0; i < id; i++)
	{
		int w = arr[i];
		int k = 1LL * (x - up[w] + mod) * rpw[h[w]] % mod;

		req[w] = lower_bound(cmp.begin() , cmp.end() , k) - cmp.begin();
		if(k != cmp[req[w]])
			req[w] = cmp.size();

		down[w] = lower_bound(cmp.begin() , cmp.end() , down[w]) - cmp.begin();
	}

	for(int _ = 0; _ < 2; _++)
	{
		reverse(arr , arr + id);
		reverse(adj[v].begin() , adj[v].end());
		fill(mp , mp + (int)cmp.size() + 2 , 0);
		fill(pm , pm + (int)cmp.size() + 2 , 0);

		int st = 0;
		for(auto u : adj[v])
			if(!hide[u])
			{
				for(int i = st; i < st + sz[u]; i++)
				{
					int w = arr[i];

					outb[w] += mp[req[w]];
					inb[w] += pm[down[w]];
				}

				for(int i = st; i < st + sz[u]; i++)
				{
					int w = arr[i];

					pm[req[w]]++;
					mp[down[w]]++;
				}

				st += sz[u];
			}
	}
	hide[v] = 1;

	for(auto u : adj[v])
		if(!hide[u])
			solve(u);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cmp.reserve(1 << 20);

	int n;
	cin >> n >> mod >> k >> x;

	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = 1LL * pw[i - 1] * k % mod;

	rpw[maxn - 1] = bpw(pw[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i > 0; i--)
		rpw[i - 1] = 1LL * rpw[i] * k % mod;

	for(int i = 0; i < n; i++)
		cin >> val[i];

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	solve(0);

	ll res = 0;
	for(int i = 0; i < n; i++)
	{
		if(val[i] == x)
			outb[i]++ , inb[i]++;
		outw[i] = n - outb[i] , inw[i] = n - inb[i];
		res -= (2LL * inw[i] * inb[i]) + (1LL * inw[i] * outb[i]) + (1LL * outw[i] * inb[i]) + (2LL * outw[i] * outb[i]);
	}

	res /= 2;
	res += 1LL * n * n * n;
	cout << res << endl;
}