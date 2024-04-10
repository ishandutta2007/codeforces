#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int64_t &e : a) cin >> e;
        int64_t mn[2] = {(int64_t) 2e9, (int64_t) 2e9};
        int64_t sum[2] = {0, 0};
        int64_t cnt[2] = {0, 0};
        int64_t ans = 1e18;
        for (int i = 0; i < n; i++) {
            sum[i % 2] += a[i];
            cnt[i % 2]++;
            mn[i % 2] = min(mn[i % 2], a[i]);
            if (i == 0) continue;
            ans = min(ans, (sum[0] + (n - cnt[0]) * mn[0]) + (sum[1] + (n - cnt[1]) * mn[1]));
        } 
        cout << ans << '\n';
    }   

    return 0;
}