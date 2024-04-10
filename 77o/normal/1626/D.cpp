#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int ans = n * 3;
    for (int b1 = 0; b1 < 19; b1++) {
        for (int b2 = 0; b2 < 19; b2++) {
            int cur = 1;
            int s1 = 1 << b1;
            while (cur <= n && cnt[cur] <= s1) {
                s1 -= cnt[cur++];
            }
            int s2 = 1 << b2;
            while (cur <= n && cnt[cur] <= s2) {
                s2 -= cnt[cur++];
            }
            int suf = 0;
            while (cur <= n)
                suf += cnt[cur++];
            int s3 = 1;
            while (s3 < suf)
                s3 <<= 1;
            ans = min(ans, s1 + s2 + s3 - suf);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}