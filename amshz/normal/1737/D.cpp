// khodaya khodet komak kon
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

int power(int a, ll b, int md){
	int res = 1;
	while (b){
		if ((b & 1))
			res = 1ll * res * a % md;
		a = 1ll * a * a % md;
		b >>= 1;
	}
	return res;
}

const int xn = 5e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

ll qq, n, m, dist[xn][xn], ans;
queue <int> q;
vector <int> adj[xn];
vector <ppi> E;

void BFS(int src, int id){
	for (int i = 1; i <= n; ++ i){
		dist[id][i] = inf;
	}
	dist[id][src] = 0;
	q.push(src);
	while (SZ(q)){
		int v = q.front();
		q.pop();
		for (int u : adj[v]){
			if (dist[id][u] < inf)
				continue;
			dist[id][u] = dist[id][v] + 1;
			q.push(u);
		}
	}
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i){
			adj[i].clear();
		}
		E.clear();
		for (int i = 0; i < m; ++ i){
			int v, u, w;
			cin >> v >> u >> w;
			adj[v].push_back(u);
			adj[u].push_back(v);
			E.push_back({{v, u}, w});
		}
		for (int i = 1; i <= n; ++ i)
			BFS(i, i);
		ans = INF;
		for (ppi e : E){
			int v = e.A.A, u = e.A.B, w = e.B;
			for (int i = 1; i <= n; ++ i){
				ans = min(ans, 1ll * w * (dist[v][i] + dist[i][1] + dist[i][n] + 2));
				ans = min(ans, 1ll * w * (dist[u][i] + dist[i][1] + dist[i][n] + 2));
			}
			ans = min(ans, 1ll * w * (dist[1][v] + dist[u][n] + 1));
			ans = min(ans, 1ll * w * (dist[1][u] + dist[v][n] + 1));
		}
		cout << ans << endl;
	}

	return 0;
}