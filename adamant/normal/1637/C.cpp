#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    int cnt = 0, ok = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0 && i + 1 < n) {
            ans += (a[i] + 1) / 2;
            if(a[i] % 2) {
                cnt++;
            }
            ok |= a[i] > 1;
        }
    }
    if(!ok || (n == 3 && cnt > 0)) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
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