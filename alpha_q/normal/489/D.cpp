#include <bits/stdc++.h>

using namespace std;

const int MAX = 3050;

bool vis[MAX];
vector <int> G[MAX];
int n, m, u, v; 
long long ret = 0, cnt[MAX];

void DFS (int c, int step) {
	if (step == 2) {
		cnt[c]++;
		return;
	} 
	if (vis[c]) return;
	vis[c] = 1;
	for (int d = 0; d < G[c].size(); d++)
		DFS(G[c][d], step + 1);
}

int main() {	
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m); while (m--) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		memset(cnt, 0, sizeof cnt);
		DFS(i, 0); 
		for (int j = 1; j <= n; j++) if (j != i) ret += cnt[j] * (cnt[j] - 1) / 2;
	}

	printf("%I64d\n", ret);
    return 0;
}