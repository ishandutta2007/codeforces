#include <bits/stdc++.h>

template<typename _Val, 
         typename _VV = std::plus<>, 
         typename _Tag = _Val, 
         typename _VT = std::plus<>, 
         typename _TT = std::plus<>>
class lazy_seg_tree {
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

    template<typename T>
    void build(size_type u, size_type l, size_type r, 
               const std::vector<T> &a) {
        if (l + 1 == r) {
            val[u] = _Val(a[l]);
            return;
        }
        size_type mid = (l + r) >> 1;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid, r, a);
        up(u);
    }

    void modify(size_type u, size_type l, size_type r, 
                size_type x, const _Val &v) {
        if (l + 1 == r) {
            val[u] = v;
            return;
        }
        size_type mid = (l + r) >> 1;
        down(u);
        if (x < mid) {
            modify(u << 1, l, mid, x, v);
        } else {
            modify(u << 1 | 1, mid, r, x, v);
        }
        up(u);
    }

    void modify(size_type u, size_type l, size_type r, 
                size_type L, size_type R, _Tag v) {
        if (L <= l && r <= R) {
            apply(u, v);
            return;
        }
        size_type mid = (l + r) >> 1;
        down(u);
        if (L < mid) {
            modify(u << 1, l, mid, L, R, v);
        }
        if (mid < R) {
            modify(u << 1 | 1, mid, r, L, R, v);
        }
        up(u);
    }

    _Val query(size_type u, size_type l, size_type r, 
               size_type L, size_type R) {
        if (L <= l && r <= R) {
            return val[u];
        }
        size_type mid = (l + r) >> 1;
        down(u);
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
    lazy_seg_tree() : lazy_seg_tree(0) {}

    lazy_seg_tree(size_type _n)
    : n(_n), en(enlarge(n)), val(en << 1), tag(en << 1) {}

    template<typename T>
    lazy_seg_tree(const std::vector<T> &a)
    : n(a.size()), en(enlarge(n)), val(en << 1), tag(en << 1) {
        if (n) {
            build(1, 0, n, a);
        }
    }

    size_type size() const {
        return n;
    }

    void modify(size_type x, const _Val &v) {
        modify(1, 0, n, x, v);
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

class seg_beats {
public:
    typedef std::size_t size_type;

    struct node {
        size_type max, sec, cnt;

        node() : max(0), sec(0), cnt(0) {}
        node(size_type v) : max(v), sec(0), cnt(1) {}

        node operator+(const node &rhs) const {
            node res;
            if (max > rhs.max) {
                res.max = max;
                res.cnt = cnt;
                res.sec = std::max(sec, rhs.max + 1);
            } else if (max < rhs.max) {
                res.max = rhs.max;
                res.cnt = rhs.cnt;
                res.sec = std::max(rhs.sec, max + 1);
            } else {
                res.max = max;
                res.cnt = cnt + rhs.cnt;
                res.sec = std::max(sec, rhs.sec);
            }
            return res;
        }
    };

    struct tnode {
        long long sum;
        size_type l, r;

        tnode() : sum(0), l(0), r(0) {}

        tnode operator+(const tnode &rhs) const {
            tnode res;
            res.sum = sum + rhs.sum;
            res.l = l;
            res.r = rhs.r;
            return res;
        }

        tnode operator+(long long d) const {
            tnode res(*this);
            res.sum += d * (long long)(r - l);
            return res;
        }
    };

private:
    constexpr static size_type enlarge(size_type n) {
        size_type res = 1;
        while (res < n) {
            res <<= 1;
        }
        return res;
    }

protected:
    static const size_type INF = std::numeric_limits<size_type>::max();

    const size_type n, en;

    std::vector<node> val;
    std::vector<size_type> tag;

    lazy_seg_tree<tnode, std::plus<>, long long> T;

    void up(size_type u) {
        val[u] = val[u << 1] + val[u << 1 | 1];
    }

    void apply(size_type u, size_type v) {
        if (v >= val[u].max) {
            return;
        }
        val[u].max = v;
        tag[u] = v;
    }

    void down(size_type u) {
        apply(u << 1, tag[u]);
        apply(u << 1 | 1, tag[u]);
        tag[u] = INF;
    }

    void build(size_type u, size_type l, size_type r) {
        tag[u] = INF;
        if (l + 1 == r) {
            val[u] = node(l + 1);
            T.modify(l, val[u].max, 1);
            return;
        }
        size_type mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid, r);
        up(u);
    }

    void modify(size_type u, size_type l, size_type r, 
                size_type x, size_type v) {
        if (l + 1 == r) {
            T.modify(l, val[u].max, -1);
            val[u] = node(v);
            T.modify(l, val[u].max, 1);
            return;
        }
        size_type mid = (l + r) >> 1;
        down(u);
        if (x < mid) {
            modify(u << 1, l, mid, x, v);
        } else {
            modify(u << 1 | 1, mid, r, x, v);
        }
        up(u);
    }

    void update_min(size_type u, size_type l, size_type r, 
                    size_type L, size_type R, size_type v) {
        if (L <= l && r <= R) {
            if (v >= val[u].max) {
                return;
            }
            if (v >= val[u].sec) {
                T.modify(v, val[u].max, -(long long)(val[u].cnt));
                apply(u, v);
                return;
            }
        }
        size_type mid = (l + r) >> 1;
        down(u);
        if (L < mid) {
            update_min(u << 1, l, mid, L, R, v);
        }
        if (mid < R) {
            update_min(u << 1 | 1, mid, r, L, R, v);
        }
        up(u);
    }

    std::vector<tnode> construct_helper(int n) {
        std::vector<tnode> a(n);
        for (int i = 0; i < n; ++i) {
            a[i].l = i, a[i].r = i + 1, a[i].sum = 0;
        }
        return a;
    }

public:
    seg_beats(size_type _n)
    : n(_n), en(enlarge(n)), val(en << 1), tag(en << 1), 
      T(construct_helper(n)) {
        if (n) {
            build(1, 0, n);
        }
    }

    void modify(size_type x, size_type v) {
        modify(1, 0, n, x, v);
    }

    void update_min(size_type l, size_type r, size_type v) {
        if (l < r) {
            update_min(1, 0, n, l, r, v);
        }
    }

    long long query(size_type l, size_type r) {
        return T.query(l, r).sum;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    seg_beats T(n);
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, v;
            std::cin >> x >> v;
            --x;
            T.modify(x, v);
            T.update_min(0, x, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            --l;
            std::cout << T.query(l, r) << "\n";
        }
    }
}