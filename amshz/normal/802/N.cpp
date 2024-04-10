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
 
const int xn = 2200 + 10;
const int xm = 2e4 + 10;
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

int n, k, a[xn], b[xn], ptM, par[xn];
ll dist[xn], ans;
queue <int> q;
edge E[xm];
bool mark[xn];
vector <int> adj[xn];

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
	for (int i = 1; i < n; ++ i)
		add_edge(i, i + 1, inf, 0);
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], add_edge(0, i, 1, a[i]);
	for (int i = 1; i <= n; ++ i)
		cin >> b[i], add_edge(i, n + 1, 1, b[i]);
	while (k --){
		fill(dist, dist + n + 2, INF);
		dist[0] = 0;
		q.push(0);
		mark[0] = true;
		while (SZ(q)){
			int v = q.front();
			q.pop();
			mark[0] = false;
			for (int i = 0; i < SZ(adj[v]); ++ i){
				int id = adj[v][i];
				if (dist[v] + E[id].cost < dist[E[id].to] && E[id].cap){
					dist[E[id].to] = dist[v] + E[id].cost;
					par[E[id].to] = id;
					if (!mark[E[id].to])
						q.push(E[id].to);
				}
			}
		}
		int v = n + 1;
		while (v){
			int id = par[v];
			-- E[id].cap;
			++ E[id ^ 1].cap;
			v = E[id].from;
		}
		ans += dist[n + 1];
	}
	cout << ans << endl;

	return 0;
}