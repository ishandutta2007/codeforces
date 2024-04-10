#include <bits/stdc++.h>

template<typename _Val, typename _VV = std::plus<_Val>>
class segment_tree {
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

    _VV fun;

    std::vector<_Val> val;

    void up(size_type u) {
        val[u] = fun(val[u << 1], val[u << 1 | 1]);
    }

    template<typename T>
    void build(size_type u, size_type l, size_type r, 
               const std::vector<T> &a) {
        if (l + 1 == r) {
            val[u] = a[l];
            return;
        }
        size_type mid = (l + r + 1) >> 1;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid, r, a);
        up(u);
    }

    void modify(size_type u, size_type l, size_type r, 
                size_type x, _Val v) {
        if (l + 1 == r) {
            val[u] = v;
            return;
        }
        size_type mid = (l + r + 1) >> 1;
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
        size_type mid = (l + r + 1) >> 1;
        if (R <= mid) {
            return query(u << 1, l, mid, L, R);
        } else if (L >= mid) {
            return query(u << 1 | 1, mid, r, L, R);
        } else {
            return fun(query(u << 1, l, mid, L, R), 
                       query(u << 1 | 1, mid, r, L, R));
        }
    }

public:
    segment_tree() : segment_tree(0) {}

    segment_tree(size_type _n)
    : n(_n), en(enlarge(n)), val(en << 1) {}

    template<typename T>
    segment_tree(const std::vector<T> &a)
    : n(a.size()), en(enlarge(n)), val(en << 1) {
        if (n) {
            build(1, 0, n, a);
        }
    }

    size_type size() const {
        return n;
    }

    void modify(size_type x, _Val v) {
        if (n) {
            modify(1, 0, n, x, v);
        }
    }

    _Val query(size_type l, size_type r) const {
        if (l < r) {
            return query(1, 0, n, l, r);
        } else {
            return _Val();
        }
    }
};

struct node {
    int l, r, w;
    long long s;

    node() : l(0), r(0), w(0), s(0) {}

    node(bool x) : w(1) {
        l = r = s = x;
    }

    node(int _l, int _r, int _w, long long _s) : l(_l), r(_r), w(_w), s(_s) {}

    friend node operator+(const node &a, const node &b) {
        return node(a.l + (a.l == a.w ? b.l : 0), 
                    b.r + (b.r == b.w ? a.r : 0), 
                    a.w + b.w,
                    a.s + b.s + 1ll * a.r * b.l);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int &x : a) {
        std::cin >> x;
    }
    std::vector<bool> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        b[i] = a[i] <= a[i + 1];
    }
    segment_tree<node> T(b);
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, v;
            std::cin >> x >> v;
            --x;
            a[x] = v;
            if (x > 0) {
                T.modify(x - 1, a[x - 1] <= a[x]);
            }
            if (x + 1 < n) {
                T.modify(x, a[x] <= a[x + 1]);
            }
        } else {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            std::cout << T.query(l, r).s + r - l + 1 << "\n";
        }
    }
}