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


struct Solver {
    void solve() {
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        vector<pair<int, int>> ps(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ps[i] = pair(a[i], i);
        }
        sort(begin(ps), end(ps));
        vector<tuple<int, int, int>> es;
        vector<int> done(n);
        for (int ips = 0; ips < isz(ps); ips++) {
            auto [x, p] = ps[ips];
            done[p] = 1;
            int cg = x;
            int cm = x;
            int cp = p;
            while (cp > 0) {
                cg = gcd(cg, a[cp - 1]);
                cm = min(cm, a[cp - 1]);
                if (cg != cm) {
                    break;
                }
                --cp;
                es.emplace_back(cm, p, cp);
                if (done[cp]) {
                    break;
                }
                done[cp] = 1;
            }

            cp = p;
            cg = x;
            cm = x;
            while (cp + 1 < n) {
                cg = gcd(cg, a[cp + 1]);
                cm = min(cm, a[cp + 1]);
                if (cg != cm) {
                    break;
                }
                ++cp;
                es.emplace_back(cm, p, cp);
                if (done[cp]) {
                    break;
                }
                done[cp] = 1;
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            es.emplace_back(p, i, i + 1);
        }

        struct DSU {
            vector<int> a;
            vector<int> r;

            DSU(int n) {
                a.resize(n);
                iota(begin(a), end(a), 0);
                r.assign(n, 1);
            }

            int get(int x) {
                return a[x] == x ? x : a[x] = get(a[x]);
            }

            void unite(int x, int y) {
                x = get(x);
                y = get(y);
                if (x == y) {
                    return;
                }
                if (r[x] < r[y]) {
                    a[x] = y;
                } else {
                    a[y] = x;
                    if (r[x] == r[y]) {
                        r[x]++;
                    }
                }
            }
        };

        DSU dsu(n);
        sort(begin(es), end(es));
        llong ans = 0;
        for (auto [w, x, y] : es) {
            if (dsu.get(x) != dsu.get(y)) {
                ans += w;
                dsu.unite(x, y);
            }
        }

        cout << ans << "\n";
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