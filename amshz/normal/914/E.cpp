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

const int xn = 2e5 + 10;
const int xm = 21;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, c[xn], sz[xn], cnt[1 << xm];
ll ans[xn], part[xn];
string s;
vector <int> adj[xn], vec;
bool hide[xn];

void plant(int v, int p = - 1){
	sz[v] = 1, part[v] = 0;
	for (int u : adj[v])
		if (!hide[u] && u != p)
			plant(u, v), sz[v] += sz[u];
}
int find_centroid(int v, int s, int p = - 1){
	for (int u : adj[v])
		if (!hide[u] && u != p && sz[u] + sz[u] > s)
			return find_centroid(u, s, v);
	return v;
}
void add(int v, int res, int val, int p = - 1){
	res ^= c[v];
	cnt[res] += val;
	for (int u : adj[v])
		if (!hide[u] && u != p)
			add(u, res, val, v);
}
void get(int v, int res = 0, int p = - 1){
	res ^= c[v];
	for (int x : vec)
		part[v] += cnt[res ^ x];
	for (int u : adj[v])
		if (!hide[u] && u != p)
			get(u, res, v);
}
void check_paths(int v){
	for (int u : adj[v])
		if (!hide[u])
			get(u), add(u, c[v], 1);
	for (int u : adj[v])
		if (!hide[u])
			add(u, c[v], - 1);
}
void calc_ans(int v, int p = - 1){
	for (int u : adj[v])
		if (!hide[u] && u != p)
			calc_ans(u, v), part[v] += part[u];
	ans[v] += part[v];
}
void ultra_calc(int v, int res = 0, int p = - 1){
	res ^= c[v];
	part[v] = 0;
	for (int x : vec)
		if (x == res)
			++ part[v];
	for (int u : adj[v])
		if (!hide[u] && u != p)
			ultra_calc(u, res, v), part[v] += part[u];
	ans[v] += part[v];
}
void solve(int v){
	plant(v);
	v = find_centroid(v, sz[v]);
	hide[v] = true;
	check_paths(v);
	reverse(all(adj[v]));
	check_paths(v);
	calc_ans(v);
	ans[v] -= part[v] / 2;
	ultra_calc(v);
	for (int u : adj[v])
		if (!hide[u])
			solve(u);
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	cin >> s;
	for (int i = 1; i <= n; ++ i)
		c[i] = (1 << (s[i - 1] - 'a'));
	vec.push_back(0);
	for (int i = 0; i < 20; ++ i)
		vec.push_back((1 << i));
	solve(1);
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << sep;
	cout << endl;
			
	return 0;
}