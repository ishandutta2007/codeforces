// khodaya khodet komak kon
// Maybe on the Moon
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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, dp[3][xn];
vector <int> adj[xn];

void DFS(int v, int par = - 1){
	dp[0][v] = dp[1][v] = 1;
	for (int u : adj[v]){
		if (u == par)
			continue;
		DFS(u, v);
		dp[1][v] = 1ll * dp[1][v] * (dp[0][u] + 2 * dp[2][u] % mod) % mod;
		dp[0][v] = 1ll * dp[0][v] * (dp[0][u] + dp[2][u]) % mod;
		dp[2][v] = (dp[2][v] + 1ll * dp[1][u] * power((dp[0][u] + 2 * dp[2][u] % mod) % mod, mod - 2, mod) % mod) % mod;
	}
	dp[2][v] = 1ll * dp[2][v] * dp[1][v] % mod;
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
	DFS(1);
	cout << (dp[0][1] + dp[2][1]) % mod << endl;

	return 0;
}