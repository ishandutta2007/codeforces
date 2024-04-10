#include <algorithm>
#include <iostream>
#include <vector>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#include <optional>

namespace suisen {
    struct UndirectedEulerianGraph {
        UndirectedEulerianGraph() {}
        UndirectedEulerianGraph(int n) : n(n), g(n), inv(n) {}

        void add_edge(int u, int v) {
            const int su = g[u].size();
            g[u].push_back(v);
            const int sv = g[v].size();
            g[v].push_back(u);
            inv[u].push_back(sv);
            inv[v].push_back(su);
        }

        std::optional<std::vector<int>> eulerian_circuit(int start = 0) {
            std::size_t edge_num = 0;
            std::vector<std::vector<bool>> used(n);
            for (int i = 0; i < n; ++i) {
                const std::size_t sz = g[i].size();
                edge_num += sz;
                used[i].resize(sz, false);
                if (sz & 1) return std::nullopt;
            }
            edge_num /= 2;
            std::vector<int> res;
            auto dfs = [&](auto dfs, int u) -> void {
                for (std::size_t i = 0; i < g[u].size(); ++i) {
                    if (used[u][i]) continue;
                    const int v = g[u][i];
                    used[u][i] = true;
                    assert(not used[v][inv[u][i]]);
                    used[v][inv[u][i]] = true;
                    dfs(dfs, v);
                }
                res.push_back(u);
            };
            dfs(dfs, start);
            if (res.size() != edge_num + 1) return std::nullopt;
            return res;
        }
        std::optional<std::vector<int>> eulerian_trail() {
            int s = -1, t = -1, invalid = -1;
            for (int i = 0; i < n; ++i) if (g[i].size() & 1) (s < 0 ? s : t < 0 ? t : invalid) = i;
            if (s < 0 or t < 0 or invalid >= 0) return std::nullopt;
            add_edge(s, t);
            auto opt_res = eulerian_circuit(s);
            if (not opt_res.has_value()) return std::nullopt;
            auto res = *opt_res;
            res.pop_back();
            // remove edge (s, t)
            g[s].pop_back(), inv[s].pop_back();
            g[t].pop_back(), inv[t].pop_back();
            if (res.back() == t) return res;
            auto is_st_edge = [&](int u, int v) {
                return (u == s and v == t) or (u == t and v == s);
            };
            std::rotate(res.begin(), std::adjacent_find(res.begin(), res.end(), is_st_edge) + 1, res.end());
            return res;
        }
        
        const std::vector<int>& operator[](int u) const {
            return g[u];
        }
        std::pair<int, int> rev_edge(int u, int i) const {
            return { g[u][i], inv[u][i] };
        }
    private:
        int n;
        std::vector<std::vector<int>> g;
        std::vector<std::vector<int>> inv;

    };
}

using suisen::UndirectedEulerianGraph;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto out = [&](const std::vector<int>& ans) {
        int k = ans.size();
        std::cout << k << '\n';
        for (int i = 0; i < k; ++i) {
            if (ans[i] == -1) {
                std::cout << -1;
            } else {
                std::cout << ans[i] + 1;
            }
            if (i + 1 < k) std::cout << ' ';
        }
        std::cout << '\n';
        exit(0);
    };

    for (int t = 0; t < n; ++t) {
        std::vector<int> gt;
        std::vector<int> erased;
        for (int i : g[t]) {
            if (g[i].size() & 1) {
                erased.push_back(i);
                g[i].erase(std::find(g[i].begin(), g[i].end(), t));
            } else {
                gt.push_back(i);
            }
        }
        g[t].swap(gt);

        int odd = 0;
        for (int i = 0; i < n; ++i) {
            if (i == t) continue;
            odd += g[i].size() & 1;
        }

        if (odd >= 2) {
            for (int i : erased) {
                g[i].push_back(t);
                g[t].push_back(i);
            }
            continue;
        }

        if (odd == 1) {
            UndirectedEulerianGraph h(n);
            for (int i = 0; i < n; ++i) for (int j : g[i]) if (i < j) {
                h.add_edge(i, j);
            }
            auto opt_ans = h.eulerian_trail();
            if (opt_ans.has_value()) {
                auto ans = *opt_ans;
                if (ans.front() == t) {
                    std::reverse(ans.begin(), ans.end());
                }
                ans.push_back(-1);
                for (int i : erased) {
                    ans.push_back(i);
                    ans.push_back(t);
                }
                out(ans);
            }
            for (int i : erased) {
                g[i].push_back(t);
                g[t].push_back(i);
            }
            continue;
        }

        atcoder::dsu uf(n);
        for (int i = 0; i < n; ++i) for (int j : g[i]) {
            uf.merge(i, j);
        }
        int c = 0, x = -1;
        for (const auto& group : uf.groups()) {
            if (group.size() == 1) {
                c += group[0] == t;
            } else {
                ++c;
                if (auto it = std::find(group.begin(), group.end(), t); it == group.end()) {
                    x = group[0];
                }
            }
        }
        if (c > 2) {
            for (int i : erased) {
                g[i].push_back(t);
                g[t].push_back(i);
            }
            continue;
        }
        if (c == 2) {
            auto it = std::find_if(erased.begin(), erased.end(), [&](int y) { return uf.same(x, y); });
            int v = *it;
            erased.erase(it);
            g[t].push_back(v);
            g[v].push_back(t);

            UndirectedEulerianGraph h(n);
            for (int i = 0; i < n; ++i) for (int j : g[i]) if (i < j) {
                h.add_edge(i, j);
            }
            auto ans = *h.eulerian_trail();
            if (ans.front() == t) {
                std::reverse(ans.begin(), ans.end());
            }
            ans.push_back(-1);
            for (int i : erased) {
                ans.push_back(i);
                ans.push_back(t);
            }
            out(ans);
        }

        UndirectedEulerianGraph h(n);
        for (int i = 0; i < n; ++i) for (int j : g[i]) if (i < j) {
            h.add_edge(i, j);
        }
        auto ans = *h.eulerian_circuit(t);
        if (ans.front() == t) {
            std::reverse(ans.begin(), ans.end());
        }
        ans.push_back(-1);
        for (int i : erased) {
            ans.push_back(i);
            ans.push_back(t);
        }
        out(ans);
    }

    std::cout << 0 << '\n';

    return 0;
}