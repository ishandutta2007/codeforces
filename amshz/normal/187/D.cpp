//khodaya khodet komak kon
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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
ll mod = 998244353;
const int base = 257;

ll n, G, R, a[xn], sum, b[xn], f[xn], par[xn];
ll sz[xn], c[xn], ans[xn], q;
set <pii> st;
vector <int> vec, S[xn];

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
	par[u] = v;
	sz[v] += sz[u];
	for (int x : S[u])
		S[v].push_back(x);
}
void get(int l, int r){
	while (st.lower_bound({l, 0}) != st.end()){
		pll x = *st.lower_bound({l, 0});
		if (x.A > r)
			return;
		vec.push_back(x.B);
		st.erase(x);
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> G >> R, mod = G + R;
	for (int i = 0; i <= n; ++ i)
		cin >> a[i];
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		cin >> b[i];
		par[i] = i, sz[i] = 1;
		f[i] = b[i] % mod;
		ans[i] = b[i] / mod;
		st.insert({f[i], i});
		S[i].push_back(i);
	}
	for (int i = 0; i < n; ++ i){
		sum += a[i];
		ll l = (G - sum % mod + mod) % mod;
		ll r = (mod - 1 - sum % mod + mod) % mod;
		ll hadaf = (r + 1) % mod;
		vec.clear();
		if (l <= r)
			get(l, r);
		else
			get(l, mod - 1), get(0, r);
		if (!SZ(vec))
			continue;
		int ind = vec[0];
		for (int x : vec){
			if (sz[x] > sz[ind])
				ind = x;
			c[x] += (hadaf < f[x]);
		}
		for (int x : vec){
			if (x == ind)
				continue;
			for (int y : S[x])
				ans[y] += c[x] - c[ind];
			merge(ind, x);
		}
		f[ind] = hadaf;
		st.insert({f[ind], ind});
	}
	sum += a[n];
	for (int i = 1; i <= q; ++ i){
		int v = get_root(i);
		cout << (ans[i] + c[v]) * mod + f[v] + sum << endl;
	}
			
	return 0;
}