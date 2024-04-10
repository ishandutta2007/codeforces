//khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize("O2")
# pragma GCC optimize("Ofast")
# pragma GCC optimize("unroll-loops")
# pragma GCC target("avx,avx2,sse,sse2,fma")
 
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
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e6 + 10;
const int xm = 1e6 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, m, a[xn], b[xn], ptr, P[xm], ids[xn], s[xn], d[xn];
pii c[xn];
ll k, ret;
vector <int> adj[xn], vec[xn];
bool mark[xn];
 
void DFS(int v){
	mark[v] = true;
	c[v] = {ptr, SZ(vec[ptr])};
	vec[ptr].push_back(v);
	for (int u : adj[v])
		if (!mark[u])
			DFS(u);
}
void solve(){
	ptr = 0;
	for (int i = 1; i <= n; ++ i){
		int id = i % m;
		if (!id)
			id = m;
		ids[i] = id;
		if (c[P[a[i]]].A != c[id].A)
			continue;
		d[ptr ++] = i;
		s[i] = SZ(vec[c[id].A]);
		int id2 = c[id].A;
		ret -= (c[P[a[i]]].A == c[id].A && c[P[a[i]]].B < c[id].B);
	}
}
bool check(ll t){
	ll res = ret, y;
	int x;
	for (int j = 0; j < ptr; ++ j){
		int i = d[j];
		if (c[P[a[i]]].A != c[ids[i]].A)
			continue;
		ll tt = (t - i + 1 + n - 1) / n;
		x = c[ids[i]].B + tt % s[i] - 1;
		res += tt / s[i];
		if (x >= s[i])
			x -= s[i], ++ res;
		res += (c[P[a[i]]].B <= x);
	}
	return res > t - k;
}
 
int main(){
	InTheNameOfGod;
 
 	c[0].A = - 1;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= m; ++ i)
		cin >> b[i], P[b[i]] = i;
	for (int i = 1; i <= m; ++ i){
		int x = (i + n) % m;
		if (!x)
			x = m;
		adj[i].push_back(x);
	}
	for (int i = 1; i <= m; ++ i){
		if (mark[i])
			continue;
		DFS(i);
		ptr ++;
	}
	solve();
	ll l = 0, r = INF;
	while (r - l > 1){
		ll mid = l + r >> 1;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	cout << r << endl;
 
	return 0;
}