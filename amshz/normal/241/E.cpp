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
 
const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, dist[xn];
vector <pii> vec;
vector <int> adj[2][xn];
bool mark[2][xn], flag;

int main(){
	InTheNameOfGod;

	cin >> n >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		vec.push_back({v, u});
		adj[0][v].push_back(u);
		adj[1][u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i)
		dist[i] = inf;
	mark[0][1] = mark[1][n] = true;
	for (int v = 1; v <= n; ++ v)
		for (int u : adj[0][v])
			mark[0][u] |= mark[0][v];
	for (int v = n; v >= 1; -- v)
		for (int u : adj[1][v])
			mark[1][u] |= mark[1][v];
	for (int _ = 0; _ < n; ++ _){
		for (pii e : vec){
			int v = e.A, u = e.B;
			if (!mark[0][v] || !mark[1][u])
				continue;
			flag = false;
			if (dist[u] + 2 < dist[v])
				flag = true, dist[v] = dist[u] + 2;
			if (dist[v] - 1 < dist[u])
				flag = true, dist[u] = dist[v] - 1;
			if (_ + 1 == n && flag)
				kill("No");
		}
	}
	cout << "Yes" << endl;
	for (pii e : vec){
		int v = e.A, u = e.B;
		if (!mark[0][v] || !mark[1][u])
			cout << 1 << endl;
		else
			cout << dist[v] - dist[u] << endl;
	}

	return 0;
}