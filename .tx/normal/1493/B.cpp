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
        int h, m;
        cin >> h >> m;
        string s;
        cin >> s;
        int cm = ((s[0] - '0') * 10 + s[1] - '0') * m + (s[3] - '0') * 10 + s[4] - '0';
        set<int> b = {3, 4, 6, 7, 9};
        map<int, int> inv;
        inv[0] = 0;
        inv[1] = 1;
        inv[2] = 5;
        inv[5] = 2;
        inv[8] = 8;
        for (;; cm++) {
            int x = cm / m % h;
            int y = cm % m;

            vector<int> d = {x % 10, x / 10 % 10, y % 10, y / 10 % 10};
            bool ok = true;
            for (int i : d) {
                if (b.count(i)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }

            int nx = inv[y % 10] * 10 + inv[y / 10 % 10];
            int ny = inv[x % 10] * 10 + inv[x / 10 % 10];
            if (nx < h && ny < m) {
                if (x < 10) {
                    cout << 0;
                }
                cout << x;
                cout << ":";
                if (y < 10) {
                    cout << 0;
                }
                cout << y;
                cout << "\n";
                return;
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
    cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
    return 0;
}