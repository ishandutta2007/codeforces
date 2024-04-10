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
        const int A = int(1e6);
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> l, r;
        tree<pair<int, int>> t;
        vector<tuple<int, int, int>> hor(n);
        int cz = 0;
        for (int i = 0; i < n; i++) {
            int y, lx, rx;
            cin >> y >> lx >> rx;
            hor[i] = {y, lx, rx};
            if (lx <= 0 && rx >= A) {
                cz++;
            }
            if (lx <= 0) {
                l.emplace_back(rx, i);
                t.insert({y, i});
            } else {
                if (rx >= A) {
                    r.emplace_back(lx, i);
                }
            }
        }
        sort(rbegin(l), rend(l));
        sort(rbegin(r), rend(r));

        vector<pair<int, pair<int, int>>> z;
        for (int i = 0; i < m; i++) {
            int x, ly, ry;
            cin >> x >> ly >> ry;
            z.push_back({x, {ly, ry}});
            if (ly <= 0 && ry >= A) {
                cz++;
            }
        }

        sort(begin(z), end(z));
        llong ans = 0;
        for (auto& p : z) {
            int x = p.first;
            int ly = p.second.first;
            int ry = p.second.second;

            while (isz(l) && l.back().first < x) {
                int y = get<0>(hor[l.back().second]);
                t.erase(pair(y, l.back().second));
                l.pop_back();
            }
            while (isz(r) && r.back().first <= x) {
                int y = get<0>(hor[r.back().second]);
                t.insert(pair(y, r.back().second));
                r.pop_back();
            }

            int cans = 0;
            if (ly <= 0) {
                cans = t.order_of_key(pair(ry, int(1e9)));
            } else {
                int q = t.order_of_key(pair(ly, -int(1e9)));
                cans = isz(t) - q;
            }

            ans += cans;
        }
        cout << ans + cz + 1 << "\n";
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