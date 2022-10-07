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

constexpr int INF = 0x3f3f3f3f;

template<typename T>
struct max {
    T operator()(const T &a, const T &b) const {
        return std::max(a, b);
    }
};

template<typename T>
struct min {
    T operator()(const T &a, const T &b) const {
        return std::min(a, b);
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
    }
    std::reverse(a.begin(), a.end());
    int ans = 0;
    for (int d = 0; d < 2; ++d) {
        std::vector<int> fL(n, INF), fR(n, -INF);
        for (int i = 0; i < (d ? n : 1); ++i) {
            fL[i] = fR[i] = a[i];
        }
        int t = 1 + d;
        while (1) {
            fenwick_tree<int, min<int>, INF> TL(n);
            fenwick_tree<int, max<int>, -INF> TR(n);
            std::vector<int> gL(n, INF), gR(n, -INF);
            bool ok = false;
            for (int i = 0; i < n; ++i) {
                if (i - t >= 0 && fR[i - t] > -INF) {
                    TL.modify(n - 1 - fR[i - t], a[i - t]);
                }
                if (i - t >= 0 && fL[i - t] < INF) {
                    TR.modify(fL[i - t], a[i - t]);
                }
                gL[i] = TL.query(n - 1 - a[i]);
                gR[i] = TR.query(a[i]);
                ok |= gL[i] < INF;
                ok |= gR[i] > -INF;
                TL.modify(n - 1 - a[i], fL[i]);
                TR.modify(a[i], fR[i]);
            }
            if (!ok) {
                break;
            }
            fL.swap(gL), fR.swap(gR);
            ++t;
        }
        ans = std::max(ans, t - d);
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