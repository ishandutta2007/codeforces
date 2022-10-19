#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N, M, S;
bool can[MAXN];
ll dp[MAXN][2];
int score[MAXN];
int a[MAXN], b[MAXN];
vector <pii> adj[MAXN];
vector <int> tree[MAXN];
int disc[MAXN], low[MAXN];
bool bridge[MAXN];
int comp[MAXN];
ll cost[MAXN];
int sz[MAXN];
int timer;

void add_edge(int i) {
	adj[a[i]].push_back({b[i], i});
	adj[b[i]].push_back({a[i], i});
}

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", score + i);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", a + i, b + i);
		add_edge(i);
	}
	scanf("%d", &S);
}

void dfs(int x, int p) {
	disc[x] = low[x] = ++timer;
	for (auto it : adj[x])
		if (!disc[it.first]) {
			dfs(it.first, x);
			low[x] = min(low[x], low[it.first]);
			if (low[it.first] == disc[it.first])
				bridge[it.second] = true;
		}
		else if (it.first != p)
			low[x] = min(low[x], disc[it.first]);
}

void go(int x, int c) {
	comp[x] = c;
	cost[c] += score[x];
	sz[c]++;
	for (auto it : adj[x])
		if (!comp[it.first])
			go(it.first, c);
}

void add_tree(int u, int v) {
	tree[u].push_back(v);
	tree[v].push_back(u);
}

ll calc(int x, int p) {
	ll best = 0;
	dp[x][1] = cost[x];
	can[x] = sz[x] > 1;
	for (auto it : tree[x])
		if (it != p) {
			calc(it, x);
			dp[x][0] += dp[it][0];
			dp[x][1] += dp[it][0];
			best = max(best, dp[it][1] - dp[it][0]);
			can[x] |= can[it];
		}
	if (can[x])
		dp[x][0] += cost[x];
	dp[x][1] += best;
	
	return dp[x][1];
}

ll solve() {
	dfs(1, 0);
	
	for (int i = 1; i <= N; i++)
		adj[i].clear();
		
	for (int i = 0; i < M; i++)
		if (!bridge[i])
			add_edge(i);
	
	int curr = 0;
	for (int i = 1; i <= N; i++)
		if (!comp[i])
			go(i, ++curr);
	
	for (int i = 0; i < M; i++)
		if (bridge[i]) 
			add_tree(comp[a[i]], comp[b[i]]);
	
	return calc(comp[S], 0);
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}