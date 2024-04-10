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
const int xn = 5e2+10;
const int xm = 5e2+10;
const int SQ = 1000;
const int inf = 1e9+10;

int dis[xn][xn][2], n, m;
pair <pii, bool> par[xn][xn][2];
vector <int> adj[xn];

int main(){
	fast_io;
	
	cin >> n >> m;
	int v, u;
	
	for (int i = 0; i < m; i++){
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	
	queue <pair <pii, bool> > q;
	
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k < 2; k++) dis[i][j][k] = inf;

	dis[1][n][0] = 0;
	q.push({{1, n}, 0});
	
	while (q.size()){
		v = q.front().F.F, u = q.front().F.S;
		int t = q.front().S;
		//cout << v << sep << u << sep << dis[v][u][t] << endl;
		q.pop();
		
		if (t == 0){
			for (int i = 0; i < adj[v].size(); i++){
				int y = adj[v][i];
				if (dis[y][u][1] < inf) continue;
				dis[y][u][1] = dis[v][u][0] + 1;
				par[y][u][1] = {{v, u}, 0};
				q.push({{y, u}, 1});
			}
		}
		else{
			for (int i = 0; i < adj[u].size(); i++){
				int y = adj[u][i];
				if (v == y || dis[v][y][0] < inf) continue;
				dis[v][y][0] = dis[v][u][1] + 1;
				par[v][y][0] = {{v, u}, 1};
				q.push({{v, y}, 0});
			}
		}
		//cout << "YES" << endl;
	}
	
	if (dis[n][1][0] == inf){
		cout << -1 << endl;
		return 0;
	}
	
	cout << dis[n][1][0]/2 << endl;
	
	int x = n, y = 1, z = 0;
	
	vector <int> s1, s2;
	
	while (x != 1 || y != n || z != 0){
		if (z == 0) s1.pb(x), s2.pb(y);
		
		int x2 = par[x][y][z].F.F, y2 = par[x][y][z].F.S, z2 = par[x][y][z].S;
		
		x = x2, y = y2, z = z2; 
	}
	s1.pb(1);
	s2.pb(n);
	for (int i = s1.size()-1; i >= 0; i--) cout << s1[i] << sep;
	cout << endl;
	for (int i = s2.size()-1; i >= 0; i--) cout << s2[i] << sep;
	cout << endl;
	
	
	
	return 0;
}