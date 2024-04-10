// khodaya khodet komak kon
# include <bits/stdc++.h>
 
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
typedef pair <ll, ll>                                    pll;
typedef pair <pll,  ll>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
 
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
 
const int xn = 1e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int n, c[xn], cnt[xn], mx, sz[xn];
ll res, ans[xn];
vector <int> adj[xn];

void add(int v, bool f, int p = - 1){
	if (f){
		++ cnt[c[v]];
		if (cnt[c[v]] == mx)
			res += c[v];
		else if (cnt[c[v]] > mx)
			res = c[v], mx = cnt[c[v]];
	}
	else
		-- cnt[c[v]];
	for (int u : adj[v])
		if (u != p)
			add(u, f, v);
}
void DFS2(int v, int p = - 1){
	int arshad = 0;
	for (int u : adj[v])
		if (u != p && sz[u] > sz[arshad])
			arshad = u;
	for (int u : adj[v]){
		if (u == p || u == arshad)
			continue;
		DFS2(u, v), add(u, 0, v);
	}
	res = mx = 0;
	if (arshad)
		DFS2(arshad, v);
	++ cnt[c[v]];
	if (cnt[c[v]] == mx)
		res += c[v];
	else if (cnt[c[v]] > mx)
		res = c[v], mx = cnt[c[v]];
	for (int u : adj[v])
		if (u != p && u != arshad)
			add(u, 1, v);
	ans[v] = res;
}
void DFS(int v, int p = - 1){
	sz[v] = 1;
	for (int u : adj[v])
		if (u != p)
			DFS(u, v), sz[v] += sz[u];
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> c[i];
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1), DFS2(1);
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << sep;
	cout << endl;
			
	return 0;
}