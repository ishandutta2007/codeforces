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

const int xn = 5e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, col[xn], ptr, d[xn], dist[xn], ans;
vector <int> adj[2][xn], tour, vec[xn];
vector <pii> E;
queue <int> q;
bool mark[xn], G[xn][xn];

void DFS(int v){
	mark[v] = true;
	for (int u : adj[0][v])
		if (!mark[u])
			DFS(u);
	tour.push_back(v);
}
void SFD(int v){
	mark[v] = true;
	col[v] = ptr;
	vec[ptr].push_back(v);
	for (int u : adj[1][v])
		if (!mark[u])
			SFD(u);
}
void BFS(int src){
	memset(dist, - 1, sizeof dist);
	dist[src] = 0;
	q.push(src);
	while (SZ(q)){
		int v = q.front();
		q.pop();
		for (int u : adj[0][v])
			if (dist[u] == - 1)
				dist[u] = dist[v] + 1, q.push(u);
	}
}

int main(){
	fast_io;

	cin >> n >> m, ans = n;
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		adj[0][v].push_back(u);
		adj[1][u].push_back(v);
		G[v][u] = true;
		E.push_back({v, u});
	}
	for (int v = 1; v <= n; ++ v)
		if (!mark[v])
			DFS(v);
	memset(mark, false, sizeof mark);
	reverse(all(tour));
	for (int v : tour)
		if (!mark[v])
			++ ptr, SFD(v);
	for (pii e : E)
		if (col[e.A] != col[e.B])
			++ d[col[e.A]];
	for (int i = 1; i <= ptr; ++ i){
		if (d[i])
			continue;
		int mn = inf;
		for (int v : vec[i]){
			BFS(v);
			for (int u : vec[i])
				if (dist[u] + 1 && G[u][v])
					mn = min(mn, dist[u] + 1);
		}
		if (mn < inf)
			ans += 998 * mn + 1;
	}
	cout << ans << endl;

	return 0;
}