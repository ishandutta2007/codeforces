#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
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

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

#include <limits>
#include <type_traits>

namespace suisen {
// ! utility
template <typename ...Types>
using constraints_t = std::enable_if_t<std::conjunction_v<Types...>, std::nullptr_t>;
template <bool cond_v, typename Then, typename OrElse>
constexpr decltype(auto) constexpr_if(Then&& then, OrElse&& or_else) {
    if constexpr (cond_v) {
        return std::forward<Then>(then);
    } else {
        return std::forward<OrElse>(or_else);
    }
}

// ! function
template <typename ReturnType, typename Callable, typename ...Args>
using is_same_as_invoke_result = std::is_same<std::invoke_result_t<Callable, Args...>, ReturnType>;
template <typename F, typename T>
using is_uni_op = is_same_as_invoke_result<T, F, T>;
template <typename F, typename T>
using is_bin_op = is_same_as_invoke_result<T, F, T, T>;

template <typename Comparator, typename T>
using is_comparator = std::is_same<std::invoke_result_t<Comparator, T, T>, bool>;

// ! integral
template <typename T, typename = constraints_t<std::is_integral<T>>>
constexpr int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits;
template <typename T, unsigned int n>
struct is_nbit { static constexpr bool value = bit_num<T> == n; };
template <typename T, unsigned int n>
static constexpr bool is_nbit_v = is_nbit<T, n>::value;

// ?
template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<unsigned int> { using type = unsigned long long; };
template <>
struct safely_multipliable<unsigned long long> { using type = __uint128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

} // namespace suisen

namespace suisen {
class HeavyLightDecomposition {
    public:
        template <typename Q>
        using is_point_update_query = std::is_invocable<Q, int>;
        template <typename Q>
        using is_range_update_query = std::is_invocable<Q, int, int>;
        template <typename Q, typename T>
        using is_point_get_query  = std::is_same<std::invoke_result_t<Q, int>, T>;
        template <typename Q, typename T>
        using is_range_fold_query = std::is_same<std::invoke_result_t<Q, int, int>, T>;

        using Graph = std::vector<std::vector<int>>;

        HeavyLightDecomposition(Graph &g, int root = 0) : n(g.size()), root(root), visit(n), leave(n), head(n), ord(n), siz(n), par(n) {
            dfs(g, root, -1);
            int time = 0;
            hld(g, root, -1, time);
        }
        int lca(int u, int v) {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) return u;
            }
        }
        int la(int u, int k, int default_value = -1) {
            for (int h = head[u]; u >= 0; u = par[h], h = head[u]) {
                if (visit[u] - k >= visit[h]) return ord[visit[u] - k];
                k -= visit[u] - visit[h] + 1;
            }
            return default_value;
        }
        template <typename T, typename Q, typename F, constraints_t<is_range_fold_query<Q, T>, is_bin_op<F, T>> = nullptr>
        T fold_path(int u, int v, T identity, F bin_op, Q fold_query, bool is_edge_query = false) {
            T res = identity;
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                res = bin_op(fold_query(visit[head[v]], visit[v] + 1), res);
            }
            return bin_op(fold_query(visit[u] + is_edge_query, visit[v] + 1), res);
        }
        template <
            typename T, typename Q1, typename Q2, typename F,
            constraints_t<is_range_fold_query<Q1, T>, is_range_fold_query<Q2, T>, is_bin_op<F, T>> = nullptr
        >
        T fold_path_noncommutative(int u, int v, T identity, F bin_op, Q1 fold_query, Q2 fold_query_rev, bool is_edge_query = false) {
            T res_u = identity, res_v = identity;
            // a := lca(u, v)
            // res = fold(u -> a) + fold(a -> v)
            while (head[u] != head[v]) {
                if (visit[u] < visit[v]) { // a -> v
                    res_v = bin_op(fold_query(visit[head[v]], visit[v] + 1), res_v);
                    v = par[head[v]];
                } else { // u -> a
                    res_u = bin_op(res_u, fold_query_rev(visit[head[u]], visit[u] + 1));
                    u = par[head[u]];
                }
            }
            if (visit[u] < visit[v]) { // a = u
                res_v = bin_op(fold_query(visit[u] + is_edge_query, visit[v] + 1), res_v);
            } else { // a = v
                res_u = bin_op(res_u, fold_query_rev(visit[v] + is_edge_query, visit[u] + 1));
            }
            return bin_op(res_u, res_v);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void update_path(int u, int v, Q update_query, bool is_edge_query = false) {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                update_query(visit[head[v]], visit[v] + 1);
            }
            update_query(visit[u] + is_edge_query, visit[v] + 1);
        }
        template <typename T, typename Q, constraints_t<is_range_fold_query<Q, T>> = nullptr>
        T fold_subtree(int u, Q fold_query, bool is_edge_query = false) {
            return fold_query(visit[u] + is_edge_query, leave[u]);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void update_subtree(int u, Q update_query, bool is_edge_query = false) {
            update_query(visit[u] + is_edge_query, leave[u]);
        }
        template <typename T, typename Q, constraints_t<is_point_get_query<Q, T>> = nullptr>
        T get_point(int u, Q get_query) {
            return get_query(visit[u]);
        }
        template <typename Q, constraints_t<is_point_update_query<Q>> = nullptr>
        void update_point(int u, Q update_query) {
            update_query(visit[u]);
        }
        std::vector<int> inv_ids() const {
            std::vector<int> inv(n);
            for (int i = 0; i < n; ++i) inv[visit[i]] = i;
            return inv;
        }
        int get_head(int u) const {
            return head[u];
        }
    private:
        const int n, root;
        std::vector<int> visit, leave, head, ord, siz, par;
        int dfs(Graph &g, int u, int p) {
            par[u] = p;
            siz[u] = 1;
            int max_size = 0;
            for (int &v : g[u]) {
                if (v == p) continue;
                siz[u] += dfs(g, v, u);
                if (max_size < siz[v]) {
                    max_size = siz[v];
                    std::swap(g[u].front(), v);
                }
            }
            return siz[u];
        }
        void hld(Graph &g, int u, int p, int &time) {
            visit[u] = time, ord[time] = u, ++time;
            head[u] = p >= 0 and g[p].front() == u ? head[p] : u;
            for (int v : g[u]) {
                if (v != p) hld(g, v, u, time);
            }
            leave[u] = time;
        }
};
} // namespace suisen

int op(int x, int y) {
    return std::max(x, y);
}
int e() {
    return std::numeric_limits<int>::min();
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<int, int, int, int>> edges(m);
    std::set<std::pair<int, int>> exists;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;
        exists.insert(std::minmax(u, v));
        edges[i] = { w, u, v, i };
    }
    std::sort(edges.begin(), edges.end());

    std::vector<std::vector<std::vector<int>>> groups(n);
    for (int i = 0; i < n; ++i) {
        groups[i] = { { i } };
    }

    std::vector<std::tuple<int, int, int>> edges2;
    atcoder::dsu uf1(n);
    atcoder::dsu uf2(n);
    for (const auto &[w, u, v, eid] : edges) {
        if (uf1.same(u, v)) continue;
        int ru = uf1.leader(u), rv = uf1.leader(v);

        const int r = uf1.merge(ru, rv), c = ru ^ rv ^ r;

        const int p = groups[c].size(), q = groups[r].size();

        std::vector<std::vector<int>> g(p + q);

        for (int i = 0; i < p; ++i) for (int j = 0; j < q; ++j) {
            bool flg = false;
            for (int x : groups[c][i]) {
                for (int y : groups[r][j]) {
                    if (uf2.same(x, y)) {
                        flg = true;
                        break;
                    }
                    auto key = std::minmax(x, y);
                    if (exists.find(key) != exists.end()) continue;
                    uf2.merge(x, y);
                    edges2.emplace_back(w, x, y);
                    g[i].push_back(p + j);
                    g[p + j].push_back(i);
                    flg = true;
                    break;
                }
                if (flg) break;
            }
        }

        std::vector<bool> seen(p + q, false);
        std::vector<std::vector<int>> new_group;
        for (int i = 0; i < p + q; ++i) {
            if (seen[i]) continue;
            std::vector<int> con;
            auto dfs = [&](auto dfs, int u, int par) -> void {
                seen[u] = true;
                auto &old_con = u < p ? groups[c][u] : groups[r][u - p];
                if (con.size() < old_con.size()) con.swap(old_con);
                for (int v : old_con) con.push_back(v);
                for (int v : g[u]) {
                    if (v == par) continue;
                    dfs(dfs, v, u);
                }
            };
            dfs(dfs, i, -1);
            new_group.push_back(std::move(con));
        }
        groups[r] = std::move(new_group);
    }

    std::vector<std::vector<int>> _mst(n);
    std::vector<std::vector<std::pair<int, int>>> mst(n);
    atcoder::dsu uf3(n);
    for (const auto &[w, u, v] : edges2) {
        if (uf3.same(u, v)) continue;
        _mst[u].push_back(v);
        _mst[v].push_back(u);
        mst[u].emplace_back(v, w);
        mst[v].emplace_back(u, w);
        uf3.merge(u, v);
    }

    suisen::HeavyLightDecomposition hld(_mst);
    std::vector<int> init(n, e());
    auto dfs = [&](auto dfs, int u, int p) -> void {
        for (const auto &e : mst[u]) {
            int v, w;
            std::tie(v, w) = e;
            if (v == p) continue;
            hld.update_point(v, [&](int vid) { init[vid] = w; });
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 0, -1);

    atcoder::segtree<int, op, e> seg(init);

    std::vector<int> ans(m);
    for (const auto &[w, u, v, eid] : edges) {
        ans[eid] = hld.fold_path(u, v, e(), op, [&](int l, int r) { return seg.prod(l, r); }, true);
    }
    for (int i = 0; i < m; ++i) {
        std::cout << ans[i] << " \n"[i == m - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t --> 0) solve();
    return 0;
}