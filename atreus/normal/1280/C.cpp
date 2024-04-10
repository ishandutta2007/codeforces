#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

vector<pair<int, int> > g[maxn];
ll G, B;
int n, sz[maxn];

void dfs(int v, int par = -1, int x = 0){
	sz[v] = 1;
	for (auto e : g[v]){
		int u = e.first, w = e.second;
		if (u != par){
			dfs(u, v, w);
			sz[v] += sz[u];
		}
	}
	if (par != -1){
		if (sz[v] & 1)
			G += x;
		B += 1ll * min(sz[v], n - sz[v]) * x;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		cin >> n;
		n = 2 * n;
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 0; i < n - 1; i++){
			int v, u, t;
			cin >> v >> u >> t;
			g[v].push_back({u, t});
			g[u].push_back({v, t});
		}
		G = 0, B = 0;
		dfs(1);
		cout << G << " " << B << endl;
	}
}