// khodaya khodet komak kon
// Nightcall - London Grammer
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
 
const int xn = 4e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, q, a[xn], par[xn], sz[xn], ptr, pt, W;
int P[xm][xn], mxedge[xm][xn], H[xn], c[xn];
pii b[xn], f[xn], ans[xn];
vector <ppp> E;
vector <int> compress;
vector <pii> adj[xn], query[xn];
unordered_map <int, int> mp;
 
void DFS(int v){
	for (int i = 1; i < xm; ++ i){
		P[i][v] = P[i - 1][P[i - 1][v]];
		mxedge[i][v] = max(mxedge[i - 1][v], mxedge[i - 1][P[i - 1][v]]);
	}
	for (pii u : adj[v]){
		if (u.A == P[0][v])
			continue;
		H[u.A] = H[v] + 1;
		P[0][u.A] = v;
		mxedge[0][u.A] = u.B;
		DFS(u.A);
	}
}
int LCA(int v, int u){
	if (H[v] > H[u])
		swap(v, u);
	int res = 0;
	for (int i = xm - 1; i >= 0; -- i){
		if ((1 << i) > H[u] - H[v])
			continue;
		res = max(res, mxedge[i][u]);
		u = P[i][u];
	}
	if (v == u)
		return res;
	for (int i = xm - 1; i >= 0; -- i){
		if (P[i][v] == P[i][u])
			continue;
		res = max(res, mxedge[i][v]);
		res = max(res, mxedge[i][u]);
		v = P[i][v], u = P[i][u];
	}
	return max({res, mxedge[0][v], mxedge[0][u]});
}
void buildDSU(){
	for (int i = 1; i <= n; ++ i){
		par[i] = i;
		sz[i] = 1;
		f[i] = {a[i], i};
	}
}
int get_root(int v){
	if (par[v] == v)
		return v;
	return par[v] = get_root(par[v]);
}
int get(int v){
	return LCA(v, f[get_root(v)].B);
}
void merge(int v, int u, int w){
	int pv = v, pu = u;
	v = get_root(v);
	u = get_root(u);
	if (sz[v] < sz[u])
		swap(v, u), swap(pv, pu);
	if (f[v].A == f[u].A)
		c[v] = max({c[v], c[u], get(pv), get(pu), w});
	else if (f[v].A < f[u].A)
		f[v] = f[u], c[v] = c[u];
	par[u] = v, sz[v] += sz[u];
}
 
int main(){
	InTheNameOfGod;
 
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 0; i < n - 1; ++ i){
		int v, u, x, y;
		cin >> v >> u >> x >> y;
		E.push_back({{x, y}, {v, u}});
		compress.push_back(x);
	}
	for (int i = 0; i < q; ++ i){
		int x, v;
		cin >> x >> v;
		b[i] = {v, x};
		compress.push_back(x);
	}
	sort(all(compress));
	for (int i = 0; i < SZ(compress); ++ i)
		if (!i || compress[i] != compress[i - 1])
			mp[compress[i]] = ptr ++;
	for (int i = 0; i < n - 1; ++ i){
		E[i].A.A = mp[E[i].A.A];
		int v = E[i].B.A, u = E[i].B.B, w = E[i].A.B;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
	}
	for (int i = 0; i < q; ++ i){
		int v = b[i].A, x = b[i].B;
		query[mp[x]].push_back({v, i});
	}
	sort(all(E)), reverse(all(E));
	DFS(1), buildDSU();
	for (W = ptr - 1; W >= 0; -- W){
		while (pt < SZ(E) && E[pt].A.A == W)
			merge(E[pt].B.A, E[pt].B.B, E[pt].A.B), ++ pt;
		for (pii x : query[W])
			ans[x.B] = {f[get_root(x.A)].A, max(get(x.A), c[get_root(x.A)])};
	}
	for (int i = 0; i < q; ++ i)
		cout << ans[i].A << sep << ans[i].B << endl;
 
	return 0;
}