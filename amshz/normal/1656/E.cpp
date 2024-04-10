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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, d[xn], a[xn], qq;
vector <int> adj[xn];

void DFS(int v, int h = - 1, int p = - 1){
	a[v] = h * d[v];
	for (int u : adj[v])
		if (u != p)
			DFS(u, - h, v);
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			adj[i].clear(), d[i] = 0;
		for (int i = 0; i < n - 1; ++ i){
			int v, u;
			cin >> v >> u;
			++ d[v], ++ d[u];
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		DFS(1);
		for (int i = 1; i <= n; ++ i)
			cout << a[i] << sep;
		cout << endl;
	}

	return 0;
}