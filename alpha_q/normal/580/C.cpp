#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bool vis[N];
vector <int> G[N];
int Ret = 0, C[N], m;

void DFS (int u, int cats) {
	if (vis[u]) return;
	vis[u] = 1;
	if (C[u] == 0) cats = 0;
	cats += C[u];
	if (cats > m) {
		cats--;
		return;
	}
	
	if (u != 1 && G[u].size() == 1) {
		++Ret;
		return;
	}
	
	for (int i = 0; i < G[u].size(); i++)
		DFS(G[u][i], cats);
}

int main() {
	int n; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> C[i];
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(vis, 0, sizeof vis);
	DFS(1, 0);
	cout << Ret << endl;
	return 0;
}