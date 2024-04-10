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
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> bg(n), wg(n);
    while (m--) {
        int u, v, t;
        cin >> u >> v >> t; u--; v--;
        if (t == 0) bg[v].pb(u);
        else wg[v].pb(u);
    }
    vector<int> b(n, INF), w(n, INF), dp(n, INF);
    dp[n - 1] = w[n - 1] = b[n - 1] = 0;
    queue<int> q;
    q.push(n - 1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &to : bg[v]) {
            if (b[to] != INF) continue;
            b[to] = dp[v] + 1;
            if (max(b[to], w[to]) != INF) {
                q.push(to);
                dp[to] = max(b[to], w[to]);
            }
        }
        for (auto &to : wg[v]) {
            if (w[to] != INF) continue;
            w[to] = dp[v] + 1;
            if (max(b[to], w[to]) != INF) {
                q.push(to);
                dp[to] = max(b[to], w[to]);
            }
        }
    }
    cout << (dp[0] == INF ? -1 : dp[0]) << "\n";
    for (int i = 0; i < n; i++) {
        if (b[i] > w[i]) cout << 0;
        else cout << 1;
    }
    return 0;
}