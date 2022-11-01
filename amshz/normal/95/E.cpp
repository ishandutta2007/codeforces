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
const int mod = 998244353;
const int base = 257;

int n, m, cnt, dp[xn], ans = inf;
bool mark[xn];
vector <int> adj[xn], vec[xn];

void DFS(int v){
	mark[v] = true, ++ cnt;
	for (int u : adj[v])
		if (!mark[u])
			DFS(u);
}

int main(){
	fast_io;

	cin >> n >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i)
		if (!mark[i])
			cnt = 0, DFS(i), vec[cnt].push_back(1);
	for (int i = 1; i < xn; ++ i)
		dp[i] = inf;
	for (int i = 1; i < xn; ++ i){
		sort(all(vec[i]));
		while (2 < SZ(vec[i])){
			int x = vec[i].back();
			vec[i].pop_back();
			x += vec[i].back();
			vec[i].pop_back();
			vec[i + i].push_back(x);
		}
		while (SZ(vec[i])){
			int x = vec[i].back();
			vec[i].pop_back();
			for (int j = n; i <= j; -- j)
				dp[j] = min(dp[j], dp[j - i] + x);
		}
	}
	memset(mark, false, sizeof mark);
	mark[0] = true;
	for (int i = 1; i <= n; ++ i){
		mark[i] = (mark[i / 10] && (i % 10 == 4 || i % 10 == 7));
		if (mark[i])
			ans = min(ans, dp[i]);
	}
	if (ans == inf)
		ans = 0;
	cout << ans - 1 << endl;

	return 0;
}