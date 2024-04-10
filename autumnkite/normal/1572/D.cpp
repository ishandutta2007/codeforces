#include <bits/stdc++.h>

template <class Flow, class Cost>
class mcmf_network {
public:
    typedef std::size_t size_type;

    static const Flow INF_flow = std::numeric_limits<Flow>::max();
    static const Cost INF_cost = std::numeric_limits<Cost>::max();

protected:
    struct Edge {
        size_type u, v;
        Flow flow;
        Cost cost;

        Edge(size_type _u, size_type _v, Flow _flow, Cost _cost)
        : u(_u), v(_v), flow(_flow), cost(_cost) {}
    };

    size_type n, S, T;
    std::vector<Edge> edge;
    std::vector<std::vector<size_type>> E;

    std::vector<Cost> dis;

    bool get_dis() {
        std::fill(dis.begin(), dis.end(), INF_cost);
        std::vector<bool> vis(n);
        std::vector<size_type> Q;
        dis[S] = 0;
        vis[S] = true;
        Q.push_back(S);
        for (size_type i = 0; i < Q.size(); ++i) {
            size_type u = Q[i];
            vis[u] = false;
            for (auto id : E[u]) {
                size_type v = edge[id].v;
                Flow flow = edge[id].flow;
                Cost cost = edge[id].cost;
                if (flow > 0 && dis[u] + cost < dis[v]) {
                    dis[v] = dis[u] + cost;
                    vis[v] = true;
                    Q.push_back(v);
                }
            }
        }
        return dis[T] < INF_cost;
    }

    std::vector<size_type> iter;
    std::vector<bool> vis;

    Flow dfs(size_type u, Flow all) {
        if (u == T || !all) {
            return all;
        }
        vis[u] = true;
        Flow res = 0;
        for (size_type &i = iter[u]; i < E[u].size(); ++i) {
            size_type id = E[u][i];
            size_type v = edge[id].v;
            Flow flow = edge[id].flow;
            Cost cost = edge[id].cost;
            if (!vis[v] && dis[v] == dis[u] + cost) {
                Flow tmp = dfs(v, std::min(all, flow));
                if (tmp) {
                    edge[id].flow -= tmp, edge[id ^ 1].flow += tmp;
                    res += tmp, all -= tmp;
                    if (!all) {
                        break;
                    }
                }
            }
        }
        vis[u] = false;
        if (!res) {
            dis[u] = INF_cost;
        }
        return res;
    }

public:
    mcmf_network(size_type _n) : n(_n), E(_n), dis(_n), iter(_n), vis(_n) {}

    void add_edge(size_type u, size_type v, Flow cap, Cost cost) {
        E[u].push_back(edge.size()), edge.emplace_back(u, v, cap, cost);
        E[v].push_back(edge.size()), edge.emplace_back(v, u, 0, -cost);
    }

    void slope(size_type _S, size_type _T, Flow &flow, Cost &cost) {
        std::fill(vis.begin(), vis.end(), false);
        S = _S, T = _T;
        flow = 0;
        cost = 0;
        while (get_dis()) {
            std::fill(iter.begin(), iter.end(), 0);
            Flow tmp = dfs(S, INF_flow);
            flow += tmp;
            cost += tmp * dis[T];
        }
    }

    Flow edge_flow(size_type id) {
        return edge[id << 1 | 1].flow;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    m = std::min(m, 1 << (n - 1));
    std::vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        std::cin >> a[i];
    }
    std::vector<int> id;
    std::vector<int> p(1 << n);
    std::iota(p.begin(), p.end(), 0);
    for (int k = 0; k < n; ++k) {
        std::nth_element(p.begin(), p.begin() + 2 * m - 1, p.end(),
        [&](int x, int y) {
            return a[x] + a[x ^ (1 << k)] > a[y] + a[y ^ (1 << k)];
        });
        for (int i = 0; i < 2 * m; ++i) {
            id.push_back(p[i]);
        }
    }
    std::sort(id.begin(), id.end());
    id.erase(std::unique(id.begin(), id.end()), id.end());

    std::vector<int> pos(1 << n, -1);
    for (int i = 0; i < (int)id.size(); ++i) {
        pos[id[i]] = i;
    }
    std::vector<int> par(1 << n);
    for (int i = 1; i < (1 << n); ++i) {
        par[i] = par[i >> 1] ^ (i & 1);
    }

    mcmf_network<int, int> G(id.size() + 3);
    for (int x : id) {
        if (!par[x]) {
            for (int i = 0; i < n; ++i) {
                int y = x ^ (1 << i);
                if (pos[y] != -1) {
                    G.add_edge(pos[x], pos[y], 1, -(a[x] + a[y]));
                }
            }
            G.add_edge(id.size(), pos[x], 1, 0);
        } else {
            G.add_edge(pos[x], id.size() + 1, 1, 0);
        }
    }
    G.add_edge(id.size() + 2, id.size(), m, 0);
    int flow, cost;
    G.slope(id.size() + 2, id.size() + 1, flow, cost);
    std::cout << -cost << "\n";
}