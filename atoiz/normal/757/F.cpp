/*input
4 4 1
1 2 4
2 3 5
3 4 9
2 4 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

struct Path
{
	long long w;
	int v;
	Path(long long _w, int _v): w(_w), v(_v) {}
	bool operator< (const Path p) const { return w > p.w; }
};

const int MAXN = 200007, LOG = 19;
const long long INF = 1e17;
int N, M, S;
vector<Path> G[MAXN];
long long dist[MAXN];
priority_queue<Path> pq;

vector<int> tree[MAXN], prv[MAXN];
int dep[MAXN], anc[LOG][MAXN], des[MAXN];

void initAnc(int u) { for (int i = 1; i < LOG; ++i) anc[i][u] = anc[i - 1][anc[i - 1][u]]; }
int getLca(int u, int v) 
{
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = LOG - 1; i >= 0; --i) if (dep[v] + (1 << i) <= dep[u]) u = anc[i][u];
	if (u == v) return u;
	for (int i = LOG - 1; i >= 0; --i) if (anc[i][u] != anc[i][v]) u = anc[i][u], v = anc[i][v];
	return anc[0][u];
}

int dfs(int u)
{
	for (auto v : tree[u]) des[u] += dfs(v);
	return ++des[u];
}

int main()
{
	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < M; ++i) {
		int u, v; long long w;
		scanf("%d %d %I64d", &u, &v, &w);
		G[u].emplace_back(w, v);
		G[v].emplace_back(w, u);
	}

	for (int u = 1; u <= N; ++u) dist[u] = INF; pq.emplace(dist[S] = 0, S);
	while (!pq.empty()) {
		int u = pq.top().v;
		long long w = pq.top().w;
		pq.pop();
		if (dist[u] != w) continue;

		if (u != S) {
			int &par = anc[0][u] = prv[u][0];
			for (auto v : prv[u]) par = getLca(par, v);
			initAnc(u);
			dep[u] = dep[par] + 1;
			tree[par].push_back(u);
		}

		for (auto p : G[u]) {
			long long w0 = w + p.w;
			int v = p.v;
			if (w0 < dist[v]) {
				prv[v] = {u};
				pq.emplace(dist[v] = w0, v);	
			} else if (w0 == dist[v]) prv[v].push_back(u);
		}
	}


	int ans = 0;
	dfs(S);
	for (int u = 1; u <= N; ++u) if (u != S) ans = max(ans, des[u]);
	printf("%d", ans);
}