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
        n *= 2;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
        }
        int c = 0;
        vector<int> w;
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(i);
        }
        int z = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            c++;
            st.erase(a[i]);
            if (a[i] == z) {
                w.push_back(c);
                c = 0;
                if (isz(st)) {
                    z = *rbegin(st);
                }
            }
        }

        auto d = make_vector<int>(isz(w) + 1, n + 1);
        d[0][0] = 1;
        for (int i = 0; i < isz(w); i++) {
            for (int j = 0; j <= n; j++) {
                d[i + 1][j] = d[i][j];
                if (i == isz(w) - 1 && j == n) {
                    j++;
                    j -= 1;
                }
                if (j >= w[i]) {
                    d[i + 1][j] |= d[i][j - w[i]];
                }
            }
        }
        if (d[isz(w)][n / 2]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
 //ngains