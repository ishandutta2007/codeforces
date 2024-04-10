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
const int mod = 998244353;
const int base = 257;

ll n, a[xn], mx[2][xn], dp[2][xn], ps[2][xn], MX, ans = INF;
vector <int> adj[xn];

void DFS1(int v, int p = - 1){
	for (int u : adj[v]){
		if (u == p)
			continue;
		DFS1(u, v);
		mx[0][v] = max({mx[0][v], mx[0][u], a[u]});
		ps[0][v] += ps[0][u] + dp[0][u];
	}
	dp[0][v] = max(0ll, a[v] - mx[0][v]);
}
void DFS2(int v, int p = 0){
	vector <pii> vec;
	vec.push_back({max(a[p], mx[1][v]), v});
	ll sum = ps[1][v] + dp[1][v];
	for (int u : adj[v]){
		if (u == p)
			continue;
		vec.push_back({max(mx[0][u], a[u]), u});
		sum += ps[0][u] + dp[0][u];
	}
	sort(all(vec));
	reverse(all(vec));
	for (int u : adj[v]){
		if (u == p)
			continue;
		mx[1][u] = vec[0].A;
		if (u == vec[0].B)
			mx[1][u] = vec[1].A;
		dp[1][u] = max(0ll, a[v] - mx[1][u]);
		ps[1][u] = sum - ps[0][u] - dp[0][u];
		DFS2(u, v);
	}
	ans = min(ans, MX + ps[0][v] + ps[1][v] + max(0ll, a[v] - vec[0].A) + dp[1][v]);
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], MX = max(MX, a[i]);
	for (int i = 1; i < n; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS1(1);
	DFS2(1);
	cout << ans << endl;

	return 0;
}