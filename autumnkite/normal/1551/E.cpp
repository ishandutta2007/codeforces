#include <bits/stdc++.h>

template<typename _Val, typename _VV = std::plus<_Val>, _Val _E = _Val()>
class fenwick_tree {
public:
    typedef std::size_t size_type;

protected:
    size_type n;
    std::vector<_Val> val;

    _VV fun;

public:
    fenwick_tree() : fenwick_tree(0) {}

    fenwick_tree(size_type _n) : n(_n), val(n + 1, _E) {}

    size_type size() const {
        return n;
    }

    void modify(size_type x, _Val v) {
        for (++x; x <= n; x += x & -x) {
            val[x] = fun(val[x], v);
        }
    }

    _Val query(size_type x) {
        _Val s = _E;
        for (; x; x ^= x & -x) {
            s = fun(s, val[x]);
        }
        return s;
    }
};

const int INF = 0x3f3f3f3f;

struct min {
    int operator()(const int &a, const int &b) const {
        return std::min(a, b);
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> id(n + 1);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int x, int y) {
        return a[x] < a[y] || (a[x] == a[y] && x > y);
    });
    std::vector<int> f(n + 1, INF);
    f[0] = 0;
    for (int k = 0; k < m; ++k) {
        std::vector<int> g(n + 1, INF);
        fenwick_tree<int, min, INF> T(n + 1);
        for (int i : id) {
            if (i >= a[i]) {
                int tmp = T.query(i - a[i] + 1);
                if (tmp != INF) {
                    g[i] = tmp + i - a[i];
                }
                if (f[i] != INF) {
                    T.modify(i - a[i], f[i] - i + a[i]);
                }
            }
        }
        f.swap(g);
    }
    int ans = *std::min_element(f.begin(), f.end());
    std::cout << (ans == INF ? -1 : ans) << "\n";
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