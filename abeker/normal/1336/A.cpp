#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N, K;
vector <int> adj[MAXN];
vector <int> diffs;

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int dfs(int node, int parent, int depth) {
	int subtree = 0;
	for (auto nxt : adj[node])
		if (nxt != parent) 
			subtree += dfs(nxt, node, depth + 1);
	diffs.push_back(depth - subtree);
	return ++subtree;
}

ll solve() {
	dfs(1, 0, 0);
	sort(diffs.begin(), diffs.end(), greater <int> ());
	ll sol = 0;
	for (int i = 0; i < K; i++)
		sol += diffs[i];
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}