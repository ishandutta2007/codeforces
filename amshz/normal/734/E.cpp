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
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int n, a[xn], H[xn], rt;
vector <pii> adj[xn];

void DFS(int v, int p = - 1){
	if (H[rt] < H[v])
		rt = v;
	for (pii u : adj[v]){
		if (p == u.A)
			continue;
		H[u.A] = H[v] + u.B;
		DFS(u.A, v);
	}
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i < n; ++ i){
		int v, u, w;
		cin >> v >> u;
		w = a[v] ^ a[u];
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
	}
	rt = 1;
	H[1] = 0, DFS(1);
	H[rt] = 0, DFS(rt);
	cout << (H[rt] + 1) / 2 << endl;

	return 0;
}