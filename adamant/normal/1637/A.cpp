#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    int a[n];
    int mx[n + 2], mn[n + 2];
    mx[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx[i + 1] = max(mx[i], a[i]);
    }
    mn[n + 1] = 1e9 + 7;
    for(int i = n - 1; i > 0; i--) {
        mn[i + 1] = min(mn[i + 2], a[i]);
        if(mx[i] > mn[i + 1]) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
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
}