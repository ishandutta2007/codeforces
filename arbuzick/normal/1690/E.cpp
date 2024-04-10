#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long ans = 0;
    vector<int> cnt(k);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i] / k;
        cnt[a[i] % k]++;
    }
    set<int> s;
    for (int i = 0; i < k; ++i) {
        s.insert(i);
    }
    for (int i = 0; i < k; ++i) {
        while (cnt[i] > 0) {
            auto it = s.lower_bound(k - i);
            if (it == s.end()) {
                it = s.begin();
            }
            if (cnt[i] < 2 && *it == i) {
                it++;
                if (it == s.end()) {
                    it = s.begin();
                }
            }
            int p = *it;
            s.erase(p);
            int vl = min(cnt[i], cnt[p]);
            if (i == p) {
                vl /= 2;
            }
            ans += ((i + p) / k) * 1LL * vl;
            cnt[i] -= vl;
            cnt[p] -= vl;
            if (cnt[p] > 0) {
                s.insert(p);
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}