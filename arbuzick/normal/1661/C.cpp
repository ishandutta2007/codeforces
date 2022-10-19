#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    long long ans = inf;
    for (int val = mx; val <= mx + 1; ++val) {
        long long sum = 0;
        long long odd = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 != val % 2) {
                odd++;
            }
            sum += (val - a[i]) / 2 * 2;
        }
        long long even = 0;
        if (sum / 2 < odd - 1) {
            ans = min(ans, odd * 2 - 1);
        } else {
            if (odd != 0) {
                even += odd - 1;
                sum -= 2 * (odd - 1);
                odd += sum / 6 * 2;
                even += sum / 6 * 2;
                sum %= 6;
                if (sum == 4) {
                    odd++;
                    even += 2;
                    sum = 0;
                }
                if (sum >= 3) {
                    odd++;
                    even++;
                    sum -= 3;
                }
                if (sum == 1) {
                    odd++;
                    even++;
                } else if (sum == 2) {
                    even++;
                }
            } else {
                odd += sum / 6 * 2;
                even += sum / 6 * 2;
                sum %= 6;
                if (sum >= 3) {
                    odd++;
                    even++;
                    sum -= 3;
                }
                if (sum == 1) {
                    odd++;
                } else if (sum == 2) {
                    odd++;
                    even++;
                }
            }
            ans = min(ans, odd + even);
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