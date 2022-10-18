#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = a[n - 1] - a[0];
    for(int i = 0; i < n; i++) {
        if(i + 1 < n) {
            ans = max(ans, a[i] - a[i + 1]);
            if(i > 0) {
                ans = max(ans, a[i] - a[0]);
            }
            ans = max(ans, a[n - 1] - a[i]);
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}