#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        if(a[i] % x == 0 && cnt[a[i] / x]) {
            cnt[a[i] / x]--;
        } else {
            cnt[a[i]]++;
        }
    }
    int ans = 0;
    for(auto it: cnt) {
        ans += it.second;
    }
    cout << ans << "\n";
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