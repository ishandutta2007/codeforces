#include <bits/stdc++.h>

#if __cplusplus > 201103L
template<typename _Val, typename _Tag = _Val, 
         typename _VV = std::plus<>, typename _VT = std::plus<>, typename _TT = std::plus<>>
#else
template<typename _Val, typename _Tag, 
         typename _VV, typename _VT, typename _TT>
#endif
class segment_tree {
public:
    typedef std::size_t size_type;

private:
    static size_type enlarge(size_type n) {
        size_type res = 1;
        while (res < n) {
            res <<= 1;
        }
        return res;
    }

protected:
    const size_type n, en;

    _VV fun_vv;
    _VT fun_vt;
    _TT fun_tt;

    std::vector<_Val> val;
    std::vector<_Tag> tag;

    void up(size_type u) {
        val[u] = fun_vv(val[u << 1], val[u << 1 | 1]);
    }

    void apply(size_type u, _Tag v) {
        val[u] = fun_vt(val[u], v);
        tag[u] = fun_tt(tag[u], v);
    }

    void down(size_type u) {
        apply(u << 1, tag[u]);
        apply(u << 1 | 1, tag[u]);
        tag[u] = _Tag();
    }

    void build(size_type u, size_type l, size_type r, const std::vector<_Val> &a) {
        if (l + 1 == r) {
            val[u] = a[l];
            return;
        }
        size_type mid = (l + r + 1) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid, r);
        up(u);
    }

    void modify(size_type u, size_type l, size_type r, size_type L, size_type R, _Tag v) {
        if (L <= l && r <= R) {
            apply(u, v);
            return;
        }
        size_type mid = (l + r + 1) >> 1;
        down(u);
        if (L < mid) {
            modify(u << 1, l, mid, L, R, v);
        }
        if (mid < R) {
            modify(u << 1 | 1, mid, r, L, R, v);
        }
        up(u);
    }

    _Val query(size_type u, size_type l, size_type r, size_type L, size_type R) {
        if (L <= l && r <= R) {
            return val[u];
        }
        size_type mid = (l + r + 1) >> 1;
        down(u);
        if (R <= mid) {
            return query(u << 1, l, mid, L, R);
        } else if (L >= mid) {
            return query(u << 1 | 1, mid, r, L, R);
        } else {
            return fun_vv(query(u << 1, l, mid, L, R), query(u << 1 | 1, mid, r, L, R));
        }
    }

public:
    segment_tree() : segment_tree(0) {}

    segment_tree(size_type _n) : n(_n), en(enlarge(n)), val(en << 1), tag(en << 1) {}

    segment_tree(const std::vector<_Val> &a) : n(a.size()), en(enlarge(n)), val(en << 1), tag(en << 1) {
        build(1, 0, n, a);
    }

    size_type size() const {
        return n;
    }

    void modify(size_type l, size_type r, _Tag v) {
        if (l < r) {
            modify(1, 0, n, l, r, v);
        }
    }

    _Val query(size_type l, size_type r) {
        if (l < r) {
            return query(1, 0, n, l, r);
        } else {
            return _Val();
        }
    }
};

struct max {
    int operator()(int a, int b) const {
        return std::max(a, b);
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        --x;
        a[x] = i;
    }
    segment_tree<int, int, max> T(n);
    std::set<int> S0, S1;
    for (int i = 1; i < n; i += 2) {
        T.modify(i, i + 1, 1);
    }
    for (int i = 0; i < n; ++i) {
        T.modify(i, n, 1);
        S1.insert(i);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        T.modify(a[i], n, -2);
        S1.erase(a[i]);
        S0.insert(a[i]);
        int l = *S1.begin(), r = *(--S0.end()) + 1;
        if (l >= r) {
            continue;
        }
        ans = std::max(ans, i + T.query(l, r));
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}