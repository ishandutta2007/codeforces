#include <bits/stdc++.h>

using namespace std;

const int lg = 30;

long long calc(int l1, int l2) {
    long long ans = 0;
    for (int i = 0; i <= lg; ++i) {
        for (int j = 0; j <= lg; ++j) {
            bool ch = true;
            for (int k = lg - 1; k >= lg - i && k >= lg - j; --k) {
                if ((l1 & (1 << k)) && (l2 & (1 << k))) {
                    ch = false;
                    break;
                }
            }
            if (!ch) {
                break;
            }
            if (i < lg && !(l1 & (1 << (lg - i - 1)))) {
                continue;
            }
            if (j < lg && !(l2 & (1 << (lg - j - 1)))) {
                continue;
            }
            // cout << i << ' ' << j << '\n';
            long long add = 1;
            if (i < j) {
                for (int k = lg - i - 2; k >= lg - j; --k) {
                    if (!(l2 & (1 << k))) {
                        add *= 2;
                    }
                }
                if (j != lg) {
                    add *= 2;
                }
            }
            if (j < i) {
                for (int k = lg - j - 2; k >= lg - i; --k) {
                    if (!(l1 & (1 << k))) {
                        add *= 2;
                    }
                }
                if (i != lg) {
                    add *= 2;
                }
            }
            for (int k = lg - max(i, j) - 2; k >= 0; --k) {
                add *= 3;
            }
            ans += add;
        }
    }
    return ans;
}

void solve() {
    int l, r;
    cin >> l >> r;
    long long ans = calc(r, r);
    if (l > 0) {
        ans = ans - calc(l - 1, r) * 2 + calc(l - 1, l - 1);
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