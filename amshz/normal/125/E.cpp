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

const int xn = 5e3 + 10;
const int xm = 1e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, k, P[xn], sz[xn];
pii a[xn], mn[xn];
ppp E[xm];
bool in_mst[xm];
vector <pii> adj[xn];

int get_root(int v){
	if (v == P[v])
		return v;
	return P[v] = get_root(P[v]);
}
bool merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return false;
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	P[u] = v;
	return true;
}
void DFS(int v, int p = - 1){
	for (pii u : adj[v]){
		if (u.A == p)
			continue;
		if (1 < v)
			a[u.A] = max(a[v], {E[u.B].A.A, u.B});
		DFS(u.A, v);
	}
}

int main(){
	fast_io;

	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		E[i] = {{w, i}, {v, u}};
	}
	if (n == 1 && k == 0)
		kill(0);
	for (int i = 1; i <= n; ++ i)
		P[i] = i, sz[i] = 1, mn[i].A = inf;
	sort(E + 1, E + m + 1);
	for (int i = 1; i <= m; ++ i){
		int v = E[i].B.A, u = E[i].B.B;
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
	}
	if (!k || !SZ(adj[1]))
		kill(- 1);
	for (int i = 1; i <= m; ++ i)
		if (E[i].B.A != 1 && E[i].B.B != 1 && merge(E[i].B.A, E[i].B.B))
			in_mst[i] = true;
	for (pii x : adj[1])
		mn[get_root(x.A)] = min(mn[get_root(x.A)], {E[x.B].A.A, x.B});
	int ted = 0;
	for (int i = 1; i <= n; ++ i)
		if (mn[i].A < inf)
			in_mst[mn[i].B] = true, merge(1, E[mn[i].B].B.A ^ E[mn[i].B].B.B ^ 1), ++ ted;
	for (int i = 1; i <= n; ++ i)
		if (get_root(i) != get_root(1))
			kill(- 1);
	if (k < ted)
		kill(- 1);
	for (int _ = ted + 1; _ <= k; ++ _){
		for (int i = 1; i <= n; ++ i)
			adj[i].clear(), a[i] = {- 1, 0};
		for (int i = 1; i <= m; ++ i){
			int v = E[i].B.A, u = E[i].B.B;
			if (in_mst[i]){
				adj[v].push_back({u, i});
				adj[u].push_back({v, i});
			}
		}
		DFS(1);
		pip mn = {inf, {- 1, 0}};
		for (int i = 1; i <= m; ++ i){
			int v = E[i].B.A, u = E[i].B.B, w = E[i].A.A;
			if (u < v)
				swap(v, u);
			if (1 < v || in_mst[i])
				continue;
			mn = min(mn, {w - a[u].A, {i, a[u].B}});
		}
		if (mn.A == inf)
			kill(- 1);
		in_mst[mn.B.A] = true;
		in_mst[mn.B.B] = false;
	}
	cout << n - 1 << endl;
	for (int i = 1; i <= m; ++ i)
		if (in_mst[i])
			cout << E[i].A.B << sep;
	cout << endl;

	return 0;
}