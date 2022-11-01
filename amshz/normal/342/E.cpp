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

int n, sz[xn], H[xn], m, f[xn], ans;
vector <int> adj[xn];
vector <pii> vec[xn];
bool hide[xn];

void plant(int v, int root, int par){
	sz[v] = 1;
	if (root)
		vec[v].push_back({root, H[v]});
	for (int u : adj[v]){
		if (hide[u] || u == par)
			continue;
		H[u] = H[v] + 1;
		plant(u, root, v);
		sz[v] += sz[u];
	}
}
int find_centroid(int v, int s, int par = - 1){
	for (int u : adj[v])
		if (!hide[u] && u != par && sz[u] + sz[u] > s)
			return find_centroid(u, s, v);
	return v;
}
void solve(int v, int h = 0){
	plant(v, 0, - 1);
	v = find_centroid(v, sz[v]);
	H[v] = 0, plant(v, v, - 1);
	hide[v] = true;
	f[v] = inf;
	for (int u : adj[v])
		if (!hide[u])
			solve(u, h + 1);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	solve(1);
	for (pii x : vec[1])
		f[x.A] = min(f[x.A], x.B);
	while (m --){
		int t, v;
		cin >> t >> v;
		if (t == 1)
			for (pii x : vec[v])
				f[x.A] = min(f[x.A], x.B);
		else{
			ans = inf;
			for (pii x : vec[v])
				ans = min(ans, f[x.A] + x.B);
			cout << ans << endl;
		}
	}
			
	return 0;
}