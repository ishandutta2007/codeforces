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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 256;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int n, sz[xn], hvy[xn], rt, par[xn];
int ans[xn];
set <pii> st[2];
vector <int> adj[xn];
vector <pii> bach[xn];

void preDFS(int v){
	sz[v] = 1;
	for (int u : adj[v]){
		preDFS(u);
		bach[v].push_back({sz[u], u});
		sz[v] += sz[u];
		if (sz[hvy[v]] < sz[u])
			hvy[v] = u;
	}
	if (v != rt)
		bach[v].push_back({n - sz[v], v});
	sort(all(bach[v]));
	reverse(all(bach[v]));
	ans[v] = bach[v][0].A;
}
void upd(int v, bool f1, bool f2){
	if (f2)
		st[f1].insert({sz[v], v});
	else
		st[f1].erase({sz[v], v});
	for (int u : adj[v])
		upd(u, f1, f2);
}
void check(int v, int mx, int mn, bool f1, int kam){
	int val = (mx - mn) / 2 + kam;
	pii x = *st[f1].lower_bound({val, 0});
	pii y = *prev(st[f1].lower_bound({val, 0}));
	ans[v] = min(ans[v], max(mn + x.A - kam, mx - x.A + kam));
	ans[v] = min(ans[v], max(mn + y.A - kam, mx - y.A + kam));
}
void DFS1(int v){
	for (int u : adj[v])
		if (u != hvy[v])
			DFS1(u), upd(u, 0, 0);
	if (hvy[v])
		DFS1(hvy[v]);
	if (bach[v][0].B == hvy[v])
		check(v, bach[v][0].A, bach[v].back().A, 0, 0);
	for (int u : adj[v])
		if (u != hvy[v])
			upd(u, 0, 1);
	st[0].insert({sz[v], v});
}
void DFS2(int v){
	st[1].erase({sz[v], v});
	st[0].insert({sz[v], v});
	for (int u : adj[v])
		if (u != hvy[v])
			DFS2(u), upd(u, 1, 1);
	if (hvy[v])
		DFS2(hvy[v]);
	for (int u : adj[v])
		if (u != hvy[v])
			upd(u, 1, 0);
	st[0].erase({sz[v], v});
	if (v == bach[v][0].B){
		check(v, bach[v][0].A, bach[v].back().A, 1, 0);
		check(v, bach[v][0].A, bach[v].back().A, 0, sz[v]);
	}
}

int main(){
	fast_io;

	for (int i = 0; i < 2; ++ i)
		st[i].insert({0, 0}), st[i].insert({inf, 0});
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		int v, u;
		cin >> v >> u;
		if (!v)
			rt = u;
		else{
			par[u] = v;
			adj[v].push_back(u);
		}
	}
	if (n == 1)
		kill(0);
	preDFS(rt);
	DFS1(rt);
	st[0].clear();
	st[0].insert({0, 0});
	st[0].insert({inf, 0});
	for (int i = 1; i <= n; ++ i)
		st[1].insert({sz[i], i});
	DFS2(rt);
	for (int i = 1; i <= n; ++ i)
		if (1 < SZ(bach[i]))
			ans[i] = max(ans[i], bach[i][1].A);
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << endl;

	return 0;
}