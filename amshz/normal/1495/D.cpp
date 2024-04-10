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

const int xn = 4e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, dist[xn][xn], ord[xn], S, dp[xn], ans, res;
vector <int> adj[xn];
vector <pii> vec;

bool CMP(int i, int j){
	return dist[i][S] < dist[j][S];
}

int main(){
	InTheNameOfGod;

	for (int i = 0; i < xn; ++ i)
		for (int j = 0; j < xn; ++ j)
			dist[i][j] = inf;
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		dist[i][i] = 0;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		dist[v][u] = dist[u][v] = 1;
	}
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j)
			ord[j] = j;
		S = i;
		sort(ord + 1, ord + n + 1, CMP);
		for (int j = 1; j <= n; ++ j){
			res = 1;
			for (int p = 2; p <= n; ++ p){
				int v = ord[p];
				int ted = 0;
				for (int u : adj[v]){
					if (dist[i][v] != dist[i][u] + 1)
						continue;
					if (dist[i][j] == dist[i][v] + dist[v][j] && dist[i][j] == dist[i][u] + dist[u][j] && dist[v][j] < dist[u][j])
						++ ted;
					else if (dist[v][j] == dist[u][j] + 1)
						++ ted;
				}
				res = 1ll * res * ted % mod;
			}
			vec.clear();
			for (int k = 1; k <= n; ++ k)
				if (dist[i][k] + dist[k][j] == dist[i][j])
				vec.push_back({dist[i][k], dist[j][k]});
			sort(all(vec));
			for (int k = 1; k < SZ(vec); ++ k)
				if (vec[k] == vec[k - 1] && i != j)
					res = 0;
			cout << res << sep;
		}
		cout << endl;
	}

	return 0;
}