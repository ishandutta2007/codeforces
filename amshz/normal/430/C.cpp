# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
bool a[xn], goal[xn], mark[xn], b[xn];
vector <int> adj[xn], ans;

void DFS(int v, int h, bool fl1, bool fl2){
	mark[v] = true;
	if (h%2 == 0){
		if (fl1) a[v] = !a[v];
		if (a[v] != goal[v]) fl1 = !fl1, ans.push_back(v); 
	}
	else{
		if (fl2) a[v] = !a[v];
		if (a[v] != goal[v]) fl2 = !fl2, ans.push_back(v);
	}
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u, h+1, fl1, fl2);
	}
}

int main(){
	int n;
	cin >> n;
	int x, y;
	for (int i=0; i<n-1; i++) cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> goal[i];
	DFS(1, 0, 0, 0);
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++) cout << ans[i] << endl;
	return 0;
}