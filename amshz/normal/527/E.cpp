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
const int xn = 1e5+10;
const int xm = 2e5+10;

int n, m, d[xn], in[xn], out[xn], ind, pnt[xn];
vector <int> adj[xn], tour, part;
bool mark[xn];
map <pii, int> vis;

void DFS(int v){
	while (pnt[v] < adj[v].size()){
		int i = pnt[v];
		pnt[v]++;
		int u = adj[v][i];
		if (vis[{v, u}] == 0) continue;
		vis[{v, u}]--, vis[{u, v}]--;
		if (v == u) vis[{v, u}]++;
		
		DFS(u);
	}
	tour.pb(v);
	part.pb(0);
}


int main(){
	//fast_io;
	
	cin >> n >> m;
	
	
	int x, y;
	for (int i=0; i<m; i++){
		cin >> x >> y;
		if (x == y){
			d[x] += 2;
			adj[x].pb(y);
			vis[{x, y}]++;
			continue;
		}
		d[x]++, d[y]++;
		adj[x].pb(y), adj[y].pb(x);
		vis[{x, y}]++, vis[{y, x}]++;
	}
	
	int dx = -1;
	//cout << endl;
	for (int i=1; i<=n; i++){
		//cout << d[i] << sep;
		if (d[i]%2 == 0) continue;
		if (dx == -1) dx = i;
		else{
			//cout << dx << sep << i << endl;
			adj[i].pb(dx), adj[dx].pb(i), d[i]++, d[dx]++;
			int v = dx, u = i;
			vis[{v, u}]++, vis[{u, v}]++;
			dx = -1;
		}
	}
	//cout << endl;
	//cout << "residam" << endl;
	for (int v=1; v<=n; v++){
		for (int i=0; i<adj[v].size(); i++){
			int u = adj[v][i];
			//if (v == 1) cout << u << endl;
			if (u > v) continue;
			//if (u == 1) cout << v << endl;
			in[u]++, out[v]++;
		}
	}
	//for (int i=1; i<=n; i++) cout << i << " : " << in[i] << endl;
	dx = 0;
	for (int i=1; i<=n; i++){
		if (d[i]){
			dx = i;
			break;
		}
	}
	//cout << "reex" << endl;
	DFS(dx);
	dx = -1;
	int lv;
	for (int i=0; i<tour.size(); i++){
		//cout << tour[i] << sep;
		int v = tour[i];
		if (in[v]%2 == 0 || v == dx) continue;
		if (dx == -1){
			dx = v, lv = i;
		}
		else{
			//cout << dx << sep << v << endl;
			part[lv]++, part[i]--;
			in[dx]++, in[v]++;
			dx = -1;
		}
	}
	//cout << endl;
	int p = tour.size()-1, s = 0;
	if (dx != -1) adj[dx].pb(dx), d[dx]++, p++;
	
	cout << p << endl;
	for (int i=0; i<tour.size()-1; i++){
		s += part[i];
		int v = tour[i], u = tour[i+1];
		if (u > v) swap(v, u);
		if (s%2) swap(v, u);
		
		cout << v << sep << u << endl;
	}
	if (dx != -1) cout << dx << sep << dx << endl;
	
	return 0;
}
/*
10 20
1 2
1 3
3 4
1 5
2 6
3 7
3 8
5 9
7 10
2 5
5 2
4 7
6 2
2 8
7 7
9 8
1 9
6 10
8 8
6 10
*/