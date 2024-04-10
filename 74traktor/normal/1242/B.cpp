#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

int const maxn = 1e5 + 5;
gp_hash_table < int, int > g[maxn];
int w[maxn];
int dels[maxn];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    set < pair < int, int > > Q;
    for (int i = 1; i <= n; ++i) w[i] = 1;
    w[1] = 0;
    for (int i = 1; i <= n; ++i) Q.insert({w[i], i});
    unordered_set < int > f;
    for (int i = 2; i <= n; ++i) f.insert(i);
    while ((int)Q.size() > 0) {
        auto p = (*Q.begin());
        ans += p.first;
        v = p.second;
        int ptr = 1;
        Q.erase(p);
        if (f.find(v) != f.end()) f.erase(v);
        for (auto key : f) {
            if (g[v].find(key) == g[v].end()) {
                dels[ptr++] = key;
            }
        }
        for (int i = 1; i < ptr; ++i) {
            Q.erase({1, dels[i]});
            Q.insert({0, dels[i]});
            f.erase(dels[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}