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

const int xn = 1e2 + 10;
const int xm = 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, k, dp[xn][2][xm], sum;
vector <int> adj[xn];

void DFS(int v, int par = - 1){
	for (int i = 1; i <= k; ++ i)
		dp[v][0][i] = dp[v][1][i] = 1;
	dp[v][1][0] = 1;
	for (int u : adj[v]){
		if (u == par)
			continue;
		DFS(u, v);
		for (int i = 0; i <= k; ++ i){
			sum = (dp[u][1][i + 1] + dp[u][0][i + 1]) % mod;
			sum = (sum + dp[u][1][i]) % mod;
			dp[v][0][i] = 1ll * dp[v][0][i] * sum % mod;
			if (i)
				sum = (sum + dp[u][1][i - 1]) % mod;
			dp[v][1][i] = 1ll * dp[v][1][i] * sum % mod;
		}
	}
	for (int i = 0; i <= k; ++ i)
		dp[v][1][i] = (dp[v][1][i] - dp[v][0][i] + mod) % mod;
}

int main(){
	fast_io;

	cin >> n >> k;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	sum = 0;
	for (int i = 0; i <= k; ++ i)
		sum = (sum + dp[1][1][i]) % mod;
	cout << sum << endl;

	return 0;
}