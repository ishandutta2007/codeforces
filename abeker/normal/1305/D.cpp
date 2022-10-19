#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e3 + 5;

int N;
vector <int> adj[MAXN];
vector <pii> edges;
bool out[MAXN], bio[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges.push_back({u, v});
	}
}

void add_edge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void build_tree() {
	for (int i = 1; i <= N; i++)
		adj[i].clear();
	for (auto it : edges)
		if (!out[it.first] && !out[it.second])
			add_edge(it.first, it.second);
}

int query(int u, int v) {
	printf("? %d %d\n", u, v);
	fflush(stdout);
	int lca;
	scanf("%d", &lca);
	return lca;
}

void dfs(int x, int p) {
	if (out[x])
		return;
	bio[x] = true;
	for (auto it : adj[x])
		if (it != p)
			dfs(it, x);
}

int solve() {
	while (1) {
		build_tree();
		int node = 0;
		for (int i = 1; i <= N; i++)
			if (adj[i].size() >= 2) {
				node = i;
				break;
			}
		if (!node) {
			vector <int> v;
			for (int i = 1; i <= N; i++)
				if (!out[i])
					v.push_back(i);
			assert(v.size() <= 2);
			if (v.size() == 1)
				return v[0];
			return query(v[0], v[1]);
		}
		int tmp = query(adj[node][0], adj[node][1]);
		for (auto it : {node, adj[node][0], adj[node][1]})
			if (it != tmp)
				out[it] = true;
		for (int i = 1; i <= N; i++)
			bio[i] = false;
		dfs(tmp, 0);
		for (int i = 1; i <= N; i++)
			if (!bio[i])
				out[i] = true;
	}
}

int main() {
	load();
	printf("! %d\n", solve());
	fflush(stdout);
	return 0;
}