//khodaya khodet komak kon
# include <bits/stdc++.h>

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, a[xn], dp[xn][7], f[7][7], pd[2][8];
vector <int> adj[xn], vec[xn];

ll DFS(int v, int p = - 1){
	for (int u : adj[v])
		if (u != p)
			DFS(u, v);
	memset(pd, 0, sizeof pd);
	for (int u : adj[v]){
		if (u == p)
			continue;
		for (int i = 0; i < 5; ++ i)
			for (int j = 0; j < 5; ++ j)
				pd[0][f[i][j]] = max(pd[0][f[i][j]], pd[1][i] + dp[u][j]);
		pd[0][4] = max(pd[0][4], pd[1][1] + dp[u][3] + a[v]);
		pd[0][4] = max(pd[0][4], pd[1][3] + dp[u][1] + a[v]);
		dp[v][2] = max(dp[v][2], pd[1][1] + dp[u][1] + a[v]);
		for (int i = 0; i < 5; ++ i)
			pd[1][i] = pd[0][i], pd[0][i] = 0;
	}
	reverse(all(adj[v]));
	for (int i = 0; i < 5; ++ i)
		dp[v][i] = max(dp[v][i], pd[1][i]);
	memset(pd, 0, sizeof pd);
	for (int u : adj[v]){
		if (u == p)
			continue;
		for (int i = 0; i < 5; ++ i)
			for (int j = 0; j < 5; ++ j)
				pd[0][f[i][j]] = max(pd[0][f[i][j]], pd[1][i] + dp[u][j]);
		pd[0][4] = max(pd[0][4], pd[1][1] + dp[u][3] + a[v]);
		pd[0][4] = max(pd[0][4], pd[1][3] + dp[u][1] + a[v]);
		dp[v][2] = max(dp[v][2], pd[1][1] + dp[u][1] + a[v]);
		for (int i = 0; i < 5; ++ i)
			pd[1][i] = pd[0][i], pd[0][i] = 0;
	}
	for (int i = 0; i < 5; ++ i)
		dp[v][i] = max(dp[v][i], pd[1][i]);
	dp[v][1] += a[v], dp[v][3] += a[v];
	for (int i = 1; i < 5; ++ i)
		dp[v][i] = max(dp[v][i], dp[v][i - 1]);
	return dp[v][4];
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 0; i < 5; ++ i)
		for (int j = 0; j < 5; ++ j)
			f[i][j] = 5;
	for (int i = 0; i < 5; ++ i)
		f[i][0] = f[0][i] = i;
	f[1][1] = f[1][2] = f[2][1] = 3;
	f[1][3] = f[3][1] = f[2][2] = 4;
	cout << DFS(1) << endl;

	return 0;
}
/*
8
1 1 1 1 0 1 1 1
1 2
1 3
3 4
3 5
5 6
6 7
6 
*/