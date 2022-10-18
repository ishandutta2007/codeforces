#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n;
    cin >> n;
    int a[n];
    int cnt[n + 1][2];
    cnt[0][0] = cnt[0][1] = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[i + 1][a[i] ^ 1] = cnt[i][a[i] ^ 1];
        cnt[i + 1][a[i]] = cnt[i][a[i]] + 1;
    }
    int total[2] = {cnt[n][0], cnt[n][1]};
    int ans = n;
    for(int i = 0; i <= n; i++) {
        int A = cnt[i][1];
        int B = (total[0] - cnt[i][0]);
        ans = min(ans, max(A, B));
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
    cerr << clock() / double(CLOCKS_PER_SEC) << endl;
    //return 0;
}