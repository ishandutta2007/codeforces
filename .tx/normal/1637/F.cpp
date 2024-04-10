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
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        int r = max_element(begin(h), end(h)) - begin(h);
        vector<int> mx(n);
        vector<vector<int>> us(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            mx[v] = h[v];
            for (int u : g[v]) {
                if (u != p) {
                    us[v].emplace_back(u);
                    dfs(u, v);
                    mx[v] = max(mx[v], mx[u]);
                }
            }
            sort(begin(us[v]), end(us[v]), [&](int x, int y) { return mx[x] > mx[y]; });
        };
        dfs(r, -1);

        auto hu = h;
        sort(begin(hu), end(hu));
        hu.resize(unique(begin(hu), end(hu)) - begin(hu));
        reverse(begin(hu), end(hu));
        vector<int> zz;
        vector<int> pos(n);
        int cur = 2;
        map<int, queue<int>> q;
        q[mx[r]].push(r);
        for (int ch : hu) {
            while (isz(q[ch])) {
                int v = q[ch].front();
                q[ch].pop();
                while (pos[v] < isz(us[v]) && mx[us[v][pos[v]]] == ch) {
                    q[ch].push(us[v][pos[v]]);
                    pos[v]++;
                    if (v == r && pos[v] > 2 || v != r && pos[v] > 1) {
                        cur++;
                    }
                }
                if (pos[v] < isz(us[v])) {
                    q[mx[us[v][pos[v]]]].push(v);
                }
            }
            zz.emplace_back(cur);
        }

        llong ans = 1LL * zz[0] * hu[0];
        int cc = zz[0];
        for (int i = 1; i < isz(hu); i++) {
            ans += max(0, zz[i] - cc) * 1LL * hu[i];
            cc = max(cc, zz[i]);
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
    // cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
}