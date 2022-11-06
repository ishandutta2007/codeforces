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
        const int M = int(1e9) + 7;

        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        llong s = accumulate(begin(a), end(a), 0LL);
        if (s % n) {
            cout << "0\n";
            return;
        }
        s /= n;

        int cl = 0;
        int ce = 0;
        int cm = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < s) {
                cl++;
            } else if (a[i] == s) {
                ce++;
            } else {
                cm++;
            }
        }

        sort(begin(a), end(a));
        vector<llong> fac(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i % M;
        }

        auto mpow = [&](llong a, llong p) {
            llong res = 1;
            for (; p > 0; p >>= 1) {
                if (p & 1) {
                    res = res * a % M;
                }
                a = a * a % M;
            }
            return res;
        };

        auto ff = [&](int x, int y){
            map<int, int> c;
            for (int i = x; i < y; i++) {
                c[a[i]]++;
            }

            llong res = fac[y - x];
            for (auto [z, zz] : c) {
                res = res * mpow(fac[zz], M - 2) % M;
            }
            return res;
        };

        auto cc = [&](int n, int k) {
            return fac[n] * mpow(fac[k], M - 2) % M * mpow(fac[n - k], M - 2) % M;
        };
        if (ce == n) {
            cout << "1\n";
            return;
        }
        if (cl == 1 || cm == 1) {
            cout << ff(0, n) << "\n";
        } else {
            cout << ff(0, cl) * ff(n - cm, n) % M * 2 % M * cc(n, ce) % M << "\n";
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