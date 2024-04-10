#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int perm[MAXN], pos[MAXN];
vector <int> adj[MAXN], ch[MAXN];
int dad[MAXN], dep[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= N; i++)
		scanf("%d", perm + i);
}

void dfs(int x, int p) {
	dad[x] = p;
	dep[x] = dep[p] + 1;
	for (auto it : adj[x])
		if (it != p) {
			ch[x].push_back(it);
			dfs(it, x);
		}
}

bool solve() {
	dfs(1, 0);

	for (int i = 1; i < N; i++)
		if (dep[perm[i]] > dep[perm[i + 1]])
			return false;
	
	for (int i = 1; i <= N; i++)
		pos[perm[i]] = i;
	
	for (int i = 1; i < N; i++)
		if (pos[dad[perm[i]]] > pos[dad[perm[i + 1]]])
			return false;
	
	for (int i = 1; i <= N; i++) {
		if (ch[i].empty())
			continue;
		int mx = 0, mn = N + 1;
		for (auto it : ch[i]) {
			mx = max(mx, pos[it]);
			mn = min(mn, pos[it]);
		}
		if (mx - mn + 1 != ch[i].size())
			return false;
	}
	
	return true;
}

int main() {
	load();
	puts(solve() ? "Yes" : "No");
	return 0;
}