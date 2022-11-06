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
        string s;
        cin >> n >> s;
        int b = 0;
        int mxb = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                b++;
            } else {
                b--;
            }
            relmax(mxb, b);
        }
        int h = 2 * mxb + 1;
        int p = n;
        for (int i = 1; i < n; i++) {
            if (s[i] == ']' && s[i - 1] == '[') {
                p += 3;
            }
        }
        int w = p;
        vector<string> a(h, string(p, ' '));
        int ch = h;
        for (int j = 0, i = 0; j < w; i++, j++) {
            if (i && s[i] == ']' && s[i - 1] == '[') {
                j += 3;
            }
            int b = (h - ch) / 2;
            a[b][j] = '+';
            if (s[i] == '[') {
                a[b][j + 1] = '-';
            } else {
                a[b][j - 1] = '-';
            }
            for (int i = 0; i < ch - 2; i++) {
                a[b + i + 1][j] = '|';
            }
            a[b + ch - 1][j] = '+';
            if (s[i] == '[') {
                a[b + ch - 1][j + 1] = '-';
            } else {
                a[b + ch - 1][j - 1] = '-';
            }

            if (i + 1 < n && s[i] == s[i + 1]) {
                if (s[i] == '[') {
                    ch -= 2;
                } else {
                    ch += 2;
                }
            }
        }
        for (int i = 0; i < isz(a); i++) {
            cout << a[i] << "\n";
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