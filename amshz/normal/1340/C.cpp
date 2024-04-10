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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e4 + 10;
const int xm = 1e3 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 2e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;
 
int n, m, d[xn], dist[xn][xm], g, r, ans = inf;
deque <pii> q;
vector <pii> adj[xn];
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> m, n = m - 1;
    for (int i = 0; i < m; ++ i) cin >> d[i];
    cin >> g >> r;
    sort(d, d + m);
    for (int i = 1; i < m; ++ i) adj[i].push_back({i - 1, d[i] - d[i - 1]});
	for (int i = 0; i < m - 1; ++ i) adj[i].push_back({i + 1, d[i + 1] - d[i]});
	for (int i = 0; i < m; ++ i) for (int j = 0; j < g; ++ j) dist[i][j] = - 1;
	dist[0][0] = 0;
	q.push_front({0, 0});
	while (SZ(q)){
		int v = q.front().A;
		int x = q.front().B;
		q.pop_front();
		for (pii u : adj[v]){
			if (u.B > g) kill(- 1);
			int z = x + u.B;
			if (z > g) continue;
			if (z < g){
				if (dist[u.A][z] != - 1) continue;
				dist[u.A][z] = dist[v][x];
				q.push_front({u.A, z});
				continue;
			}
			if (dist[u.A][0] != - 1) continue;
			dist[u.A][0] = dist[v][x] + 1;
			q.push_back({u.A, 0});
		}
	}
	if (dist[n][0] != - 1) ans = dist[n][0] * (g + r) - r;
	for (int i = 1; i < g; ++ i) if (dist[n][i] != -1) ans = min(ans, dist[n][i] * (g + r) + i);
	if (ans == inf) ans = - 1;
	kill(ans);
	
    return 0;
}