#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int x[k];
    int time[n];
    memset(time, 0x3F, sizeof(time));
    for(int i = 0; i < k; i++) {
        cin >> x[i];
        time[x[i] - 1] = 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cur = 1e9;
        for(int j = 0; j < n; j++) {
            if(time[j] == 0) {
                cur = min(cur, abs(i - j) + 1);
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
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