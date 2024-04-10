#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        string s;
        cin >> s;
        for (auto ch : s) {
            if (ch == 'U') {
                a[i]--;
            } else {
                a[i]++;
            }
        }
        a[i] = (a[i] % 10 + 10) % 10;
        cout << a[i] << ' ';
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