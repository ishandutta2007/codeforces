#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 5e5 + 5;
vector < int > g[maxn];
map < vector < int >, int > cnt;
int c[maxn];

inline int gcd(int x, int y) {
    while (x > 0 && y > 0) {
        int d = x % y;
        x = y, y = d;
    }
    return x + y;
}

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) g[i] = {};
    cnt.clear();
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
        if ((int)g[i].size() != 0) cnt[g[i]] += c[i];
    }
    int ans = 0;
    for (auto key : cnt) ans = gcd(ans, key.second);
    cout << ans << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}