#include <bits/stdc++.h>

template <class Flow>
class mf_network {
public:
    typedef std::size_t size_type;

    static const Flow INF_flow = std::numeric_limits<Flow>::max();

protected:
    struct edge {
        size_type u, v;
        Flow flow;

        edge(size_type _u, size_type _v, Flow _flow)
        : u(_u), v(_v), flow(_flow) {}
    };

	static const size_type npos = static_cast<size_type>(-1);

	size_type n, S, T;
	std::vector<edge> edges;
	std::vector<std::vector<size_type>> E;

	std::vector<size_type> dep;

	bool bfs() {
		std::fill(dep.begin(), dep.end(), npos);
		std::vector<size_type> Q;
		dep[S] = 0;
		Q.push_back(S);
		if (S == T) {
			return true;
		}
		for (size_type i = 0; i < Q.size(); ++i) {
			size_type u = Q[i];
			for (size_type id : E[u]) {
				size_type v = edges[id].v;
				Flow flow = edges[id].flow;
				if (flow && dep[v] == npos) {
					dep[v] = dep[u] + 1;
					Q.push_back(v);
					if (v == T) {
						return true;
					}
				}
			}
		}
		return false;
	}

	std::vector<size_type> iter;

	Flow dfs(size_type u, Flow all) {
		if (u == T || !all) {
			return all;
		}
		Flow res = 0;
		for (size_type &i = iter[u]; i < E[u].size(); ++i) {
			size_type id = E[u][i];
			size_type v = edges[id].v;
			Flow flow = edges[id].flow;
			if (dep[v] == dep[u] + 1) {
				Flow tmp = dfs(v, std::min(all, flow));
				if (tmp) {
					edges[id].flow -= tmp, edges[id ^ 1].flow += tmp;
					res += tmp, all -= tmp;
					if (!all) {
						break;
					}
				}
			}
		}
		if (!res) {
			dep[u] = npos;
		}
		return res;
	}

public:
	mf_network(size_type _n) : n(_n), E(_n), dep(_n), iter(_n) {}

	void add_edge(size_type u, size_type v, Flow c) {
		E[u].push_back(edges.size()), edges.emplace_back(u, v, c);
		E[v].push_back(edges.size()), edges.emplace_back(v, u, 0);
	}

	size_type edge_size() {
		return edges.size() >> 1;
	}

	void slope(size_type _S, size_type _T, Flow &flow) {
		S = _S, T = _T;
		flow = 0;
		while (bfs()) {
			std::fill(iter.begin(), iter.end(), 0);
			flow += dfs(S, INF_flow);
		}
	}

	Flow edge_flow(size_type id) {
		return edges[id << 1 | 1].flow;
	}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] ^= s[j] == 'B';
            if (i) {
                a[i - 1][j] ^= s[j] == 'B';
            }
            if (j) {
                a[i][j - 1] ^= s[j] == 'B';
            }
            if (i && j) {
                a[i - 1][j - 1] ^= s[j] == 'B';
            }
        }
    }

    int sum = std::accumulate(a.begin(), a.end(), 0, 
    [&](int a, const std::vector<int> &b) {
        return std::accumulate(b.begin(), b.end(), a);
    });

    mf_network<int> G(n + m);
    int S = n + m - 2, T = n + m - 1;
    for (int i = 0; i < n - 1; ++i) {
        G.add_edge(S, i, a[i][m - 1]);
    }
    for (int i = 0; i < m - 1; ++i) {
        G.add_edge(n - 1 + i, T, a[n - 1][i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            G.add_edge(i, n - 1 + j, a[i][j]);
        }
    }
    int flow;
    G.slope(S, T, flow);
    sum -= a[n - 1][m - 1];
    sum += a[n - 1][m - 1] ^ (flow & 1);
    std::cout << sum - flow << "\n";
}