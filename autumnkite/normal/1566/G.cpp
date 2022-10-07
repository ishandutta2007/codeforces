#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename _Val, typename _VV = std::plus<_Val>>
class seg_tree {
public:
    typedef std::size_t size_type;

private:
    constexpr static size_type enlarge(size_type n) {
        size_type res = 1;
        while (res < n) {
            res <<= 1;
        }
        return res;
    }

protected:
    const size_type n, en;

    _VV fun_vv;

    std::vector<_Val> val;

    void up(size_type u) {
        val[u] = fun_vv(val[u << 1], val[u << 1 | 1]);
    }

    template<typename T>
    void build(size_type u, size_type l, size_type r, 
               const std::vector<T> &a) {
        if (l + 1 == r) {
            val[u] = _Val(a[l]);
            return;
        }
        size_type mid = l + ((r - l) >> 1);
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid, r, a);
        up(u);
    }

    template<typename T>
    void modify(size_type u, size_type l, size_type r, 
                size_type x, const T &v) {
        if (l + 1 == r) {
            val[u] = _Val(v);
            return;
        }
        size_type mid = l + ((r - l) >> 1);
        if (x < mid) {
            modify(u << 1, l, mid, x, v);
        } else {
            modify(u << 1 | 1, mid, r, x, v);
        }
        up(u);
    }

    _Val query(size_type u, size_type l, size_type r, 
               size_type L, size_type R) const {
        if (L <= l && r <= R) {
            return val[u];
        }
        size_type mid = l + ((r - l) >> 1);
        if (R <= mid) {
            return query(u << 1, l, mid, L, R);
        } else if (L >= mid) {
            return query(u << 1 | 1, mid, r, L, R);
        } else {
            return fun_vv(query(u << 1, l, mid, L, R), 
                          query(u << 1 | 1, mid, r, L, R));
        }
    }

public:
    seg_tree() : seg_tree(0) {}

    seg_tree(size_type _n)
    : n(_n), en(enlarge(n)), val(en << 1) {}

    template<typename T>
    seg_tree(const std::vector<T> &a)
    : n(a.size()), en(enlarge(n)), val(en << 1) {
        if (n) {
            build(1, 0, n, a);
        }
    }

    size_type size() const {
        return n;
    }

    template<typename T>
    void modify(size_type x, const T &v) {
        modify(1, 0, n, x, v);
    }

    _Val query(size_type l, size_type r) const {
        if (l < r) {
            return query(1, 0, n, l, r);
        } else {
            return _Val();
        }
    }
};

template<typename T>
struct min {
    T operator()(const T &a, const T &b) const {
        return std::min(a, b);
    }
};

typedef __gnu_pbds::tree<std::pair<int, int>, __gnu_pbds::null_type, 
                         std::less<std::pair<int, int>>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update> tree;

const int LIM = 1000000000;

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::multiset<int>> adj_w(n);
    std::map<std::pair<int, int>, int> edge;
    std::set<std::tuple<int, int, int>> edge_w;
    seg_tree<long long, min<long long>> gmin(n);
    int idx = 0;
    std::vector<tree> cnt(n);
    tree gcnt;

    auto modify = [&](int u) {
        auto it = adj_w[u].begin();
        long long s = 0;
        for (int i = 0; i < 3; ++i) {
            if (it == adj_w[u].end()) {
                gmin.modify(u, INF);
                return;
            }
            s += *it;
            ++it;
        }
        gmin.modify(u, s);
    };

    auto insert = [&](int u, int v, int w) {
        adj_w[u].insert(w);
        adj_w[v].insert(w);
        edge_w.emplace(w, u, v);
        edge[std::make_pair(u, v)] = w;
        cnt[u].insert(std::make_pair(w, idx));
        cnt[v].insert(std::make_pair(w, idx));
        gcnt.insert(std::make_pair(w, idx));
        ++idx;
        modify(u);
        modify(v);
    };

    auto erase = [&](int u, int v) {
        if (!edge.count(std::make_pair(u, v))) {
            std::swap(u, v);
        }
        int w = edge[std::make_pair(u, v)];
        adj_w[u].erase(adj_w[u].find(w));
        adj_w[v].erase(adj_w[v].find(w));
        edge.erase(std::make_pair(u, v));
        edge_w.erase(std::make_tuple(w, u, v));
        cnt[u].erase(cnt[u].lower_bound(std::make_pair(w, 0)));
        cnt[v].erase(cnt[v].lower_bound(std::make_pair(w, 0)));
        gcnt.erase(gcnt.lower_bound(std::make_pair(w, 0)));
        modify(u);
        modify(v);
    };

    auto query = [&](int u, int v) -> long long {
        if (!edge.count(std::make_pair(u, v))) {
            std::swap(u, v);
        }
        if (!edge.count(std::make_pair(u, v))) {
            return INF;
        }
        int w = edge[std::make_pair(u, v)];
        int l = 0, r = LIM + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (gcnt.order_of_key(std::make_pair(mid + 1, 0))
                - cnt[u].order_of_key(std::make_pair(mid + 1, 0))
                - cnt[v].order_of_key(std::make_pair(mid + 1, 0))
                + (w <= mid) > 0) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (r == LIM + 1) {
            return INF;
        }
        return w + r;
    };

    auto get_ans = [&]() -> long long {
        auto [w1, u1, v1] = *edge_w.begin();
        auto [w2, u2, v2] = *std::next(edge_w.begin());
        std::vector<int> id({u1, v1, u2, v2});
        std::sort(id.begin(), id.end());
        id.erase(std::unique(id.begin(), id.end()), id.end());
        if ((int)id.size() == 4) {
            return w1 + w2;
        }
        long long ans = gmin.query(0, n);
        for (int i = 0; i < (int)id.size(); ++i) {
            for (int j = i + 1; j < (int)id.size(); ++j) {
                ans = std::min(ans, query(id[i], id[j]));
            }
        }
        return ans;
    };

    for (int i = 0; i < n; ++i) {
        modify(i);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;
        insert(u, v, w);
    }

    std::cout << get_ans() << "\n";
    
    int q;
    std::cin >> q;
    while (q--) {
        int op, u, v;
        std::cin >> op >> u >> v;
        --u, --v;
        if (op == 0) {
            erase(u, v);
        } else {
            int w;
            std::cin >> w;
            insert(u, v, w);
        }
        std::cout << get_ans() << "\n";
    }
}