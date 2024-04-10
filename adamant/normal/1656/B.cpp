#include <bits/stdc++.h>

#define int int64_t
#define all(x) begin(x), end(x)

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, int> cnt;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans += cnt[a[i] + k] + cnt[a[i] - k];
        cnt[a[i]]++;
    }
    cout << (ans ? "YES" : "NO") << "\n";
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