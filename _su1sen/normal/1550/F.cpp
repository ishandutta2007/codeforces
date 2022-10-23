#include <cassert>
#include <iostream>
#include <limits>
#include <map>
#include <tuple>

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

constexpr int M = 1000000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q, s, d;
    std::cin >> n >> q >> s >> d;
    --s;

    std::map<int, int> mp;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        mp[a[i]] = i;
    }

    auto get_weight = [&](int i, int j) {
        return ::abs(::abs(a[i] - a[j]) - d);
    };

    std::vector<std::vector<std::pair<int, int>>> mst(n);

    atcoder::dsu uf(n);

    while (uf.size(0) != n) {
        auto groups = uf.groups();

        for (auto group : groups) {
            for (int v : group) mp.erase(a[v]);

            auto min_edge = std::make_tuple(std::numeric_limits<int>::max(), 0, 0);

            auto chmin = [&](const auto &fr_to) {
                auto [x, y] = fr_to;
                auto edge = std::make_tuple(get_weight(x, y), x, y);
                if (edge < min_edge) min_edge = std::move(edge);
            };
        
            for (int v : group) {
                for (int x : { a[v] - d, a[v] + d }) {
                    auto it = mp.lower_bound(x);
                    if (it != mp.end())   chmin(std::minmax(v, it->second));
                    if (it != mp.begin()) chmin(std::minmax(v, (--it)->second));
                }
            }

            auto [w, x, y] = min_edge;
            mst[x].emplace_back(y, w);
            mst[y].emplace_back(x, w);
            uf.merge(x, y);

            for (int v : group) mp[a[v]] = v;
        }
    }

    for (auto &adj : mst) {
        std::sort(adj.begin(), adj.end());
        adj.erase(std::unique(adj.begin(), adj.end()), adj.end());
    }
    
    std::vector<int> min_k(n);
    auto dfs = [&](auto dfs, int u, int p) -> void {
        for (const auto &[v, w_uv] : mst[u]) {
            if (v == p) continue;
            min_k[v] = std::max(w_uv, min_k[u]);
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, s, -1);

    while (q --> 0) {
        int i, k;
        std::cin >> i >> k;
        --i;
        std::cout << (min_k[i] <= k ? "Yes" : "No") << '\n';
    }
    return 0;
}