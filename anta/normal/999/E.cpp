#include "bits/stdc++.h"
using namespace std;

class StronglyConnectedComponents {
public:
	typedef vector<vector<int>> Graph;

	int run(const Graph &graph) {
		int n = (int)graph.size();
		stack.resize(n);
		S.resize(n);
		B.resize(n);
		I.assign(n, 0);
		int sp = 0, topS = 0, topB = 0, c = n;
		for (int start = 0; start < n; ++ start) if (I[start] == 0) {
			stack[sp ++] = make_pair(start, 0);
			for (; sp != 0; ) {
				int u, ei;
				tie(u, ei) = stack[-- sp];
				if (ei == 0) {
					S[topS ++] = u;
					B[topB ++] = I[u] = topS;
				}
				if (ei != graph[u].size()) {
					stack[sp ++] = make_pair(u, ei + 1);
					int v = graph[u][ei];
					if (I[v] == 0) {
						stack[sp ++] = make_pair(v, 0);
					} else {
						while (I[v] < B[topB - 1])
							-- topB;
					}
				} else if (I[u] == B[topB - 1]) {
					-- topB, ++ c;
					while (I[u] <= topS)
						I[S[-- topS]] = c;
				}
			}
		}
		for (int u = 0; u < n; ++ u)
			I[u] -= n + 1;
		return c - n;
	}

	int getColor(int u) const {
		return I[u];
	}

private:
	vector<pair<int, int>> stack;
	vector<int> S, B, I;
};

int main() {
	int n; int m; int s;
	while (~scanf("%d%d%d", &n, &m, &s)) {
		-- s;
		vector<vector<int> > g(n);
		for (int i = 0; i < m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
		}
		StronglyConnectedComponents scc;
		int S = scc.run(g);
		vector<int> deg(S, 0);
		for (int i = 0; i < n; ++ i) for (int j : g[i]) if (scc.getColor(i) != scc.getColor(j))
			++ deg[scc.getColor(j)];
		++ deg[scc.getColor(s)];
		int ans = 0;
		for (int u = 0; u < S; ++ u)
			ans += deg[u] == 0;
		printf("%d\n", ans);
	}
}