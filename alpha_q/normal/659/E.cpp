#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 50;

bool Vis[MAX];
vector <int> G[MAX];
vector <int> C[MAX];
int n, m, num = 0, Ret = 0;

void DFS (int u) {
	if (Vis[u]) return;
	Vis[u] = 1, C[num].push_back(u);
	for (int v = 0; v < G[u].size(); v++)
		DFS(G[u][v]);
}

int main() {
	scanf("%d %d", &n, &m); while (m--) {
		int u, v; scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) if (!Vis[i]) num++, DFS(i);

	for (int i = 1; i <= num; i++) {
		int tmp = 0, nn = C[i].size();
		for (int u = 0; u < nn; u++) tmp += G[C[i][u]].size();
		tmp /= 2;
		if (tmp == nn - 1) Ret++;
	}

	printf("%d\n", Ret);
	return 0;
}