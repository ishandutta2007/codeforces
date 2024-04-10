# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, par[xn], sz[xn], k;
ll dist[xn], ans;
pair <ll, pii> E[xn];
vector <pair <int, ll> > adj[xn];
bool mark[xn];
set <pair <ll, int> > st;

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u, ll w){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	ans += w;
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
    	int v, u, w;
    	cin >> v >> u >> w;
    	E[i] = {w, {v, u}};
    	adj[v].push_back({u, w});
    	adj[u].push_back({v, w});
	}
	for (int i = 1; i <= n; ++ i)
		dist[i] = INF, par[i] = i, sz[i] = 1;
	cin >> k;
	for (int i = 1; i <= k; ++ i){
		int v;
		cin >> v;
		dist[v] = 0;
	}
	for (int i = 1; i <= n; ++ i)
		st.insert({dist[i], i});
	while (st.size()){
		int v = st.begin() -> B;
		st.erase(st.begin());
		mark[v] = true;
		for (pii u : adj[v]){
			if (mark[u.A])
				continue;
			st.erase({dist[u.A], u.A});
			if (dist[v] + u.B < dist[u.A])
				par[u.A] = par[v];
			dist[u.A] = min(dist[u.A], dist[v] + u.B);
			st.insert({dist[u.A], u.A});
		}
	}
	for (int i = 1; i <= m; ++ i)
		E[i].A += dist[E[i].B.A] + dist[E[i].B.B];
	sort(E + 1, E + m + 1);
	for (int i = 1; i <= m; ++ i)
		merge(E[i].B.A, E[i].B.B, E[i].A);
	cout << ans + dist[1] << endl;

    return 0;
}