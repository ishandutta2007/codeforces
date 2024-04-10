# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

ll n, m, a[xn], b[xn], s[xn], sz[xn], par[xn], ans;
vector <int> vec[xn];
vector <pair <ll, pii> > E;

int get_root(int v){
	if (par[v] == v) return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u, ll w){
	v = get_root(v);
	u = get_root(u);
	if (v == u) return;
	if (sz[v] < sz[u]) swap(v, u);
	par[u] = v;
	sz[v] += sz[u];
	ans -= w;
}

int main(){
    //InTheNameOfGod;
    
	cin >> m >> n;
	for (int i = 1; i <= m; ++ i) cin >> a[i];
	for (int i = 1; i <= n; ++ i) cin >> b[i];
	for (int i = 1; i <= m; ++ i){
		cin >> s[i];
		for (int j = 0; j < s[i]; ++ j){
			int v;
			cin >> v;
			E.push_back({a[i] + b[v], {i, v + m}});
			ans += a[i] + b[v];
		}
	}
	sort(all(E));
	reverse(all(E));
	for (int i = 1; i <= n + m; ++ i){
		sz[i] = 1;
		par[i] = i;
	}
	for (pair <ll, pii> e : E) merge(e.B.A, e.B.B, e.A);
	cout << ans << endl;
 
    return 0;
}