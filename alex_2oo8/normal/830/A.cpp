#include <bits/stdc++.h>

using namespace std;

const int LEFT = 1000, RIGHT = 2000;

vector<int> G[LEFT];
int paired[LEFT], parent[RIGHT];
bool used[LEFT];

bool dfs(int v) {
	if (used[v]) return false;
	used[v] = true;
	for (int u : G[v])
		if (parent[u] == -1 || dfs(parent[u])) {
			paired[v] = u;
			parent[u] = v;
			return true;
		}
	return false;
}

int bipartite_matching(int left, int right) {
	memset(paired, -1, sizeof(int) * left);
	memset(parent, -1, sizeof(int) * right);
	bool run = true;
	int size = 0;
	while (run) {
		memset(used, 0, sizeof(bool) * left);
		run = false;
		for (int i = 0; i < left; i++)
			if (paired[i] == -1 && dfs(i)) {
				size++;
				run = true;
			}
	}
	return size;
}

const int MX = 2000;

int a[MX], b[MX], n, k, p;

bool check(int t) {
	for (int i = 0; i < n; i++) {
		G[i].clear();
		for (int j = 0; j < k; j++)
			if (abs(a[i] - b[j]) + abs(b[j] - p) <= t)
				G[i].push_back(j);
	}
	
	return bipartite_matching(n, k) == n;
}

int main() {
	ignore = scanf("%d %d %d", &n, &k, &p);
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	for (int i = 0; i < k; i++) ignore = scanf("%d", b + i);
	
	int ans = -1;
	for (int p = (1 << 30); p > 0; p /= 2)
		if (check(ans + p) == false)
			ans += p;
	
	printf("%d\n", ans + 1);
	
	return 0;
}