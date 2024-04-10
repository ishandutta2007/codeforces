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

    void apply(size_type u, const _Tag &v) {
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
                size_type L, size_type R, const _Tag &v) {
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

    void modify(size_type l, size_type r, const _Tag &v) {
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

struct node {
    static int M;
    static std::vector<int> pf;

    static int qpow(int a, int b) {
        int s = 1;
        for (; b; b >>= 1) {
            if (b & 1) {
                s = 1ll * s * a % M;
            }
            a = 1ll * a * a % M;
        }
        return s;
    }

    int v;
    std::vector<int> c;

    node() : v(1), c(pf.size()) {}

    node(int _v) : v(_v), c(pf.size()) {
        for (std::size_t i = 0; i < pf.size(); ++i) {
            while (v % pf[i] == 0) {
                v /= pf[i];
                ++c[i];
            }
        }
    }

    node operator*(const node &rhs) const {
        node res;
        res.v = 1ll * v * rhs.v % M;
        for (std::size_t i = 0; i < pf.size(); ++i) {
            res.c[i] = c[i] + rhs.c[i];
        }
        return res;
    }

    node inv() const {
        node res;
        int phi = M;
        for (std::size_t i = 0; i < pf.size(); ++i) {
            res.c[i] = -c[i];
            phi /= pf[i];
            phi *= pf[i] - 1;
        }
        res.v = qpow(v, phi - 1);
        return res;
    }

    int val() const {
        int ans = v;
        for (std::size_t i = 0; i < pf.size(); ++i) {
            ans = 1ll * ans * qpow(pf[i], c[i]) % M;
        }
        return ans;
    }

    node operator+(const node &rhs) const {
        return node();
    }
};

int node::M;
std::vector<int> node::pf;

struct mint {
    static int M;

    int v;

    mint() : v(1) {}

    mint(int _v) : v(_v % M) {}

    mint operator+(const mint &rhs) const {
        mint res;
        res.v = v + rhs.v >= M ? v + rhs.v - M : v + rhs.v;
        return res;
    }

    mint operator*(const mint &rhs) const {
        mint res;
        res.v = 1ll * v * rhs.v % M;
        return res;
    }

    int val() const {
        return v;
    }
};

int mint::M;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    node::M = m;
    int x = m;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            node::pf.push_back(i);
        }
    }
    if (x > 1) {
        node::pf.push_back(x);
    }
    mint::M = m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    lazy_seg_tree<node, std::plus<>, node, 
                  std::multiplies<>, std::multiplies<>> T(a);
    lazy_seg_tree<mint, std::plus<>, mint, 
                  std::multiplies<>, std::multiplies<>> S(a);
    int q;
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            --l;
            T.modify(l, r, x);
            S.modify(l, r, x);
        } else if (op == 2) {
            int p, x;
            std::cin >> p >> x;
            --p;
            node tmp = T.query(p, p + 1);
            tmp = tmp * node(x).inv();
            T.modify(p, tmp);
            S.modify(p, tmp.val());
        } else {
            int l, r;
            std::cin >> l >> r;
            --l;
            std::cout << S.query(l, r).val() << "\n";
        }
    }
}