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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, dist[xn][xn], mx, ans[4];
pii door[xn][3];
vector <int> adj[xn];
queue <int> q;
bool mark[xn];

void BFS(int s){
	for (int i = 1; i <= n; ++ i)
		dist[s][i] = - 1;
	dist[s][s] = 0;
	q.push(s);
	while (SZ(q)){
		int v = q.front();
		q.pop();
		for (int u : adj[v]){
			if (dist[s][u] != - 1)
				continue;
			dist[s][u] = dist[s][v] + 1;
			q.push(u);
		}
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++ i)
		BFS(i);
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < 3; ++ j){
			for (int k = 1; k <= n; ++ k){
				bool f = false;
				for (int l = 0; l < j; ++ l)
					f |= (k == door[i][l].A);
				if (f || i == k || dist[i][k] <= dist[i][door[i][j].A])
					continue;
				door[i][j].A = k;
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < 3; ++ j){
			for (int k = 1; k <= n; ++ k){
				bool f = false;
				for (int l = 0; l < j; ++ l)
					f |= (k == door[i][l].B);
				if (f || i == k || dist[k][i] < dist[door[i][j].B][i])
					continue;
				door[i][j].B = k;
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			if (i == j || dist[i][j] == - 1)
				continue;
			for (int k = 0; k < 3; ++ k){
				for (int p = 0; p < 3; ++ p){
					int v = door[i][k].B, u = door[j][p].A;
					if (v == u || i == v || j == v || i == u || j == u || !v || !u)
						continue;
					if (dist[v][i] == - 1 || dist[j][u] == - 1)
						continue;
					if (dist[v][i] + dist[i][j] + dist[j][u] > mx){
						mx = dist[v][i] + dist[i][j] + dist[j][u];
						ans[0] = v, ans[1] = i, ans[2] = j, ans[3] = u;
					}
				}
			}
		}
	}
	for (int i = 0; i < 4; ++ i)
		cout << ans[i] << sep;
	cout << endl;
			
	return 0;
}