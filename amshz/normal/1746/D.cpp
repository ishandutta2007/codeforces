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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, k, a[xn], par[xn];
map <int, ll> dp[xn];
vector <int> adj[xn];

void DFS(int v, int x){
	if (dp[v][x])
		return;
	dp[v][x] = 1ll * a[v] * x + 1;
	int d = SZ(adj[v]);
	if (!d)
		return;
	int y1 = x / d;
	int y2 = (x + d - 1) / d;
	vector <ll> vec;
	for (int u : adj[v]){
		DFS(u, y1);
		DFS(u, y2);
		dp[v][x] += dp[u][y1] - 1;
		vec.push_back(dp[u][y2] - dp[u][y1]);
	}
	sort(all(vec));
	reverse(all(vec));
	for (int i = 0; i < x % d; ++ i)
		dp[v][x] += vec[i];
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> k;
		for (int i = 1; i <= n; ++ i){
			adj[i].clear();
			dp[i].clear();
		}
		for (int i = 2; i <= n; ++ i){
			cin >> par[i];
			adj[par[i]].push_back(i);
		}
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		DFS(1, k);
		cout << dp[1][k] - 1 << endl;
	}

	return 0;
}