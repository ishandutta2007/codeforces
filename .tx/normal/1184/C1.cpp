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
        int n;
        cin >> n;
        n = 4 * n + 1;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }

        for (int i = 0; i < n; i++) {
            auto zx1 = a[i].first;
            for (int j = i + 1; j < n; j++) {
                auto zx2 = a[j].first;
                for (int b = 0; b < n; b++) {
                    auto zy1 = a[b].second;
                    for (int z = b + 1; z < n; z++) {
                        auto zy2 = a[z].second;
                        int x1 = min(zx1, zx2);
                        int x2 = max(zx1, zx2);
                        int y1 = min(zy1, zy2);
                        int y2 = max(zy1, zy2);
                        pair<int, int> no = {-1, -1};
                        int cno = 0;
                        for (int k = 0; k < n; k++) {
                            auto [x, y] = a[k];
                            bool ok = true;
                            if (x == x1 || x == x2) {
                                if (y < y1 || y > y2) {
                                    ok = false;
                                }
                            } else if (y == y1 || y == y2) {
                                if (x < x1 || x > x2) {
                                    ok = false;
                                }
                            } else {
                                ok = false;
                            }
                            if (!ok) {
                                cno++;
                                no = {x, y};
                            }
                        }
                        if (cno == 1) {
                            cout << no.first << " " << no.second << "\n";
                            return;
                        }
                    }
                }
            }
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
    //cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
    return 0;
}