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
 
const int xn = 1e2 + 10;
const int xm = 1e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

struct edge{
	int from, to;
	ll cap;
};

int n, m, pt[xm], dist[xm], ptM, q[xm], a[xm];
vector <int> adj[xm];
ll ans, D, sum;
edge E[xm];

ll DFS(int v, ll val, int t){
	if (v == t || !val)
		return val;
	ll res = 0;
	while (pt[v] < SZ(adj[v])){
		int id = adj[v][pt[v]];
		if (dist[E[id].to] <= dist[v] || E[id].cap < D){
			pt[v] ++;
			continue;
		}
		ll w = DFS(E[id].to, min(val, E[id].cap), t);
		if (!w){
			pt[v] ++;
			continue;
		}
		val -= w, res += w;
		E[id].cap -= w;
		E[id ^ 1].cap += w;
		if (!val)
			break;
	}
	return res;
}
bool BFS(int s, int t){
	fill(dist, dist + t + 1, - 1);
	dist[s] = 0;
	int L = 0, R = 0;
	q[R ++] = s;
	while (L < R){
		int v = q[L ++];
		for (int i = 0; i < SZ(adj[v]); ++ i){
			int id = adj[v][i];
			if (E[id].cap < D || dist[E[id].to] != - 1)
				continue;
			dist[E[id].to] = dist[v] + 1;
			q[R ++] = E[id].to;
		}
	}
	return dist[t] != - 1;
}
void add_edge(int v, int u, int w, bool f){
	adj[v].push_back(ptM);
	E[ptM].from = v;
	E[ptM].to = u;
	E[ptM].cap = w;
	ptM ++;

	adj[u].push_back(ptM);
	E[ptM].from = u;
	E[ptM].to = v;
	E[ptM].cap = 0;
	if (f)
		E[ptM].cap = w;
	ptM ++;
}
void FLOW(int s, int t){
	D = INF, ans = 0;
	while (D){
		while (BFS(s, t)){
			fill(pt, pt + t + 1, 0);
			ans += DFS(s, INF, t);
		}
		D /= 2;
	}
}
int main(){
	fast_io;

	cin >> n >> m;
	int s = n + m + 1, t = s + 1;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		add_edge(i, t, a[i], 0);
	}
	for (int i = 1; i <= m; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		add_edge(n + i, v, inf, 0);
		add_edge(n + i, u, inf, 0);
		add_edge(s, n + i, w, 0);
		sum += w;
	}
	FLOW(s, t);
	cout << sum - ans << endl;

	return 0;
}