# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e5+10;
const int xm = 5e5+10;
const int SQ = 1000;
const ll inf = 1e18+10;

struct edge{
	ll V, U, W, P;
};

ll n, L, x[xn], d[xn], p[xn], t[xn], s, par[xn], dis[xn], g[xn];
vector <ll> vec;
vector <edge> adj[xn];
map <ll, ll> tab, mp;
bool mark[xm];

void Dijkstra(ll start){
	for (int i = 0; i < s; i++) dis[i] = inf;
	dis[start] = 0;
	set <pll> q;
	for (int i = 0; i < s; i++) q.insert({dis[i], i});
	while (q.size()){
		ll v = q.begin() -> S;
		q.erase(q.begin());
		mark[v] = true;
		for (int i = 0; i < adj[v].size(); i++){
			ll u = adj[v][i].U;
			if (mark[u]) continue;
			q.erase({dis[u], u});
			if (dis[v] + adj[v][i].W < dis[u]){
				par[u] = v;
				g[u] = adj[v][i].P;
			}
			dis[u] = min(dis[u], dis[v] + adj[v][i].W);
			q.insert({dis[u], u});
		}
	}
}
 
 
int main(){
	fast_io;
	
	cin >> n >> L;
	for (int i = 0; i < n; i++) cin >> x[i] >> d[i] >> t[i] >> p[i];
	
	vec.pb(0), vec.pb(L);
	for (int i = 0; i < n; i++) vec.pb(x[i]), vec.pb(x[i]-p[i]), vec.pb(x[i]+d[i]);
	
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++){
		if (vec[i] < 0) continue;
		if (i == 0 || vec[i] != vec[i-1]) mp[vec[i]] = s++, tab[s-1] = vec[i];
	}
	
	
	for (int i = 1; i < s; i++){
		edge e;
		e.V = i, e.U = i - 1, e.W = tab[i] - tab[i-1], e.P = 0;
		adj[i].pb(e);
		swap(e.V, e.U);
		adj[i-1].pb(e);
	}
	
	for (int i = 0; i < n; i++){
		edge e;
		if (x[i] - p[i] < 0) continue;
		e.V = mp[x[i] - p[i]], e.U = mp[x[i] + d[i]], e.W = t[i] + p[i], e.P = i+1;
		adj[e.V].pb(e);
	}
	Dijkstra(0);
	
	cout << dis[mp[L]] << endl;
	
	vector <ll> ans;
	ll v = mp[L];
	while (v != 0){
		if (g[v]) ans.pb(g[v]);
		v = par[v];
	}
	cout << ans.size() << endl;
	for (int i = ans.size()-1; i >= 0; i--) cout << ans[i] << sep;
	cout << endl;
		
	return 0;
}