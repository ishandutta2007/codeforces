# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;

vector <int> a[xn];
vector <int> adj[xn];
vector <int> team[xn];
bool mark[xn], f[xn];

void DFS(int v){
	for (int i=0; i<a[v].size(); i++) f[a[v][i]] = true;
	mark[v] = true;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u);
	}
}

int main(){
	int x;
	int n, m;
	cin >> n >> m;
	int s = 0;
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		s += t;
		for (int j=0; j<t; j++) cin >> x, a[i].push_back(x);
	}
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			for (int k1=0; k1<a[i].size(); k1++){
				for (int k2=0; k2<a[j].size(); k2++){
					if (a[i][k1] == a[j][k2]) adj[i].push_back(j), adj[j].push_back(i);
				}
			}
		}
	}
	int ans = 0;
	for (int i=0; i<n; i++){
		if (!mark[i]){
			ans++;
			for (int j=1; j<=m; j++) f[j] = false;
			DFS(i);
			for (int j=1; j<=m; j++) if (f[j]) team[ans-1].push_back(j);
		}
	}
	if (s == 0) ans++;
	cout << ans-1 << endl;
	return 0;
}