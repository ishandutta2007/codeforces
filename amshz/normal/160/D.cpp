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
const int xm = 1e6 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, par[xn], sz[xn];
int H[xn], ans[xn], dp[xn];
ppi E[xn];
vector <int> vec[xm];
vector <pii> adj[xn];
set <int> st;
bool mark[xn];

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
	sz[v] += sz[u];
	par[u] = v;
}
void DFS(int v, int id = - 1){
	mark[v] = true;
	dp[v] = H[v];
	for (pii U : adj[v]){
		int u = U.A, x = U.B;
		if (mark[u]){
			if (x == id)
				continue;
			++ ans[x];
			dp[v] = min(dp[v], H[u]);
			continue;
		}
		merge(v, u);
		H[u] = H[v] + 1;
		DFS(u, x);
		dp[v] = min(dp[v], dp[u]);
	}
	if (id + 1 && dp[v] < H[v])
		++ ans[id];
}

int main(){
	fast_io;

	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		par[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		E[i] = {{v, u}, w};
		vec[w].push_back(i);
	}
	for (int W = 1; W < xm; ++ W){
		st.clear();
		for (int e : vec[W]){
			int v = E[e].A.A, u = E[e].A.B;
			v = get_root(v);
			u = get_root(u);
			if (v == u)
				continue;
			st.insert(v);
			st.insert(u);
			ans[e] = 1;
			adj[v].push_back({u, e});
			adj[u].push_back({v, e});
		}
		for (int v : st)
			mark[v] = false;
		for (int v : st){
			if (mark[v])
				continue;
			H[v] = 0;
			DFS(v);
		}
		for (int v : st)
			adj[v].clear();
	}
	for (int i = 1; i <= m; ++ i){
		if (1 < ans[i])
			cout << "at least one" << endl;
		else if (ans[i])
			cout << "any" << endl;
		else
			cout << "none" << endl;
	}

	return 0;
}