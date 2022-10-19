#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1007;
int N, M;
vector<int> G[MAXN];
int qu[MAXN], fr, rr, dist[MAXN], len[MAXN];

int dsu[MAXN];
int get(int u) { return (dsu[u] < 0 ? u : dsu[u] = get(dsu[u])); }
void join(int u, int v)
{
	u = get(u), v = get(v);
	if (u == v) return;
	if (dsu[u] > dsu[v]) swap(u, v);
	dsu[u] += dsu[v], dsu[v] = u;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	memset(dsu + 1, -1, sizeof(dsu[0]) * N);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		join(u, v);
	}
	for (int r = 1; r <= N; ++r) {
		for (int u = 1; u <= N; ++u) dist[u] = MAXN;
		fr = rr = 0;
		dist[qu[++rr] = r] = 0;
		while (fr < rr) {
			int u = qu[++fr];
			for (int v : G[u]) {
				if (dist[u] == dist[v]) return cout << -1 << endl, 0;
				if (dist[v] > dist[u] + 1) dist[qu[++rr] = v] = dist[u] + 1;
			}
		}
		int cur = 0;
		for (int u = 1; u <= N; ++u) if (dist[u] != MAXN) cur = max(cur, dist[u]);
		len[get(r)] = max(len[get(r)], cur);
	}

	int ans = 0;
	for (int u = 1; u <= N; ++u) if (u == get(u)) ans += len[u];
	cout << ans << endl;
}