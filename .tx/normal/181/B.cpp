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
        int n;
        cin >> n;
        auto z = make_vector<int>(2222, 2222);
        vector<pair<int, int>> ps;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x += 1111;
            y += 1111;
            z[x][y] = 1;
            ps.emplace_back(x, y);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            auto [x1, y1] = ps[i];
            for (int j = 0; j < i; j++) {
                auto [x2, y2] = ps[j];
                if ((x1 + x2) % 2 || (y1 + y2) % 2) {
                    continue;
                }
                ans += z[(x1 + x2) / 2][(y1 + y2) / 2];
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
    //cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
    return 0;
}