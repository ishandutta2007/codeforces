//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a[xn], par[xn], sz[xn];
ll res, ans, last;
vector <int> vec[xn], adj[xn];

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	if (sz[v] < sz[u])
		swap(v, u);
	res += 1ll * sz[v] * sz[u];
	sz[v] += sz[u];
	par[u] = v;
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		vec[a[i]].push_back(i);
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i < n; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 1; i < xn; ++ i){
		for (int v : vec[i])
			for (int u : adj[v])
				if (a[u] <= i)
					merge(v, u);
		ans += 1ll * i * (res - last);
		last = res;
	}
	for (int i = 1; i <= n; ++ i)
		par[i] = i, sz[i] = 1;
	for (int i = xn - 1; 1 <= i; -- i){
		for (int v : vec[i])
			for (int u : adj[v])
				if (i <= a[u])
					merge(v, u);
		ans -= 1ll * i * (res - last);
		last = res;
	}
	cout << ans << endl;

	return 0;
}