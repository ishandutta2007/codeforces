#include <bits/stdc++.h>

using namespace std;

void solve() {
    int d, sum;
    cin >> d >> sum;
    vector<int> mn(d), mx(d);
    for (int i = 0; i < d; ++i) {
        cin >> mn[i] >> mx[i];
        sum -= mn[i];
    }
    if (sum < 0) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < d; ++i) {
        int nw = min(mx[i] - mn[i], sum);
        sum -= nw;
        mn[i] += nw;
    }
    if (sum > 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto val : mn) {
            cout << val << ' ';
        }
        cout << '\n';
    }
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