# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
vector <int> adj[xn][xn];
bool mark[xn];

void DFS(int v, int c){
	mark[v] = true;
	for (int i=0; i<adj[c][v].size(); i++){
		int u = adj[c][v][i];
		if (mark[u]) continue;
		DFS(u, c);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	int x, y, z;
	for (int i=0; i<m; i++) cin >> x >> y >> z, adj[z][x].push_back(y), adj[z][y].push_back(x);
	int q;
	cin >> q;
	for (int i=0; i<q; i++){
		int ans = 0;
		cin >> x >> y;
		for (int j=1; j<=m; j++){
			for (int k=1; k<=n; k++) mark[k] = false;
			DFS(x, j);
			if (mark[y]) ans++;
		}
		cout << ans << endl;
	}
}