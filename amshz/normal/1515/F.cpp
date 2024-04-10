// khodaya khodet komak kon
// Toxicity
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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, m, k, a[xn], par[xn], sz[xn], sum;
set <pii> adj[xn];
bool mark[xn];
set <pll> st;

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}

int main(){
	//InTheNameOfGod;

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], st.insert({- a[i], i}), sum += a[i];
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].insert({u, i});
		adj[u].insert({v, i});
	}
	if (sum < k * (n - 1))
		kill("NO");
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++ i)
		par[i] = i, sz[i] = 1;
	while (SZ(st)){
		int v = st.begin() -> B;
		st.erase(st.begin());
		if (!SZ(st))
			break;
		int u = adj[v].begin() -> A;
		int id = adj[v].begin() -> B;
		st.erase({- a[u], u});
		adj[v].erase(adj[v].begin());
		adj[u].erase({v, id});
		if (sz[v] < sz[u])
			swap(v, u);
		sz[v] += sz[u];
		for (pll x : adj[u]){
			int uu = x.A, idd = x.B;
			adj[uu].erase({u, idd});
			if (adj[uu].lower_bound({v, 0}) == adj[uu].end() || adj[uu].lower_bound({v, 0}) -> A != v)
				adj[uu].insert({v, idd});
			if (adj[v].lower_bound({uu, 0}) == adj[v].end() || adj[v].lower_bound({uu, 0}) -> A != uu)
				adj[v].insert(x);
		}
		cout << id << endl;
		a[v] += a[u] - k;
		st.insert({- a[v], v});
	}
	
	return 0;
}