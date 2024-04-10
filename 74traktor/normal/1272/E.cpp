#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn], ans[maxn];
vector < int > g[maxn];
int inf = 1e9;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector < int > c, d;
    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2 == 0) c.push_back(i);
        else d.push_back(i);
        ans[i] = inf;
    }
    for (auto key : c) {
        if (key + a[key] <= n && a[key + a[key]] % 2 == 1) ans[key] = 1;
        if (key - a[key] >= 1 && a[key - a[key]] % 2 == 1) ans[key] = 1;
    }
    for (auto key : d) {
        if (key + a[key] <= n && a[key + a[key]] % 2 == 0) ans[key] = 1;
        if (key - a[key] >= 1 && a[key - a[key]] % 2 == 0) ans[key] = 1;
    }
    for (auto key : c) {
        if (ans[key] == 1) continue;
        if (key + a[key] <= n) g[key + a[key]].push_back(key);
        if (key - a[key] >= 1) g[key - a[key]].push_back(key);
    }
    set < pair < int, int > > Q;
    for (auto key : c) {
        Q.insert({ans[key], key});
    }
    while ((int)Q.size() > 0) {
        auto p = (*Q.begin());
        Q.erase(p);
        for (auto key : g[p.second]) {
            if (p.first + 1 < ans[key]) {
                Q.erase({ans[key], key});
                ans[key] = p.first + 1;
                Q.insert({ans[key], key});
            }
        }
    }
    for (int i = 1; i <= n; ++i) g[i] = {};
    for (auto key : d) {
        if (ans[key] == 1) continue;
        if (key + a[key] <= n) g[key + a[key]].push_back(key);
        if (key - a[key] >= 1) g[key - a[key]].push_back(key);
    }
    Q = {};
    for (auto key : d) {
        Q.insert({ans[key], key});
    }
    while ((int)Q.size() > 0) {
        auto p = (*Q.begin());
        Q.erase(p);
        for (auto key : g[p.second]) {
            if (p.first + 1 < ans[key]) {
                Q.erase({ans[key], key});
                ans[key] = p.first + 1;
                Q.insert({ans[key], key});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] != inf) cout << ans[i] << " ";
        else cout << -1 << " ";
    }
    cout << '\n';
    return 0;
}