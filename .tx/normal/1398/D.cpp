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
        int r, g, b;
        cin >> r >> g >> b;
        vector<int> rs(r), gs(g), bs(b);
        for (int i = 0; i < r; i++) {
            cin >> rs[i];
        }
        for (int i = 0; i < g; i++) {
            cin >> gs[i];
        }
        for (int i = 0; i < b; i++) {
            cin >> bs[i];
        }
        sort(rbegin(rs), rend(rs));
        sort(rbegin(gs), rend(gs));
        sort(rbegin(bs), rend(bs));

        auto d = make_vector<int>(r + 1, g + 1, b + 1);
        auto remax = [](int& a, int b) {
            a = max(a, b);
        };

        for (int ir = 0; ir <= r; ir++) {
            for (int ig = 0; ig <= g; ig++) {
                for (int ib = 0; ib <= b; ib++) {
                    if (ir) {
                        remax(d[ir][ig][ib], d[ir - 1][ig][ib]);
                    }
                    if (ig) {
                        remax(d[ir][ig][ib], d[ir][ig - 1][ib]);
                    }
                    if (ib) {
                        remax(d[ir][ig][ib], d[ir][ig][ib - 1]);
                    }
                    if (ir && ig) {
                        remax(d[ir][ig][ib], d[ir - 1][ig - 1][ib] + rs[ir - 1] * gs[ig - 1]);
                    }
                    if (ir && ib) {
                        remax(d[ir][ig][ib], d[ir - 1][ig][ib - 1] + rs[ir - 1] * bs[ib - 1]);
                    }
                    if (ig && ib) {
                        remax(d[ir][ig][ib], d[ir][ig - 1][ib - 1] + gs[ig - 1] * bs[ib - 1]);
                    }
                }
            }
        }

        cout << d[r][g][b] << "\n";
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