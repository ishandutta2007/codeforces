#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N, K, L;
vector <int> adj[MAXN];
bool my[MAXN];
int his[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		adj[i].clear();
	memset(my, false, sizeof my);
	for (int i = 1; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	scanf("%d", &K);
	while (K--) {
		int x;
		scanf("%d", &x);
		my[x] = true;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++)
		scanf("%d", his + i);
}

int ask(char c, int x) {
	printf("%c %d\n", c, x);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

int dfs(int x, int p) {
	if (my[x])
		return x;
	for (auto it : adj[x])
		if (it != p) {
			int tmp = dfs(it, x);
			if (tmp != -1)
				return tmp;
		}
	return -1;
}

void solve() {
	int node = ask('B', his[0]);
	if (my[node]) {
		printf("C %d\n", node);
		fflush(stdout);
		return;
	}
	
	int nxt = dfs(node, 0);
	int curr = ask('A', nxt);
	
	for (int i = 0; i < L; i++)
		if (his[i] == curr) {
			printf("C %d\n", nxt);
			fflush(stdout);
			return;
		}
	
	puts("C -1");
	fflush(stdout);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}