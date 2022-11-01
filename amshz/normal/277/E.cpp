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
 
const int xn = 800 + 10;
const int xm = 2e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;
 
struct edge{
	int from, to;
	ll cap;
	ld cost;
};
 
int n, ptM, par[xn];
pii a[xn];
ld dist[xn], ans;
queue <int> q;
edge E[xm];
bool mark[xn];
vector <int> adj[xn];
 
void add_edge(int v, int u, int w, ld cost){
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
 
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i].A >> a[i].B;
		add_edge(0, i, 2, 0);
		add_edge(n + i, n + n + 1, 1, 0);
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (a[j].B < a[i].B)
				add_edge(i, n + j, 1, pow(pow(abs(a[i].A - a[j].A), 2) + pow(abs(a[i].B - a[j].B), 2), 0.5));
	for (int _ = 1; _ < n; ++ _){
		fill(dist, dist + n + n + 2, INF);
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
		if (dist[n + n + 1] == INF)
			kill(- 1);
		int v = n + n + 1;
		while (v){
			int id = par[v];
			-- E[id].cap;
			++ E[id ^ 1].cap;
			v = E[id].from;
		}
		ans += dist[n + n + 1];
	}
	cout << fixed << setprecision(9) << ans << endl;
 
	return 0;
}