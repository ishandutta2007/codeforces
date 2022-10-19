/*input
3 1 3 4 5
URU
B
2 1
1 1
3 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

using namespace std;

const int INF = 2e9, COMP = 40004;

struct MCMF
{
	struct Edge
	{
		int v, c, w;
		Edge (int _v = 0, int _c = 0, int _w = 0): v(_v), c(_c), w(_w) {}
	};
	int n, s, t;
	vector<Edge> edges;
	vector<int> prv, dist, inq;
	vector<vector<int>> adj;

	MCMF(int _n = 0, int _s = 0, int _t = 0)
	{
		n = _n, s = _s, t = _t;
		adj.resize(n);
		prv.resize(n);
		dist.resize(n);
		inq.resize(n);
	}

	void add_edge(int u, int v, int c, int w)
	{
		adj[u].emplace_back(edges.size());
		edges.emplace_back(v, c, w);
		adj[v].emplace_back(edges.size());
		edges.emplace_back(u, 0, -w);
	}

	int run()
	{
		queue<int> qu;
		int total_flow = 0, total_cost = 0;

		while (true) {
			fill(dist.begin(), dist.end(), INF);
			fill(inq.begin(), inq.end(), 0);
			dist[s] = 0;
			while (!qu.empty()) qu.pop();
			qu.push(s);
			inq[s] = 0;

			while (!qu.empty()) {
				int u = qu.front();
				inq[u] = 0;
				qu.pop();

				for (int id : adj[u]) {
					auto e = edges[id];
					if (e.c && dist[u] + e.w < dist[e.v]) {
						dist[e.v] = dist[u] + e.w;
						prv[e.v] = id;
						if (!inq[e.v]) {
							inq[e.v] = 1;
							qu.push(e.v);
						}
					}
				}
			}

			if (dist[t] >= 0) {
				return total_cost;
			}

			int f = INF;
			for (int u = t; u != s; u = edges[prv[u] ^ 1].v) {
				f = min(f, edges[prv[u]].c);
			}

			total_cost += dist[t] * f;
			for (int u = t; u != s; u = edges[prv[u] ^ 1].v) {
				edges[prv[u]].c -= f;
				edges[prv[u] ^ 1].c += f;
			}
		}
	}
};

int main()
{
	int n1, n2, m, r, b;
	cin >> n1 >> n2 >> m >> r >> b;
	string col1, col2;
	cin >> col1 >> col2;
	string col = "-" + col1 + col2;
	vector<pair<int, int>> edges(m);
	for (auto &e : edges) {
		cin >> e.first >> e.second;
		e.second += n1;
	}

	int s = 0, t = n1 + n2 + 1;
	int c = m + 2;

	MCMF mcmf(t + 1, 0, t);
	for (auto &e : edges) {
		mcmf.add_edge(e.first, e.second, 1, r);
		mcmf.add_edge(e.second, e.first, 1, b);
	}

	int num_colored = 0;
	for (int u = 1; u <= n1; ++u) {
		if (col[u] == 'R') {
			mcmf.add_edge(s, u, 1, -COMP);
			mcmf.add_edge(s, u, c, 0);
			++num_colored;
		} else if (col[u] == 'B') {
			mcmf.add_edge(u, t, 1, -COMP);
			mcmf.add_edge(u, t, c, 0);
			++num_colored;
		} else {
			mcmf.add_edge(s, u, c, 0);
			mcmf.add_edge(u, t, c, 0);
		}
	}

	for (int u = n1 + 1; u <= n1 + n2; ++u) {
		if (col[u] == 'B') {
			mcmf.add_edge(s, u, 1, -COMP);
			mcmf.add_edge(s, u, c, 0);
			++num_colored;
		} else if (col[u] == 'R') {
			mcmf.add_edge(u, t, 1, -COMP);
			mcmf.add_edge(u, t, c, 0);
			++num_colored;
		} else {
			mcmf.add_edge(s, u, c, 0);
			mcmf.add_edge(u, t, c, 0);
		}
	}

	int total_cost = mcmf.run() + num_colored * COMP;
	if (total_cost >= COMP) return cout << -1 << endl, 0;
	cout << total_cost << endl;
	for (int i = 0; i < m; ++i) {
		if (mcmf.edges[i * 4].c == 0) {
			cout << 'R';
		} else if (mcmf.edges[i * 4 + 2].c == 0) {
			cout << 'B';
		} else {
			cout << 'U';
		}
	}
}