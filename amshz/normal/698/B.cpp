# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;

vector <int> adj[xn], d[xn];
bool mark[xn], fl1, fl2;
int root = -1;
int dxd = -1;
int p[xn], e[xn], door[xn], r[xn];
map < pair <int, int> , bool> mp;

void DFS(int v, int h, int dr){
	mark[v] = true;
	e[v] = h, d[dr].push_back(v);
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (v == u) fl1 = true, root = v, dxd = dr;
		if (mark[u]) continue;
		if (mp[{v, u}]) DFS(u, h+1, dr);
		else DFS(u, h-1, dr);
	}
}

int main(){
	int n, x;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> x, adj[i+1].push_back(x), adj[x].push_back(i+1), p[i+1] = x, mp[{i+1, x}] = true;
	
	int ans = 0;
	for (int i=1; i<=n; i++){
		if (!mark[i]){
			fl1 = false;
			DFS(i, 0, ans);
			//if (fl1) d.push_back(root);
			//else d.push_back(i);
			ans++;
		}
	}
	int td = ans;
	if (root != -1) ans--;
	if (1){
		for (int i=0; i<td; i++){
			//if (i == dxd){
				
			//}
			int dx = 0;
			for (int j=1; j<d[i].size(); j++)
				if (e[d[i][j]] > e[d[i][dx]]) dx = j;
			r[i] = dx;
			if (root == -1) root = d[i][r[i]];
		}
	}
	for (int i=0; i<td; i++) p[d[i][r[i]]] = root;
	cout << ans << endl;
	for (int i=1; i<=n; i++) cout << p[i] << ' ';
	cout << endl;
	return 0;
}