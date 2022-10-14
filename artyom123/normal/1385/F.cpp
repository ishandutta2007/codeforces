#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n);
        vector<pair<int, int>> sz(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        for (int i = 0; i < n; i++) {
            sz[i] = {g[i].size(), i};
        }
        sort(all(sz));
        vector<int> p(n);
        vector<int> usd(n);
        int ans = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (sz[i].fi == 1) q.push(sz[i].se);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            usd[v] = 1;
            for (auto to : g[v]) {
                if (!usd[to]) {
                    p[to]++;
                    if (p[to] % k == 0) {
                        ans++;
                        if (g[to].size() - p[to] == 1) {
                            q.push(to);
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}