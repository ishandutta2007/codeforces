#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int maxn = 2e5 + 42;

void solve() {
    int n, k;
    cin >> n >> k;
    int x[n], y[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int g[n][n];
    memset(g, 0, sizeof(g));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k) {
                g[i][j] = 1;
            }
        }
        if(accumulate(g[i], g[i] + n, 0) == n) {
            cout << 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}