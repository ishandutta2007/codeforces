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
        string ab = "abacaba";
        int n;
        string s;
        cin >> n >> s;
        auto is = [&](int i) {
            if (i + 7 > n) {
                return false;
            }
            return s.substr(i, 7) == ab;
        };
        auto cntm = [&](){
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (is(i)) {
                    res++;
                }
            }
            return res;
        };
        auto isq = [&](int i) {
            if (i + 7 > n) {
                return false;
            }
            for (int j = 0; j < 7; j++) {
                if (s[i + j] != '?' && s[i + j] != ab[j]) {
                    return false;
                }
            }
            return true;
        };
        vector<int> qs;
        auto dom = [&](int i) {
            for (int j = 0; j < 7; j++) {
                if (s[i + j] == '?') {
                    qs.push_back(i + j);
                    s[i + j] = ab[j];
                }
            }
        };

        auto unm = [&]() {
            while (isz(qs)) {
                s[qs.back()] = '?';
                qs.pop_back();
            }
        };

        int cnt = cntm();
        if (cnt > 1) {
            cout << "No\n";
            return;
        }

        if (cnt == 0) {
            for (int i = 0; i < n; i++) {
                if (isq(i)) {
                    dom(i);
                    if (cntm() == 1) {
                        break;
                    }
                    unm();
                }
            }
        }

        cnt = cntm();
        if (cnt != 1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (char c : s) {
                cout << (c == '?' ? 'z' : c);
            }
            cout << "\n";
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
 //pyhcxd