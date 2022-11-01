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
 
const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
int mod = 1e9 + 7;
const int base = 257;

int n, m, a, b, k, dist[xn][xn];
int dp[xn], f[xn];
vector <int> adj[xn], vec[xn][xn];
pii s[xn];
queue <int> q;
bool mark[xn];

void BFS(int x){
	for (int i = 1; i <= n; ++ i)
		dist[x][i] = inf;
	dist[x][x] = 0;
	q.push(x);
	while (SZ(q)){
		int v = q.front();
		q.pop();
		for (int u : adj[v]){
			if (dist[x][u] < inf)
				continue;
			dist[x][u] = dist[x][v] + 1;
			q.push(u);
		}
	}
}

int main(){
    //InTheNameOfGod;
    
    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; ++ i){
    	int v, u;
    	cin >> v >> u;
    	adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++ i)
		BFS(i);
	cin >> k;
	for (int i = 0; i < k; ++ i){
		int v, u;
		cin >> v >> u;
		s[i] = {v, u};
		for (int j = 1; j <= n; ++ j)
			if (dist[v][j] + dist[j][u] == dist[v][u] && dist[v][u] < inf)
				vec[i][dist[v][j]].push_back(j);
	}
	for (int i = 1; i <= n; ++ i)
		dp[i] = inf;
	dp[b] = 0;
	mark[b] = true;
	while (!mark[a]){
		int res = - 1, val = inf + 1;
		for (int i = 0; i < k; ++ i){
			for (int d = n; d >= 0; -- d){
				for (int v : vec[i][d]){
					int mx = - 1;
					for (int u : adj[v]){
						if (dist[s[i].A][u] <= dist[s[i].A][v])
							continue;
						if (dist[u][s[i].B] >= dist[v][s[i].B])
							continue;
						mx = max(mx, f[u]);
					}
					if (mx == - 1)
						mx = inf;
					f[v] = min(dp[v], mx);
					if (mark[v] || SZ(vec[i][d]) > 1)
						continue;
					if (f[v] < val)
						res = v, val = f[v] + 1;
				}
			}
		}
		if (res == - 1)
			break;
		mark[res] = true;
		dp[res] = val;
	}
	if (dp[a] >= inf)
		dp[a] = - 1;
	cout << dp[a] << endl;
	
    return 0;
}