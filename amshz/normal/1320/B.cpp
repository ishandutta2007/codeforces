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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, k, a[xn], dist[xn], x, y;
vector <int> adj[2][xn];
queue <int> q;

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[0][v].push_back(u);
		adj[1][u].push_back(v);
	}
	cin >> k;
	for (int i = 1; i <= k; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		dist[i] = - 1;
	dist[a[k]] = 0;
	q.push(a[k]);
	while (SZ(q)){
		int v = q.front();
		q.pop();
		for (int u : adj[1][v]){
			if (dist[u] != - 1)
				continue;
			dist[u] = dist[v] + 1;
			q.push(u);
		}
	}
	for (int i = 1; i < k; ++ i){
		int v = a[i], u = a[i + 1];
		x += (dist[u] != dist[v] - 1);
		int t = 0;
		for (int w : adj[0][v])
			t += (dist[w] == dist[v] - 1);
		y += (dist[u] == dist[v] - 1 && t > 1);
	}
	cout << x << sep << x + y << endl;
	
	return 0;
}