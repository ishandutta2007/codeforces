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

ll n, m, sz[xn], ans, pw[xn], inv[xn], phi;
vector <pii> adj[xn];
map <int, int> cnt;
bool hide[xn];

void plant(int v, int p = - 1){
	sz[v] = 1;
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p)
			plant(u.A, v), sz[v] += sz[u.A];
}
int find_centroid(int v, int s, int p = - 1){
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p && sz[u.A] + sz[u.A] > s)
			return find_centroid(u.A, s, v);
	return v;
}
void get(int v, ll res, bool f, int h = 1, int p = - 1){
	ans += (f && !res) + cnt[(m - res) * inv[h] % m];
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p)
			get(u.A, (res * pw[1] + u.B) % m, f, h + 1, v);
}
void add(int v, ll res, bool f, int h = 1, int p = - 1){
	ans += (f && !res), ++ cnt[res];
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p)
			add(u.A, (res + ll(u.B) * pw[h]) % m, f, h + 1, v);
}
void solve(int v){
	plant(v);
	v = find_centroid(v, sz[v]);
	hide[v] = true;
	cnt.clear();
	for (pii u : adj[v])
		if (!hide[u.A])
			get(u.A, u.B, 1), add(u.A, u.B, 1);
	reverse(all(adj[v])), cnt.clear();
	for (pii u : adj[v])
		if (!hide[u.A])
			get(u.A, u.B, 0), add(u.A, u.B, 0);
	for (pii u : adj[v])
		if (!hide[u.A])
			solve(u.A);
}
void calc_phi(){
    phi = m;
    int t = m;
    for (int i = 2; i * i <= t; ++ i){
        if (t % i)
			continue;
        while (t % i == 0)
			t /= i;
        phi -= phi / i;
    }
    if (t > 1)
		phi -= phi / t;
    -- phi;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	calc_phi();
	pw[1] = 10, inv[1] = power(10, phi, m);
	for (int i = 2; i < xn; ++ i)
		pw[i] = pw[i - 1] * pw[1] % m, inv[i] = inv[i - 1] * inv[1] % m;
	for (int i = 0; i < n - 1; ++ i){
		int v, u, w;
		cin >> v >> u >> w, w %= m;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
	}
	solve(0);
	cout << ans << endl;
			
	return 0;
}