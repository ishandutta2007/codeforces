#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    map<int, int> left, right;
    for (int i = 0; i < l; i++) {
        int x;
        cin >> x;
        left[x]++;
    }
    for (int i = 0; i < r; i++) {
        int x;
        cin >> x;
        right[x]++;
        if (left[x] && right[x]) {
            left[x]--;
            right[x]--;
            l--;
            r--;
            i--;
        }
    }
    int ans = 0;
    if (l > r) {
        for (auto &pp : left) {
            while (pp.second >= 2 && l != r) {
                pp.second -= 2;
                ans++;
                l -= 2;
                if (l == r)
                    break;
            }
        }
    }
    if (r > l) {
        for (auto &pp : right) {
            while (pp.second >= 2 && l != r) {
                pp.second -= 2;
                ans++;
                r -= 2;
                if (l == r)
                    break;
            }
        }
    }
    ans += abs(r - l) / 2;
    ans += (l + r) / 2;
    cout << ans << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}