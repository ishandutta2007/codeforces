# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 26+10;
const int SQ = 450;
 
int n = 26, m;
ll ans, dist[xn][xn];
string a, b, c, abc = "abcdefghijklmnopqrstuvwxyz";
vector <pair <int, ll> > adj[xn];
bool mark[xn];

void dijkstra(int s){
	set <pair <ll, int> > q;
	for (int i = 0; i < n; i++) dist[s][i] = 1e18+10, mark[i] = false;
	dist[s][s] = 0;
	mark[s] = true;
	for (int i = 0; i < n; i++) q.insert({dist[s][i], i});
	
	while (q.size()){
		set < pair <ll, int> > :: iterator it = q.begin();
		q.erase(it);
		int v = it->S;
		mark[v] = true;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i].F;
			if (mark[u]) continue;
			q.erase({dist[s][u], u});
			dist[s][u] = min(dist[s][u], dist[s][v] + adj[v][i].S);	
			q.insert({dist[s][u], u});	
		}
	}
}


 
int main(){
	//fast_io;
	
	cin >> a >> b >> m;
	for (int i = 0; i < m; i++){
		char vv, uu;
		ll w;
		cin >> vv >> uu >> w;
		int v = int(vv-'a'), u = int(uu-'a');
		adj[v].pb({u, w});
	}
	for (int i = 0; i < 26; i++) dijkstra(i);
	if (a.size() != b.size()){
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < a.size(); i++){
		ll mn = 1e18;
		ll f;
		int v = int(a[i]-'a'), u = int(b[i]-'a');
		for (int j = 0; j < 26; j++){
			int z = j;
			ll cost = dist[v][z] + dist[u][z];
			if (mn == 1e18 || dist[v][mn] + dist[u][mn] > cost){
				mn = z;
				f = cost;
			}
		}
		ans += f;
		if (mn <= 25) c += abc[mn];
		if (f >= 1e18){
			cout << -1 << endl;
			return 0;
		}
		
	}
	if (ans >= 1e18 || ans < 0){
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl << c << endl;
 
	return 0;
}