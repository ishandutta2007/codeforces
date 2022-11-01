# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;
 
# define endl         '\n'
# define sep         ' '
# define F              first
# define S              second
# define pb             push_back
# define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll md = 1e9+7;

ll gcd(ll a, ll b){
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}
ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
 
const int xn = 3e5+10;
const int xm = 5e4+10;

ll dist[xn], sm;
int p[xn], n, m;
vector <pair <int, ll> > adj[xn];
bool mark[xn], ans[xn];
map <pii, pair <int, ll> > mp;



void dijkstra(int s){
	set <pair <ll, int> > q;
	for (int i = 1; i <= n; i++) dist[i] = 1e18+10, mark[i] = false;
	dist[s] = 0;
	mark[s] = true;
	for (int i = 1; i <= n; i++) q.insert({dist[i], i});
	
	while (q.size()){
		set < pair <ll, int> > :: iterator it = q.begin();
		q.erase(it);
		int v = it->S;
		mark[v] = true;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i].F;
			if (mark[u]) continue;
			q.erase({dist[u], u});
			if (dist[v] + adj[v][i].S <= dist[u]) p[u] = v;
			dist[u] = min(dist[u], dist[v] + adj[v][i].S);	
			q.insert({dist[u], u});	
		}
	}
}




int main(){
    fast_io;
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
    	int v, u;
    	ll w;
    	cin >> v >> u >> w;
    	mp[{v, u}] = {i, w}, mp[{u, v}] = {i, w};
    	adj[v].pb({u, w});
    	adj[u].pb({v, w});
	}
	
	int s;
	cin >> s;
	
	dijkstra(s);
	
	for (int i = 1; i <= n; i++){
		if (i == s) continue;
		//sm += dist[i];
		//cout << i << " : " << dist[i] << endl;
		ans[mp[{i, p[i]}].F] = true;
		sm += mp[{i, p[i]}].S;
	}
	
	cout << sm << endl;
	for (int i = 1; i <= m; i++){
		if (ans[i]) cout << i << sep;
	}
	cout << endl;
    
    return 0;
}