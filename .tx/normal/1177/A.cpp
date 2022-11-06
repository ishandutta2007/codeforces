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

#endif //CONTESTSMTH_UTILS_H


struct Solver {
    void solve() {
        llong k;
        cin >> k;
        if (k <= 9) {
            cout << k << "\n";
            return;
        }
        vector<llong> p(18);
        p[0] = 1;
        for (int i = 1; i < isz(p); i++) {
            p[i] = p[i - 1] * 10;
        }
        auto get = [&p](llong x) {
            llong res = 0;
            int i;
            for (i = 1; p[i] <= x; i++) {
                res += 1LL * i * (p[i] - p[i - 1]);
            }
            res += 1LL * i * (x - p[i - 1] + 1);
            return res;
        };
        llong l = 0, r = llong(1e15);
        while (l + 1 < r) {
            llong m = (l + r) >> 1;
            llong z = get(m);
            if (z < k) {
                l = m;
            } else {
                r = m;
            }
        }
        llong z = get(r - 1);
        cout << to_string(r)[k - z - 1] << "\n";
    }
};

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
    return 0;
}