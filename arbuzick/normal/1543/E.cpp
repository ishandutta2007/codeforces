#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
//#define _USE_MATH_DEFINE
using namespace std;

void solve() {
    int n;
    cin >> n;
    int nn = 1 << n;
    vector<vector<int>> g(nn), sl;
    vector<int> col(nn, 0), ans(nn, -1), ans2(nn, -1), s(nn, -1);
    for (int i = 0; i < nn / 2 * n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    s[0] = 0;
    sl.pb({0});
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u: g[v]) {
            if (s[u] == -1) {
                s[u] = s[v] + 1;
                q.push(u);
                if (s[u] == sl.size()) {
                    sl.pb({});
                }
                sl.back().pb(u);
            }
        }
    }
    ans[0] = ans2[0] = 0;
    for (int i = 0; i < sl[1].size(); ++i) {
        ans2[sl[1][i]] = 1 << i;
        ans[ans2[sl[1][i]]] = sl[1][i];
    }
    for (int i = 2; i < sl.size(); ++i) {
        for (auto u: sl[i]) {
            ans2[u] = 0;
            for (auto v: g[u]) {
                if (s[v] < s[u]) {
                    ans2[u] |= ans2[v];
                }
            }
            ans[ans2[u]] = u;
        }
    }
    for (int i = 0; i < nn; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        if ((1 << i) > n) {
            cout << -1 << '\n';
            return;
        } else if ((1 << i) == n) {
            break;
        }
    }
    for (int i = 0; i < nn; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                col[i] ^= j;
            }
        }
    }
    for (int i = 0; i < nn; ++i) {
        cout << col[ans2[i]] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}