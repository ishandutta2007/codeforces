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
 
const int xn = 50 + 10;
const int xm = 1e4 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

struct edge{
	int from, to;
	ll cap, cost;
};

int n, k, dist[xn], par[xn], ptM;
vector <int> adj[xm];
queue <int> q;
ll ans, D, d[xm];
edge E[xm];
bool mark[xn];

void add_edge(int v, int u, int w, int cost){
	adj[v].push_back(ptM);
	E[ptM].from = v;
	E[ptM].to = u;
	E[ptM].cap = w;
	E[ptM].cost = cost;
	ptM ++;

	adj[u].push_back(ptM);
	E[ptM].from = u;
	E[ptM].to = v;
	E[ptM].cap = 0;
	E[ptM].cost = - cost;
	ptM ++;
}

int main(){
	fast_io;

	cin >> n >> k;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			int w;
			cin >> w;
			if (w){
				add_edge(i, j, w, 0);
				add_edge(i, j, inf, 1);
			}
		}
	}
	while (true){
		fill(dist, dist + n + 1, inf);
		fill(mark, mark + n + 1, false);
		dist[1] = 0;
		q.push(1);
		mark[1] = true;
		while (SZ(q)){
			int v = q.front();
			q.pop();
			mark[v] = false;
			for (int i = 0; i < SZ(adj[v]); ++ i){
				int id = adj[v][i];
				if (dist[v] + E[id].cost < dist[E[id].to] && E[id].cap){
					dist[E[id].to] = dist[v] + E[id].cost;
					par[E[id].to] = id;
					if (!mark[E[id].to])
						q.push(E[id].to);
					mark[E[id].to] = true;
				}
			}
		}
		if (k < dist[n])
			break;
		k -= dist[n];
		int v = n, mn = inf;
		while (v != 1){
			int id = par[v];
			mn = min(ll(mn), E[id].cap);
			if (E[id].cost)
				mn = 1;
			v = E[id].from;
		}
		v = n;
		while (v != 1){
			int id = par[v];
			E[id].cap -= mn;
			E[id ^ 1].cap += mn;
			v = E[id].from;
		}
		ans += mn;
	}
	cout << ans << endl;

	return 0;
}