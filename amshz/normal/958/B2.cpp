//khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize("O2")
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
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
# define lc                                              id << 1
# define rc                                              lc | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = 20 + 10;
const int sq = 320;
const ll inf = 1e18 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, par[xm][xn], H[xn], a[xn], S, d[xn], res;
int ans[xn], c[xn], tot;
set <pii> st, leaf;
vector <int> adj[xn];

void DFS(int v){
	a[v] = S ++;
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		par[0][u] = v;
		H[u] = H[v] + 1;
		DFS(u);
	}
}
int LCA(int v, int u){
	if (H[v] > H[u])
		swap(v, u);
	for (int i = xm - 1; i >= 0; -- i)
		if ((1 << i) <= H[u] - H[v])
			u = par[i][u];
	if (v == u)
		return v;
	for (int i = xm - 1; i >= 0; -- i)
		if (par[i][v] != par[i][u])
			v = par[i][v], u = par[i][u];
	return par[0][v];
}
int dist(int v, int u){ return H[v] + H[u] - 2 * H[LCA(v, u)];}
void modify(int v){
	int x = prev(leaf.end()) -> B, y = leaf.begin() -> B;
	if (leaf.find({a[v], v}) != leaf.begin())
		x = prev(leaf.find({a[v], v})) -> B;
	if (leaf.find({a[v], v}) != prev(leaf.end()))
		y = leaf.lower_bound({a[v], v + 1}) -> B;
	st.erase({c[v], v});
	c[v] = dist(v, x) + dist(v, y) - dist(x, y);
	st.insert({c[v], v});
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		++ d[v], ++ d[u];
		res += 2;
	}
	DFS(1);
	for (int i = 1; i < xm; ++ i)
		for (int v = 1; v <= n; ++ v)
			par[i][v] = par[i - 1][par[i - 1][v]];
	for (int i = 1; i <= n; ++ i)
		if (d[i] < 2)
			leaf.insert({a[i], i});
	for (int i = 1; i <= n; ++ i)
		if (d[i] < 2)
			modify(i), ++ tot;
	for (int i = tot; i <= n; ++ i)
		ans[i] = n;
	for (int i = tot - 1; i >= 1; -- i){
		int v = st.begin() -> B;
		st.erase(st.begin());
		res -= c[v], ans[i] = res / 2 + 1;
		int x = prev(leaf.end()) -> B, y = leaf.begin() -> B;
		if (leaf.find({a[v], v}) != leaf.begin())
			x = prev(leaf.find({a[v], v})) -> B;
		if (leaf.find({a[v], v}) != prev(leaf.end()))
			y = leaf.lower_bound({a[v], v + 1}) -> B;
		leaf.erase({a[v], v});
		modify(x), modify(y);
	}
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}