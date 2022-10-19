#include <bits/stdc++.h>

using namespace std;

const int mod = 32768;

vector<int> g[mod];

int d[mod];

void solve() {
    for (int i = 0; i < mod; ++i) {
        g[(i + 1) % mod].push_back(i);
        g[(i * 2) % mod].push_back(i);
        d[i] = -1;
    }
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (d[u] == -1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cout << d[a] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}