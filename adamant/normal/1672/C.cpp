#include <bits/stdc++.h>

#define int int64_t

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int mn = n, mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0 && a[i] == a[i - 1]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if(mx == 0 || mx == mn) {
        cout << 0 << "\n";
    } else {
        cout << max<int>(1, mx - mn - 1) << "\n";
    }
    
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