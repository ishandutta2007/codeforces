#include <bits/stdc++.h>

template<typename _Val, typename _VV = std::plus<_Val>>
class fenwick_tree {
public:
    typedef std::size_t size_type;

protected:
    const _Val E;

    size_type n;
    std::vector<_Val> val;

    _VV fun;

public:
    fenwick_tree() : fenwick_tree(0) {}

    fenwick_tree(size_type _n)
    : E(), n(_n), val(n + 1, E) {}

    fenwick_tree(size_type _n, const _Val &_E)
    : E(_E), n(_n), val(n + 1, E) {}

    size_type size() const {
        return n;
    }

    void modify(size_type x, _Val v) {
        for (++x; x <= n; x += x & -x) {
            val[x] = fun(val[x], v);
        }
    }

    _Val query(size_type x) {
        _Val s = E;
        for (; x; x ^= x & -x) {
            s = fun(s, val[x]);
        }
        return s;
    }
};

struct query {
    int op, la, lb, ra, rb, s;
};

struct oper {
    int op, x, l, r, d;

    oper(int _op, int _x, int _l, int _r, int _d)
    : op(_op), x(_x), l(_l), r(_r), d(_d) {}

    bool operator<(const oper &rhs) const {
        return x < rhs.x || (x == rhs.x && op < rhs.op);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n), a(n), b(n);
    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        --v;
        p[v] = i;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        --b[i];
        a[p[b[i]]] = i;
    }

    std::vector<oper> tmp;
    for (int i = 0; i < n; ++i) {
        tmp.emplace_back(2, i, 0, a[i], 0);
    }

    std::vector<query> Q(q);

    for (int i = 0; i < q; ++i) {
        std::cin >> Q[i].op;
        if (Q[i].op == 1) {
            std::cin >> Q[i].la >> Q[i].ra;
            std::cin >> Q[i].lb >> Q[i].rb;
            --Q[i].la, --Q[i].lb;
        } else {
            int x, y;
            std::cin >> x >> y;
            --x, --y;
            Q[i].la = p[b[x]], Q[i].lb = a[p[b[x]]];
            Q[i].ra = p[b[y]], Q[i].rb = a[p[b[y]]];
            std::swap(b[x], b[y]);
            std::swap(a[p[b[x]]], a[p[b[y]]]);
        }
    }

    fenwick_tree<int> T(n);

    auto solve = [&](auto &self, int l, int r) -> void {
        if (l + 1 == r) {
            return;
        }
        int mid = (l + r) >> 1;
        self(self, l, mid);
        self(self, mid, r);
        std::vector<oper> tmp;
        for (int i = l; i < mid; ++i) {
            if (Q[i].op == 2) {
                tmp.emplace_back(2, Q[i].la, Q[i].lb, Q[i].rb, 0);
                tmp.emplace_back(2, Q[i].ra, Q[i].rb, Q[i].lb, 0);
            }
        }
        for (int i = mid; i < r; ++i) {
            if (Q[i].op == 1) {
                tmp.emplace_back(0, Q[i].la, Q[i].lb, Q[i].rb, i);
                tmp.emplace_back(1, Q[i].ra, Q[i].lb, Q[i].rb, i);
            }
        }
        std::sort(tmp.begin(), tmp.end());
        for (auto [op, x, l, r, d] : tmp) {
            if (op == 2) {
                T.modify(l, -1);
                T.modify(r, 1);
            } else {
                Q[d].s += (op == 0 ? -1 : 1) * (T.query(r) - T.query(l));
            }
        }
    };

    solve(solve, 0, q);

    for (int i = 0; i < q; ++i) {
        if (Q[i].op == 1) {
            tmp.emplace_back(0, Q[i].la, Q[i].lb, Q[i].rb, i);
            tmp.emplace_back(1, Q[i].ra, Q[i].lb, Q[i].rb, i);
        }
    }
    std::sort(tmp.begin(), tmp.end());
    for (auto [op, x, l, r, d] : tmp) {
        if (op == 2) {
            T.modify(r, 1);
        } else {
            Q[d].s += (op == 0 ? -1 : 1) * (T.query(r) - T.query(l));
        }
    }

    for (int i = 0; i < q; ++i) {
        if (Q[i].op == 1) {
            std::cout << Q[i].s << "\n";
        }
    }
}