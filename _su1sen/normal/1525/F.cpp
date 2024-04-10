#include <cassert>
#include <iostream>

#include <algorithm>
#include <deque>
#include <random>
#include <utility>
#include <vector>

namespace suisen {
    struct BipartiteMatching {
        static constexpr int ABSENT = -1;

        BipartiteMatching() {}
        BipartiteMatching(int n, int m) : _n(n), _m(m), _to_r(_n, ABSENT), _to_l(_m, ABSENT), _g(n + m) {}

        void add_edge(int fr, int to) {
            _g[fr].push_back(to), _f = -1;
        }

        template <bool shuffle = true>
        int solve() {
            if (_f >= 0) return _f;
            
            static std::mt19937 rng(std::random_device{}());
            if constexpr (shuffle) for (auto &adj : _g) std::shuffle(adj.begin(), adj.end(), rng);

            std::vector<int8_t> vis(_n, false);
        
            auto dfs = [&, this](auto dfs, int u) -> bool {
                if (std::exchange(vis[u], true)) return false;
                for (int v : _g[u]) if (_to_l[v] == ABSENT) return _to_r[u] = v, _to_l[v] = u, true;
                for (int v : _g[u]) if (dfs(dfs, _to_l[v])) return _to_r[u] = v, _to_l[v] = u, true;
                return false;
            };
    
            for (bool upd = true; std::exchange(upd, false);) {
                vis.assign(_n, false);
                for (int i = 0; i < _n; ++i) if (_to_r[i] == ABSENT) upd |= dfs(dfs, i);
            }

            return _f = _n - std::count(_to_r.begin(), _to_r.end(), ABSENT);
        }

        std::vector<std::pair<int, int>> max_matching() {
            if (_f < 0) _f = solve();
            std::vector<std::pair<int, int>> res;
            res.reserve(_f);
            for (int i = 0; i < _n; ++i) if (_to_r[i] != ABSENT) res.emplace_back(i, _to_r[i]);
            return res;
        }

        std::vector<std::pair<int, int>> min_edge_cover() {
            auto res = max_matching();
            std::vector<bool> vl(_n, false), vr(_n, false);
            for (const auto &[u, v] : res) vl[u] = vr[v] = true;
            for (int u = 0; u < _n; ++u) for (int v : _g[u]) if (not (vl[u] and vr[v])) {
                vl[u] = vr[v] = true;
                res.emplace_back(u, v);
            }
            return res;
        }

        std::vector<int> min_vertex_cover() {
            if (_f < 0) _f = solve();
            std::vector<std::vector<int>> g(_n + _m);
            std::vector<bool> cl(_n, true), cr(_m, false);
            for (int u = 0; u < _n; ++u) for (int v : _g[u]) {
                if (_to_r[u] == v) {
                    g[v + _n].push_back(u);
                    cl[u] = false;
                } else {
                    g[u].push_back(v + _n);
                }
            }
            std::vector<bool> vis(_n + _m, false);
            std::deque<int> dq;
            for (int i = 0; i < _n; ++i) if (cl[i]) {
                dq.push_back(i);
                vis[i] = true;
            }
            while (dq.size()) {
                int u = dq.front();
                dq.pop_front();
                for (int v : g[u]) {
                    if (vis[v]) continue;
                    vis[v] = true;
                    (v < _n ? cl[v] : cr[v - _n]) = true;
                    dq.push_back(v);
                }
            }
            std::vector<int> res;
            for (int i = 0; i < _n; ++i) if (not cl[i]) res.push_back(i);
            for (int i = 0; i < _m; ++i) if (cr[i]) res.push_back(_n + i);
            return res;
        }
        
        std::vector<int> max_independent_set() {
            std::vector<bool> use(_n + _m, true);
            for (int v : min_vertex_cover()) use[v] = false;
            std::vector<int> res;
            for (int i = 0; i < _n + _m; ++i) if (use[i]) res.push_back(i);
            return res;
        }

        int right(int l) const {
            return _to_r[l];
        }
        int left(int r) const {
            return _to_l[r];
        }

    private:
        int _n, _m;
        std::vector<int> _to_r, _to_l;
        std::vector<std::vector<int>> _g;
        int _f = 0;
    };
    
} // namespace suisen

using suisen::BipartiteMatching;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> g(n), h(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        h[v].push_back(u);
    }

    long long base_score = 0;

    std::vector<int> xs(k + 1);
    std::vector<std::pair<int, int>> ps;
    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        xs[i] = x;
        base_score += x;
        if (ps.empty() or ps.back().first > y) {
            ps.emplace_back(y, i);
        }
    }
    ps.emplace_back(0, k);

    BipartiteMatching bm;

    auto rebuild = [&] {
        bm = BipartiteMatching(n, n);
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                bm.add_edge(i, j);
            }
        }
    };
    rebuild();

    auto remove_from_left = [&] {
        std::vector<int8_t> wk_l(n, false);
        auto dfs = [&](auto dfs, int i) -> void {
            if (i == BipartiteMatching::ABSENT or wk_l[i]) return;
            wk_l[i] = true;
            for (int j : g[i]) dfs(dfs, bm.left(j));
        };
        for (int i = 0; i < n; ++i) {
            if (bm.right(i) == BipartiteMatching::ABSENT) {
                dfs(dfs, i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (not wk_l[i]) return i;
        }
        return -1;
    };

    auto remove_from_right = [&] {
        std::vector<int8_t> w0_r(n, false);
        auto dfs = [&](auto dfs, int j) -> void {
            if (j == BipartiteMatching::ABSENT or w0_r[j]) return;
            w0_r[j] = true;
            for (int i : h[j]) dfs(dfs, bm.right(i));
        };
        for (int j = 0; j < n; ++j) {
            if (bm.left(j) == BipartiteMatching::ABSENT) {
                dfs(dfs, j);
            }
        }
        for (int j = 0; j < n; ++j) {
            if (not w0_r[j]) return j;
        }
        return -1;
    };

    int arg_max = -1;
    long long max_score = -1;
    long long min_cost = 0;

    int deletion_time = 0;
    long long deletion_cost = 0;

    std::vector<std::vector<std::pair<int, int>>> op(k);

    for (int i = 0, j = 0; i <= k; ++i) {
        long long score = base_score - (min_cost + xs[i]);
        if (max_score < score) {
            max_score = score;
            arg_max = i;
        }
        if (i == k) break;
        if (ps[j].second == i) std::tie(deletion_cost, deletion_time) = ps[j++];

        int cap_goblins = n - bm.solve();
        int num_goblins = i + 1;
        if (cap_goblins > num_goblins) continue;

        if (int rem_l = remove_from_left(); rem_l >= 0) {
            g[rem_l].clear();
            for (auto &adj : h) {
                auto it = std::find(adj.begin(), adj.end(), rem_l);
                if (it != adj.end()) adj.erase(it);
            }
            op[deletion_time].emplace_back(+(rem_l + 1), i);
        } else {
            int rem_r = remove_from_right();
            h[rem_r].clear();
            for (auto &adj : g) {
                auto it = std::find(adj.begin(), adj.end(), rem_r);
                if (it != adj.end()) adj.erase(it);
            }
            op[deletion_time].emplace_back(-(rem_r + 1), i);
        }
        min_cost += deletion_cost;
        rebuild();
        assert(n - bm.solve() > cap_goblins);
    }

    std::vector<int8_t> removed(n, false);

    std::vector<int> ans;
    for (int i = 0; i < k; ++i) {
        if (i < arg_max) {
            for (const auto &[v, t] : op[i]) {
                if (t >= arg_max) break;
                ans.push_back(v);
                if (v > 0) removed[v - 1] = true;
            }
        } else if (i == arg_max) {
            for (int j = 0; j < n; ++j) {
                if (not removed[j]) ans.push_back(j + 1);
            }
        }
        ans.push_back(0);
    }

    int sz = ans.size();
    std::cout << sz << '\n';
    for (int i = 0; i < sz; ++i) {
        std::cout << ans[i];
        if (i + 1 < sz) std::cout << ' ';
    }
    std::cout << '\n';

    // std::cerr << "score = " << max_score << '\n';

    return 0;
}