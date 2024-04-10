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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        int g = 0;
        for (int i : a) {
            g = gcd(i, g);
        }
        if (a.front() < 0 || a.back() / g > 300) {
            cout << "NO\n";
            return;
        }
        while (isz(a) <= 300) {
            vector<int> b;
            for (int i = 0; i < isz(a); i++) {
                for (int j = i + 1; j < isz(a); j++) {
                    int x = a[j] - a[i];
                    auto it = lower_bound(begin(a), end(a), x);
                    if (it == a.end() || *it != x) {
                        b.push_back(x);
                    }
                }
            }
            if (!isz(b)) {
                break;
            }
            sort(begin(b), end(b));
            b.resize(unique(begin(b), end(b)) - begin(b));
            a.insert(a.end(), b.begin(), b.end());
            inplace_merge(begin(a), end(a) - isz(b), end(a));
        }
        if (isz(a) <= 300) {
            cout << "YES\n";
            cout << a.size() << "\n";
            for (int i : a) {
                cout << i << " ";
            }
            cout << "\n";
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