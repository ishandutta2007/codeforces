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
 
ll n, m, sz[xn], ans, H[xn], dist[xn], L, W;
ll fen[xn];
vector <pair <ll, pii> > query;
vector <pii> adj[xn];
bool hide[xn];
 
void modify(int pos, ll val){
	if (pos < 1)
		return;
	for (; pos < xn; pos += pos & -pos)
		fen[pos] += val;
}
ll get(int pos){
	if (pos < 1)
		return 0;
	ll sum = 0;
	for (; pos > 0; pos -= pos & -pos)
		sum += fen[pos];
	return sum;
}
void plant(int v, int p = - 1){
	sz[v] = 1;
	for (pii u : adj[v]){
		if (hide[u.A] || u.A == p)
			continue;
		H[u.A] = H[v] + 1;
		dist[u.A] = dist[v] + u.B;
		plant(u.A, v);
		sz[v] += sz[u.A];
	}
}
int find_centroid(int v, int s, int p = - 1){
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p && sz[u.A] + sz[u.A] > s)
			return find_centroid(u.A, s, v);
	return v;
}
ll DFS(int v, int p = - 1){
	query.push_back({dist[v], {0, H[v]}});
	query.push_back({W - dist[v], {1, L - H[v]}});
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p)
			DFS(u.A, v);
}
ll close_pairs(int v){
	query.clear();
	DFS(v);
	sort(all(query));
	ll res = 0;
	for (pair <ll, pii> x : query){
		if (x.B.A)
			res += get(x.B.B + 1);
		else
			modify(x.B.B + 1, 1);
	}
	for (pair <ll, pii> x : query)
		if (!x.B.A)
			modify(x.B.B + 1, - 1);
	return res;
}
void solve(int v){
	plant(v);
	v = find_centroid(v, sz[v]);
	H[v] = dist[v] = 0, plant(v);
	ans += close_pairs(v);
	hide[v] = true;
	for (pii u : adj[v])
		if (!hide[u.A])
			ans -= close_pairs(u.A);
	for (pii u : adj[v])
		if (!hide[u.A])
			solve(u.A);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> L >> W;
	for (int i = 2; i <= n; ++ i){
		int v, w;
		cin >> v >> w;
		adj[v].push_back({i, w});
		adj[i].push_back({v, w});
	}
	solve(1);
	cout << (ans - n) / 2 << endl;
			
	return 0;
}