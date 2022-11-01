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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 5e3 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

int n, d, qq, p[xn], t[xn], H[xn], mx;
set <int> f[xn], F[xn];
set <pii> leaf;
ll s, ptr;

void solve(){
	memset(t, 0, sizeof t);
	for (int i = 0; i < xn; ++ i){
		f[i].clear();
		leaf.clear();
		F[i].clear();
	}
	cin >> n >> d;
	mx = 0, s = 0;
	for (int i = 1; i <= n; ++ i){
		p[i] = i / 2;
		++ t[i / 2];
		H[i] = H[i / 2] + 1;
		mx = max(mx, H[i]);
		s += H[i] - 1;
		F[H[i]].insert(i);
		f[i / 2].insert(i);
	}
	if (s > d){
		cout << "NO" << endl;
		return;
	}
	ptr = d - s;
	s = n * (n - 1) / 2;
	if (d > s){
		cout << "NO" << endl;
		return;
	}
	for (int i = 1; i <= n; ++ i) if (!t[i]) leaf.insert({- H[i], i});
	while (ptr --){
		int v = leaf.begin() -> B;
		leaf.erase(leaf.begin());
		int u = leaf.begin() -> B;
		leaf.erase(leaf.begin());
		if (H[v] == H[u]){
			-- t[p[v]];
			++ t[u];
			if (!t[p[v]]) leaf.insert({- H[p[v]], p[v]});
			f[p[v]].erase(v);
			p[v] = u;
			F[H[v]].erase(v);
			H[v] = H[u] + 1;
			F[H[v]].insert(v);
			leaf.insert({- H[v], v});
			f[u].insert(v);
		}
		else{
			int P = p[u];
			F[H[u]].erase(u);
			int w = *F[H[u]].begin();
			-- t[p[u]];
			++ t[w];
			if (!t[p[u]]) leaf.insert({- H[p[u]], p[u]});
			f[p[u]].erase(u);
			p[u] = w;
			H[u] = H[w] + 1;
			F[H[u]].insert(u);
			leaf.insert({- H[u], u});
			f[w].insert(u);
			leaf.insert({- H[v], v});
		}
	}
	cout << "YES" << endl;
	for (int i = 2; i <= n; ++ i) cout << p[i] << sep;
	cout << endl;
}

int main(){
    InTheNameOfGod;
    
	cin >> qq;
	while (qq --) solve();

    return 0;
}