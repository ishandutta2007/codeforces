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
        int m;
        cin >> m;
        vector<vector<int>> a(m);
        map<int, int> a_cnt;
        for (int i = 0; i < m; i++) {
            int n;
            cin >> n;
            a[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                a_cnt[a[i][j]]++;
            }
        }

        for (auto [x, cnt] : a_cnt) {
            if (cnt % 2 != 0) {
                cout << "NO\n";
                return;
            }
        }

        auto ans = a;

        vector<set<pair<int, int>>> ss(m);
        map<int, set<int>> wh;

        for (int i = 0; i < m; i++) {
            map<int, vector<int>> z;
            for (int j = 0; j < isz(a[i]); j++) {
                z[a[i][j]].push_back(j);
            }
            for (auto& p : z) {
                while (isz(p.second) > 1) {
                    int x = p.second.back();
                    p.second.pop_back();
                    int y = p.second.back();
                    p.second.pop_back();
                    ans[i][x] = 0;
                    ans[i][y] = 1;
                }
                if (isz(p.second)) {
                    ss[i].insert({p.first, p.second[0]});
                    wh[p.first].insert(i);
                }
            }

            if (isz(ss[i]) % 2 != 0) {
                cout << "NO\n";
                return;
            }
        }

        for (int i = 0; i < m; i++) {
            while (isz(ss[i])) {
                auto [x, pos] = *begin(ss[i]);
                ss[i].erase(begin(ss[i]));
                wh[x].erase(i);
                ans[i][pos] = 0;
                int cur_ans = 1;
                while (true) {
                    int j = *begin(wh[x]);
                    auto [y, pos] = *ss[j].lower_bound({x, -1});
                    ss[j].erase({y, pos});
                    wh[y].erase(j);
                    ans[j][pos] = cur_ans;
                    cur_ans ^= 1;
                    if (j == i) {
                        break;
                    }
                    auto tt = *begin(ss[j]);
                    y = tt.first;
                    pos = tt.second;
                    ss[j].erase({y, pos});
                    wh[y].erase(j);
                    ans[j][pos] = cur_ans;
                    cur_ans ^= 1;
                    x = y;
                }
            }
        }

        cout << "YES\n";
        for (int i = 0; i < m; i++) {
            for (int j : ans[i]) {
                if (j == 0) {
                    cout << 'L';
                } else {
                    cout << 'R';
                }
            }
            cout << "\n";
        }
    }
};

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
#endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
}