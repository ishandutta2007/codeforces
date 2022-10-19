#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int pos = n;
    vector<int> ans(n);
    while (pos) {
        pos--;
        int val = ceil(sqrt(pos)) * ceil(sqrt(pos));
        for (int i = val - pos; i <= pos; ++i) {
            ans[i] = val - i;
        }
        pos = val - pos;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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