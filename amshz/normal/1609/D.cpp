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

const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, sz[xn], par[xn], m, cnt, ans;
vector <int> vec;

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
bool merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return true;
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	return false;
}

int main(){
	fast_io;

	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		par[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		cnt += merge(v, u);
		vec.clear();
		for (int v = 1; v <= n; ++ v)
			if (get_root(v) == v)
				vec.push_back(sz[v]);
		sort(all(vec));
		reverse(all(vec));
		ans = 0;
		for (int j = 0; j <= cnt; ++ j)
			ans += vec[j];
		cout << ans - 1 << endl;
	}

	return 0;
}