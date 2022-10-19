#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n % 2 == 1) {
        cout << "Mike\n";
        return;
    }
    array<pair<int, int>, 2> mn = {make_pair(a[0], 0), make_pair(a[1], 1)};
    for (int i = 2; i < n; ++i) {
        mn[i % 2] = min(mn[i % 2], make_pair(a[i], i));
    }
    if (mn[0] <= mn[1]) {
        cout << "Joe\n";
    } else {
        cout << "Mike\n";
    }
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