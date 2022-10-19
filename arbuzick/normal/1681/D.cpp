#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    long long val = 1;
    for (int i = 0; i < n - 1; ++i) {
        val *= 10;
    }
    map<long long, int> dist;
    dist[x] = 0;
    queue<long long> q;
    q.push(x);
    while (!q.empty()) {
        long long v = q.front();
        q.pop();
        if (v >= val) {
            cout << dist[v] << '\n';
            return;
        }
        long long v2 = v;
        vector<int> used(10);
        while (v2) {
            used[v2 % 10] = 1;
            v2 /= 10;
        }
        for (int i = 2; i < 10; ++i) {
            if (used[i] && !dist.count(v * i)) {
                dist[v * i] = dist[v] + 1;
                q.push(v * i);
            }
        }
    }
    cout << -1 << '\n';
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