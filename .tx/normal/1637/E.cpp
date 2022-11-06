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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        set<pair<int, int>> bad;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            bad.emplace(x, y);
        }

        auto is_bad = [&](int x, int y) {
            if (x > y) {
                swap(x, y);
            }
            return x == y || bad.find({x, y}) != bad.end();
        };

        llong ans = -1;

        map<int, vector<int>> bcnt;

        for (auto [x, c] : cnt) {
            bcnt[c].emplace_back(x);
        }

        vector<pair<int, vector<int>>> z;

        for (auto& p : bcnt) {
            sort(rbegin(p.second), rend(p.second));
            z.push_back(p);
        }

        for (int i = 0; i < isz(z); i++) {
            const auto& a = z[i].second;
            for (int j = i; j < isz(z); j++) {
                const auto& b = z[j].second;
                set<pair<int, pair<int, int>>> s;
                s.insert({a[0] + b[0], {0, 0}});
                while (isz(s)) {
                    auto p = *rbegin(s);
                    s.erase(p);
                    auto [x, y] = p.second;
                    if (!is_bad(a[x], b[y])) {
                        ans = max(ans, 1LL * (a[x] + b[y]) * (z[i].first + z[j].first));
                        break;
                    }
                    if (x + 1 < isz(a)) {
                        s.insert({a[x + 1] + b[y], {x + 1, y}});
                    }
                    if (y + 1 < isz(b)) {
                        s.insert({a[x] + b[y + 1], {x, y + 1}});
                    }
                }
            }
        }

        cout << ans << "\n";
    }
};

int main(int argc, char** argv) {
#ifdef VSE
    if (argc == 2) assert(freopen(argv[1], "r", stdin));
#endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
}