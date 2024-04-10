#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define pb emplace_back
#define mp make_pair

typedef long long ll;
typedef double lf;

const int inf = 1e9;
const int maxn = 600, maxk = 200;

struct edge {
	int to, w;

	edge(int to, int w): to(to), w(w) {}
};

#define tm lijwerferlkjre

int n, m, k, r;
int start[maxk];
vector<edge> graph[maxn];
int dist[maxk][maxn], used[maxn], to[maxn];
vector<int> g[maxk];
int tm;

bool go(int v) {
	if (used[v] == tm) return false;
	//cerr << "go " << v << endl;
	used[v] = tm;
	for (int u : g[v]) {
		if (to[u] == -1 || go(to[u])) {
			to[u] = v;
			return true;
		}
	}
	return false;
}

bool check(int T) {
	//cerr << "check " << T << endl;
	for (int i = 0; i < k; ++i) {
		g[i].clear();
		//cerr << i << ": ";
		for (int j = 0; j < n; ++j) {
			if (dist[i][j] <= T) {
				g[i].pb(j);
				//cerr << j << " ";
			}
		}
		//cerr << endl;
	}
	fill(to, to + n, -1);
	fill(used, used + n, 0);
	tm = 0;
	int cnt = 0;
	for (int i = 0; i < k; ++i) {
		++tm;
		if (go(i)) ++cnt;
	}
	//cerr << "match " << cnt << endl;
	return cnt >= r;
}

void dijkstra(int s, int *dist) {
	fill(dist, dist + n, inf);
	fill(used, used + n, 0);
	dist[s] = 0;
	for (int it = 0; it < n; ++it) {
		int v = -1;
		for (int i = 0; i < n; ++i) {
			if (used[i]) continue;
			if (v == -1 || dist[i] < dist[v]) v = i;
		}
		if (v == -1) break;
		used[v] = 1;
		for (const auto &e: graph[v]) {
			dist[e.to] = min(dist[e.to], dist[v] + e.w);
		}
	}
}

int main() {
	srand(131);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k >> r;
	for (int i = 0; i < k; ++i) {
		cin >> start[i];
		--start[i];
	}
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		graph[u].pb(v, w);
		graph[v].pb(u, w);
	}
	for (int i = 0; i < k; ++i) {
		dijkstra(start[i], dist[i]);
	}
	int left = 0, right = 1731312;
	while (left < right) {
		int m = (left + right) / 2;
		if (check(m)) right = m;
		else left = m + 1;
	}
	cout << (left > 1731311 ? -1 : left) << endl;
	return 0;
}