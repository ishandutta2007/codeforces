#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int INF = 1e9;

int N, M, K;
int spec[MAXN];
vector <int> adj[MAXN];
int st[MAXN], en[MAXN];
int mx1[MAXN], mx2[MAXN];

void load() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; i++)
		scanf("%d", spec + i);
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void bfs(int src, int dist[MAXN]) {
	for (int i = 1; i <= N; i++)
		dist[i] = -1;
	queue <int> Q;
	Q.push(src);
	dist[src] = 0;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (auto it : adj[x])
			if (dist[it] == -1) {
				dist[it] = dist[x] + 1;
				Q.push(it);
			}
	}
}

bool check(int d) {
	for (int i = 0; i < K; i++) {
		int lo = max(d - 1 - en[spec[i]], 0);
		int best = mx1[lo];
		if (en[spec[i]] == best && st[spec[i]] + en[spec[i]] >= d - 1)
			best = mx2[lo];
		if (best >= d - 1 - st[spec[i]])
			return true;
	}
	return false;
}

void update(int x, int val) {
	if (val >= mx1[x]) {
		mx2[x] = mx1[x];
		mx1[x] = val;
	}
	else if (val > mx2[x])
		mx2[x] = val;
}

int solve() {
	bfs(1, st);
	bfs(N, en);
	
	for (int i = 0; i <= N; i++)
		mx1[i] = mx2[i] = -INF;
		
	for (int i = 0; i < K; i++)
		update(st[spec[i]], en[spec[i]]);
	
	for (int i = N - 1; i >= 0; i--) {
		update(i, mx1[i + 1]);
		update(i, mx2[i + 1]);
	}
	
	int lo = 0, hi = N;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
		
	return min(st[N], lo);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}