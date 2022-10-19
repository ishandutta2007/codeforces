#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    int ans = abs(l - r) / 2;
    vector<int> cnt_l(n), cnt_r(n);
    for (int i = 0; i < l; ++i) {
        int c;
        cin >> c;
        cnt_l[c - 1]++;
    }
    for (int i = 0; i < r; ++i) {
        int c;
        cin >> c;
        cnt_r[c - 1]++;
    }
    int ch = abs(l - r) / 2;
    int kek = n;
    for (int i = 0; i < n; ++i) {
        kek -= min(cnt_l[i], cnt_r[i]) * 2;
        if (cnt_l[i] < cnt_r[i]) {
            cnt_r[i] -= cnt_l[i];
            cnt_l[i] = 0;
        } else {
            cnt_l[i] -= cnt_r[i];
            cnt_r[i] = 0;
        }
        while (ch > 0) {
            if (l < r) {
                if (cnt_r[i] <= 1) {
                    break;
                }
                ch--;
                cnt_r[i] -= 2;
                kek -= 2;
            } else {
                if (cnt_l[i] <= 1) {
                    break;
                }
                ch--;
                cnt_l[i] -= 2;
                kek -= 2;
            }
        }
    }
    cout << ans + kek / 2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}