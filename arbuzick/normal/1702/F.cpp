#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), used(n);
    multiset<int> ms;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] /= 2;
        }
        ms.insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int _ = 0; _ < 32; ++_) {
        for (int i = 0; i < n; ++i) {
            if (!used[i] && b[i] > 0) {
                if (ms.find(b[i]) != ms.end()) {
                    used[i] = 1;
                    ms.erase(ms.find(b[i]));
                } else {
                    b[i] /= 2;
                }
            }
        }
    }
    if (ms.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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