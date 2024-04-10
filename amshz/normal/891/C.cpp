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

const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, q, par[xn], sz[xn], ted;
ppi E[xn];
vector <int> vec[xn];
vector <pii> adj[xn];
bool flag, mark[xn];
set <int> st, ts;

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
	for (pii u : adj[v]){
		if (u.B == id)
			continue;
		flag |= mark[u.A];
		if (!mark[u.A])
			DFS(u.A, u.B);
	}
}

int main(){
	fast_io;

	cin >> n >> m;
	for (int i = 1; i <= m; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		E[i] = {{v, u}, w};
		vec[w].push_back(i);
	}
	for (int i = 1; i <= n; ++ i)
		par[i] = i, sz[i] = 1;
	for (int W = 1; W < xn; ++ W){
		for (int id : vec[W]){
			E[id].A.A = get_root(E[id].A.A);
			E[id].A.B = get_root(E[id].A.B);
		}
		for (int id : vec[W])
			merge(E[id].A.A, E[id].A.B);
		vec[W].clear();
	}
	cin >> q;
	while (q --){
		cin >> ted;
		st.clear(), flag = false;
		for (int i = 0; i < ted; ++ i){
			int x;
			cin >> x;
			st.insert(E[x].B);
			vec[E[x].B].push_back(x);
		}
		for (int W : st){
			ts.clear();
			for (int id : vec[W]){
				int v = E[id].A.A, u = E[id].A.B;
				ts.insert(v);
				ts.insert(u);
				adj[v].push_back({u, id});
				adj[u].push_back({v, id});
			}
			vec[W].clear();
			for (int v : ts)
				mark[v] = false;
			for (int v : ts)
				if (!mark[v])
					DFS(v);
			for (int v : ts)
				adj[v].clear();
		}
		if (flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}