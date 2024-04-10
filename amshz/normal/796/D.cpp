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
const int xn = 3e5+10;
const int xm = 5e2+10;
const int SQ = 1000;

struct edge{
	int V, U, ind;
};

int n, k, d, par[xn], dist[xn];
vector <int> vec, adj[xn], ans;
edge e[xn];


int main(){
	cin >> n >> k >> d;
	int v, u;
	for (int i = 0; i < k; i++) cin >> v, vec.pb(v);
	
	for (int i = 0; i < n-1; i++) cin >> e[i].V >> e[i].U, e[i].ind = i, adj[e[i].V].pb(e[i].U), adj[e[i].U].pb(e[i].V);
	
	for (int i = 1; i <= n; i++) dist[i] = -1;
	
	queue <int> q;
	for (int i = 0; i < k; i++){
		v = vec[i];
		par[v] = v;
		q.push(v);
		dist[v] = 0;
	}
	
	while (q.size()){
		v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			if (dist[u] > -1) continue;
			par[u] = par[v];
			dist[u] = dist[v] + 1;
			q.push(u);
		}
	}
	//-for (int i = 1; i <= n; i++) cout << par[i] << sep;
	//cout << endl;
	
	for (int i = 0; i < n-1; i++){
		v = e[i].V;
		u = e[i].U;
		if (par[v] != par[u]) ans.pb(i+1);
	}
	
	cout << ans.size() << endl;;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << sep;
	
	cout << endl;
}