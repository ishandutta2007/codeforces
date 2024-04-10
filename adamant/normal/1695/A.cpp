#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 2e5 + 42;
const int inf = 1e16;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int mx = -1e9;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    int ans = n * m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == mx) {
                ans = min(ans, max(i + 1, n - i) * max(j + 1, m - j));
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}