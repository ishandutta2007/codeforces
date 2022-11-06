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
        int n, k;
        cin >> n >> k;
        auto a = make_vector<int>(n, n);
        for (int j = 0; k && j < n; j++) {
            for (int i = 0; k && i < n; i++) {
                a[i][(i + j) % n] = 1;
                k--;
            }
        }
        int MXR = 0;
        int MNR = 1e9;
        for (int i = 0; i < n; i++) {
            int c = count(begin(a[i]), end(a[i]), 1);
            MXR = max(MXR, c);
            MNR = min(MNR, c);
        }

        int MXC = 0;
        int MNC = 1e9;
        for (int j = 0; j < n; j++) {
            int c = 0;
            for (int i = 0; i < n; i++) {
                c += a[i][j];
            }
            MXC = max(MXC, c);
            MNC = min(MNC, c);
        }

        int ans = (MXR - MNR) * (MXR - MNR) + (MXC - MNC) * (MXC - MNC);
        cout << ans << "\n";
        for (auto& i : a) {
            for (int j : i) {
                cout << j;
            }
            cout << "\n";
        }
    }
};

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
#endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
}