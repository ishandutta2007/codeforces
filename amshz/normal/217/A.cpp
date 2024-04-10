# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
bool mark[xn];
vector <int> adj[xn];
int x[xn], y[xn];

void DFS(int v){
	mark[v] = true;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u);
	}
}

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> x[i] >> y[i];
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if (x[i] == x[j] or y[i] == y[j]) adj[i].push_back(j), adj[j].push_back(i);
	int ans = 0;
	for (int i=0; i<n; i++){
		if (!mark[i]) DFS(i), ans++;
	}
	cout << ans-1 << endl;
	return 0;
}