#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 3e3 + 5;

int N;
vector <int> adj[MAXN];
int sub[MAXN][MAXN];
ll dp[2 * MAXN][2 * MAXN];
vector <pii> edges;
int idx[MAXN][MAXN];

void add_edge(int u, int v) {
	adj[u].push_back(v);
	idx[u][v] = edges.size();
	edges.push_back({u, v});
}

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
}

int calc_sub(int x, int p, int root) {
	sub[root][x] = 1;
	for (auto it : adj[x])
		if (it != p)
			sub[root][x] += calc_sub(it, x, root);
	return sub[root][x];
}

ll rec(int l, int r) {
	ll &ref = dp[l][r];
	if (ref != -1)
		return ref;
	ref = 0;
	int a = edges[l].second;
	int b = edges[r].second;
	int pa = edges[l].first;
	int pb = edges[r].first;
	for (auto it : adj[a])
		if (it != pa)
			ref = max(ref, rec(idx[a][it], r));
	for (auto it : adj[b])
		if (it != pb)
			ref = max(ref, rec(l, idx[b][it]));
	ref += sub[pa][a] * sub[pb][b];
	return ref;
}

ll solve() {
	memset(dp, -1, sizeof dp);
	
	for (int i = 1; i <= N; i++)
		calc_sub(i, 0, i);
		
	ll sol = 0;
	for (auto it : edges)
		sol = max(sol, rec(idx[it.first][it.second], idx[it.second][it.first]));
		
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}