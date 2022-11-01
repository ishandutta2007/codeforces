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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, a[xn], n, ans, ord[xn];
pii d[xn];
vector <int> adj[xn];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n, ans = 0;
		for (int i = 1; i <= n; ++ i)
			adj[i].clear();
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			adj[a[i]].push_back(i);
		}
		for (int i = 1; i <= n; ++ i)
			d[i] = {SZ(adj[i]), i};
		sort(d + 1, d + n + 1);
		for (int i = 1; i <= n; ++ i){
			while (1 < SZ(adj[i])){
				int v = adj[i].back();
				adj[i].pop_back();
				int u = adj[i].back();
				adj[i].pop_back();
				int w = d[++ ans].B;
				if (u == w){
					a[v] = w;
					adj[i].push_back(u);
				}
				else{
					a[u] = w;
					adj[i].push_back(v);
				}
			}
		}
		cout << n - ans << endl;
		for (int i = 1; i <= n; ++ i)
			cout << a[i] << sep;
		cout << endl;
	}

	return 0;
}