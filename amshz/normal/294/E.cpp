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
typedef pair <pii, int>                                  ppi;
typedef pair <pll, ll >                                  ppl;
typedef pair <int, pii>                                  pip;
typedef pair <ll , pll>                                  plp;
typedef pair <pii, pii>                                  ppp;
typedef pair <pll, pll>                                  PPP;
 
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
 
const int xn = 5e3 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;//998244353;
const int base = 257;

int n, sz[xn];
ll ans = INF, res, dist[xn];
ppi E[xn];
vector <pll> adj[xn];
bool mark[xn];

void plant(int v, int p){
	sz[v] = 1;
	for (pll u : adj[v])
		if (u.A != p)
			plant(u.A, v), sz[v] += sz[u.A];
}
int find_centroid(int v, int s, int p){
	for (pll u : adj[v])
		if (u.A != p && sz[u.A] + sz[u.A] > s)
			return find_centroid(u.A, s, v);
	return v;
}
void DFS(int v, int s, int t){
	mark[v] = true;
	res += dist[v] * ll(t);
	for (pll u : adj[v]){
		if (mark[u.A])
			continue;
		if (sz[v] > sz[u.A])
			res += ll(u.B) * ll(sz[u.A]) * ll(s - sz[u.A]);
		else
			res += ll(u.B) * ll(sz[v]) * ll(s - sz[v]);
		dist[u.A] = dist[v] + u.B;
		DFS(u.A, s, t);
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		E[i] = {{v, u}, w};
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
	}
	for (int i = 0; i < n - 1; ++ i){
		int v = E[i].A.A, u = E[i].A.B;
		int vv = v, uu = u;
		plant(v, u), plant(u, v);
		v = find_centroid(v, sz[v], u);
		u = find_centroid(u, sz[u], vv);
		dist[v] = dist[u] = res = 0;
		memset(mark, false, sizeof mark);
		mark[uu] = true, DFS(v, sz[vv], sz[uu]);
		mark[uu] = false, DFS(u, sz[uu], sz[vv]);
		res += 1LL * E[i].B * sz[vv] * sz[uu];
		ans = min(ans, res);
	}
	cout << ans << endl;
	
	return 0;
}