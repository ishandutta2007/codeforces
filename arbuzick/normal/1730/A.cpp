#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    map<int, int> count;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        a--;
        count[a]++;
    }
    int ans = 0;
    for (auto [a, cnt] : count) {
        ans += min(c, cnt);
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