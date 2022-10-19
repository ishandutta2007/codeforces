#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int64_t INF = 1e15;

struct Dinic {
	struct Edge {
		int v;
		int64_t f, c;
		Edge(int _v = 0, int64_t _f = 0, int64_t _c = 0): v(_v), f(_f), c(_c) {};
	};

	int n;
	vector<int> idx, dep, qu;
	vector<vector<int>> adj;
	vector<Edge> edges;

	Dinic(int _n): n(_n), idx(_n), dep(_n), adj(_n), edges(0) {}

	void addEdge(int u, int v, int64_t c) {
		adj[u].push_back((int) edges.size());
		edges.emplace_back(v, 0, c);
		adj[v].push_back((int) edges.size());
		edges.emplace_back(u, 0, 0);
	}

	bool levelGraph(int s, int t) {
		qu.clear();
		fill(dep.begin(), dep.end(), n + 1);
		fill(idx.begin(), idx.end(), 0);

		qu.push_back(s);
		dep[s] = 0;
		for (int qi = 0; qi < (int) qu.size() && qu.back() != t; ++qi) {
			int u = qu[qi];
			for (int i : adj[u]) {
				auto &e = edges[i];
				if (e.f < e.c && dep[u] + 1 < dep[e.v]) {
					dep[e.v] = dep[u] + 1;
					qu.push_back(e.v);
				}
			}
		}
		return dep[t] <= n;
	}

	int64_t sendFlow(int u, int t, int64_t f) {
		if (u == t) return f;
		for (int &i = idx[u]; i < (int) adj[u].size(); ++i) {
			auto &e = edges[adj[u][i]];
			if (e.f < e.c && dep[u] + 1 == dep[e.v]) {
				int64_t g = sendFlow(e.v, t, min(f, e.c - e.f));
				if (g > 0) {
					edges[adj[u][i]].f += g;
					edges[adj[u][i] ^ 1].f -= g;
					return g;	
				}
			}
		}
		return 0;
	}

	int64_t maxFlow(int s, int t) {
		while (levelGraph(s, t)) {
			while (sendFlow(s, t, INF));
		}

		int64_t flow = 0;
		for (int i : adj[s]) {
			flow += edges[i].f;
		}
		return flow;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	map<pair<int, int>, int> a;
	auto get = [&](int x, int y) {
		auto it = a.find(make_pair(x, y));
		return (it == a.end() ? -1 : it->second);
	};

	cin >> n;
	Dinic dinic(n * 2 + 2);
	int s = n * 2, t = n * 2 + 1;
	int64_t total = 0;
	for (int i = 0; i < n; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		dinic.addEdge(2 * i, 2 * i + 1, w);
		total += w;

		a[make_pair(x, y)] = i;
	}

	for (auto rit = a.begin(); rit != a.end(); ++rit) {
		int x = rit->first.first, y = rit->first.second, i = rit->second, j;

		if (x % 2 == 0 && y % 2 == 0) {
			for (int y0 = y - 1; y0 <= y + 1; y0 += 2) {
				if (~(j = get(x, y0))) dinic.addEdge(2 * i + 1, 2 * j, INF);
			}
			for (int x0 = x - 1; x0 <= x + 1; x0 += 2) {
				if (~(j = get(x0, y))) dinic.addEdge(2 * j + 1, 2 * i, INF);
			}
		} else if (x % 2 == 0) {
			for (int x0 = x - 1; x0 <= x + 1; x0 += 2) {
				if (~(j = get(x0, y))) dinic.addEdge(2 * i + 1, 2 * j, INF);
			}
		} else if (y % 2 == 0) {
			dinic.addEdge(s, 2 * i, INF);
		} else {
			dinic.addEdge(2 * i + 1, t, INF);
		}
	}

	cout << total - dinic.maxFlow(s, t) << endl;
}