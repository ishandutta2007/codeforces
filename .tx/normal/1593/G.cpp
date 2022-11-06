#ifndef CONTESTSMTH_HEADER_H
#define CONTESTSMTH_HEADER_H

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename V = __gnu_pbds::null_type>
using htable = __gnu_pbds::gp_hash_table<K, V>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
#ifdef VSE
mt19937 rng(0);
#else
mt19937 rng((size_t) make_shared<char>().get());
#endif

#endif //CONTESTSMTH_HEADER_H

#ifndef CONTESTSMTH_UTILS_H
#define CONTESTSMTH_UTILS_H



template <typename T, T val = T()>
auto make_vector(size_t d) {
    return vector<T>(d, val);
}

template <typename T, T val = T(), typename ...Ds>
auto make_vector(size_t d, Ds... ds) {
    return vector<decltype(make_vector<T, val>(ds...))>(d, make_vector<T, val>(ds...));
}

llong min(int a, llong b) {
    return min<llong>(a, b);
}

llong min(llong a, int b) {
    return min<llong>(a, b);
}

llong max(int a, llong b) {
    return max<llong>(a, b);
}

llong max(llong a, int b) {
    return max<llong>(a, b);
}

template <typename T>
void relmax(T& a, const T& b) {
    a = max(a, b);
}

template <typename T>
void relmin(T& a, const T& b) {
    a = min(a, b);
}

#endif //CONTESTSMTH_UTILS_H

#ifndef CONTESTSMTH_SEGTREE_H
#define CONTESTSMTH_SEGTREE_H

#include <functional>

template <typename T>
struct SegTree {
    vector<T> a;
    const function<T(T, T)> pull;
    T ZERO;

    SegTree(int n, function<T(T, T)> pull, T ZERO = T()) : pull(pull), ZERO(ZERO) {
        a.resize(4 * n);
    }

    template <typename SubT>
    SegTree(const vector<SubT>& b, function<T(T, T)> pull, T ZERO = T()) : pull(pull), ZERO(ZERO) {
        if (isz(b)) {
            a.resize(4 * isz(b));
            build(0, 0, isz(b), b);
        }
    }

    template <typename SubT>
    void build(int i, int l, int r, const vector<SubT>& b) {
        if (l + 1 == r) {
            a[i] = b[l];
        } else {
            int m = (l + r) >> 1;
            build(i * 2 + 1, l, m, b);
            build(i * 2 + 2, m, r, b);
            a[i] = pull(a[i * 2 + 1], a[i * 2 + 2]);
        }
    }

    void upd(int i, int l, int r, int qi, T qx) {
        if (l + 1 == r) {
            a[i] = qx;
        } else {
            int m = (l + r) >> 1;
            if (qi < m) {
                upd(i * 2 + 1, l, m, qi, qx);
            } else {
                upd(i * 2 + 2, m, r, qi, qx);
            }
            a[i] = pull(a[i * 2 + 1], a[i * 2 + 2]);
        }
    }

    void upd(int qi, int qx) {
        upd(0, 0, isz(a) >> 2, qi, qx);
    }

    T get(int i, int l, int r, int ql, int qr) {
        if (r <= ql || qr <= l) {
            return ZERO;
        }

        if (ql <= l && r <= qr) {
            return a[i];
        }
        int m = (l + r) >> 1;
        return pull(get(i * 2 + 1, l, m, ql, qr), get(i * 2 + 2, m, r, ql, qr));
    }

    T get(int ql, int qr) {
        return get(0, 0, isz(a) >> 2, ql, qr);
    }
};

#endif //CONTESTSMTH_SEGTREE_H


struct Solver {
    void solve() {
        string s;
        cin >> s;
        vector<pair<int, int>> a(isz(s));
        for (int i = 0; i < isz(s); i++) {
            if (s[i] == '(' || s[i] == ')') {
                a[i] = {1, 0};
            } else {
                a[i] = {1, 1};
            }
        }
        auto pull = [](pair<int, int> l, pair<int, int> r) -> pair<int, int> {
            if (l.first == 0) {
                return r;
            }
            if (r.first == 0) {
                return l;
            }
            int z = l.second ^ (l.first & 1) ^ 1;
            if (z != r.second) {
                return {l.first + r.first, l.second};
            }
            if (l.first > r.first) {
                return {l.first - r.first, l.second};
            }
            return {r.first - l.first, r.second ^ (l.first & 1)};
        };

        SegTree<pair<int, int>> st(a, pull);
        int q;
        cin >> q;
        for (int iq = 0; iq < q; iq++) {
            int l, r;
            cin >> l >> r;
            auto p = st.get(l - 1, r);
            cout << p.first / 2 << "\n";
        }
    }
};

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
    return 0;
}