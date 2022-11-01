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

const int xn = 2e5 + 10;
const int xm = 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, dp[xm][xn], ans = inf;
pii dist[2][xn];
vector <int> adj[2][xn];
deque <pii> dq;
set <ppi> st;
bool mark[xn + xn];

int main(){
	InTheNameOfGod;

	cin >> n >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[0][v].push_back(u);
		adj[1][u].push_back(v);
	}
	for (int i = 0; i < xm; ++ i)
		for (int v = 1; v <= n; ++ v)
			dp[i][v] = inf;
	dp[0][1] = 0, dq.push_back({1, 0});
	while (SZ(dq)){
		int v = dq.front().A, k = dq.front().B;
		dq.pop_front();
		if (v == n)
			ans = min(ans, dp[k][v] + (1 << k) - 1);
		if (k < xm - 1 && dp[k][v] < dp[k + 1][v])
			dp[k + 1][v] = dp[k][v], dq.push_front({v, k + 1});
		for (int u : adj[k % 2][v])
			if (dp[k][v] + 1 < dp[k][u])
				dp[k][u] = dp[k][v] + 1, dq.push_back({u, k});
	}
	if (ans < inf)
		kill(ans);
	for (int j = 0; j < 2; ++ j)
		for (int i = 1; i <= n; ++ i)
			dist[j][i] = {inf, inf};
	dist[0][1] = {0, 0};
	for (int j = 0; j < 2; ++ j)
		for (int i = 1; i <= n; ++ i)
			st.insert({dist[j][i], i + i + j});
	while (SZ(st)){
		int v = st.begin() -> B;
		st.erase(st.begin());
		mark[v] = true;
		int f = v % 2;
		v /= 2;
		for (int u : adj[f][v]){
			if (mark[u + u + f])
				continue;
			st.erase({dist[f][u], u + u + f});
			dist[f][u] = min(dist[f][u], {dist[f][v].A, dist[f][v].B + 1});
			st.insert({dist[f][u], u + u + f});
		}
		if (mark[v + v + !f])
			continue;
		st.erase({dist[!f][v], v + v + !f});
		dist[!f][v] = min(dist[!f][v], {dist[f][v].A + 1, dist[f][v].B});
		st.insert({dist[!f][v], v + v + !f});
	}
	dist[0][n] = min(dist[0][n], dist[1][n]);
	ans = 1;
	for (int i = 0; i < dist[0][n].A; ++ i)
		ans = 2ll * ans % mod;
	ans = (ans + dist[0][n].B - 1 + mod) % mod;
	cout << ans << endl;

	return 0;
}