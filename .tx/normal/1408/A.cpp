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

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (T& t : v) {
        is >> t;
    }
    return is;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const T& t : v) {
        os << t << " ";
    }
    return os;
}

#endif //CONTESTSMTH_UTILS_H


struct Solver {
    void solve() {
        int n;
        cin >> n;
        auto a = make_vector<int>(3, n);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        vector<int> ans(n);
        ans[0] = a[0][0];
        for (int i = 1; i + 1 < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (a[j][i] != ans[i - 1]) {
                    ans[i] = a[j][i];
                    break;
                }
            }
        }

        for (int j = 0; j < 3; j++) {
            if (ans[n - 2] != a[j][n - 1] && ans[0] != a[j][n - 1]) {
                ans[n - 1] = a[j][n - 1];
                break;
            }
        }

        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
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