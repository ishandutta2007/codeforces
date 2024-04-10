#include <bits/stdc++.h>

#define int int64_t

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int ans = 1e18;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < n; j++) {
        vector<int> b(n);
        int cur = 0;
        for(int i = 1; i < n; i++) {
            if(j + i < n) {
                int t = b[j + i - 1] / a[j + i] + 1;
                cur += t;
                b[j + i] = a[j + i] * t;
            }
            if(j - i >= 0) {
                int t = b[j - i + 1] / a[j - i] + 1;
                cur += t;
                b[j - i] = a[j - i] * t;
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    t = 1;// cin >> t;
    while(t--) {
        solve();
    }
}