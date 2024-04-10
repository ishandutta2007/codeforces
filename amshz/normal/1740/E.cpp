// khodaya khodet komak kon
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

int power(int a, ll b, int md){
	int res = 1;
	while (b){
		if ((b & 1))
			res = 1ll * res * a % md;
		a = 1ll * a * a % md;
		b >>= 1;
	}
	return res;
}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, p[xn], dp[xn], pd[xn];
vector <int> adj[xn];

void DFS(int v){
	for (int u : adj[v]){
		DFS(u);
		dp[v] += dp[u];
		pd[v] = max(pd[v], pd[u]);
	}
	++ pd[v];
	dp[v] = max(dp[v], pd[v]);
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 2; i <= n; ++ i){
		cin >> p[i];
		adj[p[i]].push_back(i);
	}
	DFS(1);
	cout << dp[1] << endl;

	return 0;
}