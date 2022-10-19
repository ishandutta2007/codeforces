#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, h_st, m_st;
    cin >> n >> h_st >> m_st;
    int t_st = h_st * 60 + m_st;
    int ans = 24 * 60;
    while (n--) {
        int h, m;
        cin >> h >> m;
        int t = h * 60 + m;
        if (t < t_st) {
            ans = min(ans, 24 * 60 + t - t_st);
        } else {
            ans = min(ans, t - t_st);
        }
    }
    cout << ans / 60 << ' ' << ans % 60 << '\n';
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