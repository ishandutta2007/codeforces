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
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto b = make_vector<int>(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = a[i][j] - '0';
                if (i) {
                    b[i][j] += b[i - 1][j];
                }
                if (j) {
                    b[i][j] += b[i][j - 1];
                }
                if (i && j) {
                    b[i][j] -= b[i - 1][j - 1];
                }
            }
        }
        auto get = [&](int x1, int y1, int x2, int y2) {
            if (x1 >= n || y1 >= m) {
                return 0;
            }
            x2 = min(x2, n - 1);
            y2 = min(y2, m - 1);
            int res = b[x2][y2];
            if (x1) {
                res -= b[x1 - 1][y2];
            }
            if (y1) {
                res -= b[x2][y1 - 1];
            }
            if (x1 && y1) {
                res += b[x1 - 1][y1 - 1];
            }
            return res;
        };

        int ans = n * m;

        for (int k = 2; k < 5001; k++) {
            int cur = 0;
            int p = n;
            if (p % k) {
                p += k - p % k;
            }
            int q = m;
            if (q % k) {
                q += k - q % k;
            }
            for (int i = 0; i < p; i += k) {
                for (int j = 0; j < q; j += k) {
                    int s = get(i, j, i + k - 1, j + k - 1);
                    s = min(s, k * k - s);
                    cur += s;
                }
            }
            ans = min(ans, cur);
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