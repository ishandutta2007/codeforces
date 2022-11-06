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
void readv(vector<T>& v) {
    for (T& t : v) {
        cin >> t;
    }
}

template  <typename T>
void writev(const vector<T>& v, const T& add = T(), const string& delim = " ", bool end_line = true) {
    for (const T& t : v) {
        cout << (t + add) << delim;
    }
    if (end_line) {
        cout << "\n";
    }
}

#endif //CONTESTSMTH_UTILS_H


struct Solver {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        readv(a);
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                a[i] = abs(a[i]);
            } else {
                a[i] = -abs(a[i]);
            }
        }
        writev(a);
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