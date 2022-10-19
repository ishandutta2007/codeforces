#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5, sq = 357;

int a[maxn];

int cnt1[maxn * (sq + 10)], cnt2[maxn * (sq + 10)];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = max(0, n - 2);
    for (int dl = -sq; dl <= sq; ++dl) {
        map<int, int> cnt;
        int vl = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < vl) {
                cnt2[vl - a[i]]++;
                ans = min(ans, n - cnt2[vl - a[i]]);
            } else {
                cnt1[a[i] - vl]++;
                ans = min(ans, n - cnt1[a[i] - vl]);
            }
            vl += dl;
        }
        vl = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < vl) {
                cnt2[vl - a[i]]--;
            } else {
                cnt1[a[i] - vl]--;
            }
            vl += dl;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= i + sq && j < n; ++j) {
            if ((a[i] - a[j]) % (j - i) == 0) {
                if ((a[i] - a[j]) / (j - i) < 0) {
                    cnt2[(a[i] - a[j]) / (i - j)]++;
                    ans = min(ans, n - cnt2[(a[i] - a[j]) / (i - j)] - 1);
                } else {
                    cnt1[(a[i] - a[j]) / (j - i)]++;
                    ans = min(ans, n - cnt1[(a[i] - a[j]) / (j - i)] - 1);
                }
            }
        }
        for (int j = i + 1; j <= i + sq && j < n; ++j) {
            if ((a[i] - a[j]) % (j - i) == 0) {
                if ((a[i] - a[j]) / (j - i) < 0) {
                    cnt2[(a[i] - a[j]) / (i - j)]--;
                } else {
                    cnt1[(a[i] - a[j]) / (j - i)]--;
                }
            }
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}