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
        string s;
        cin >> n >> s;
        set<char> op;
        for (char c : s) {
            op.insert(c);
        }
        vector<string> a;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            string t;
            cin >> t;
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (s[j] != '*' && s[j] != t[j]) {
                    ok = false;
                    break;
                }
                if (s[j] == '*' && op.count(t[j])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                a.push_back(t);
            }
        }

        m = isz(a);

        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (op.count(c)) {
                continue;
            }
            bool ok = true;
            for (auto& s : a) {
                if (!count(begin(s), end(s), c)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans++;
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
 //cjshxl