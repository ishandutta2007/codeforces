#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> count(10);
    for (int i = 0; i < n; ++i) {
        count[a[i] % 10]++;
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = i; j < 10; ++j) {
            int k = (23 - i - j) % 10;
            count[i]--, count[j]--, count[k]--;
            if (count[i] >= 0 && count[j] >= 0 && count[k] >= 0) {
                cout << "YES\n";
                return;
            }
            count[i]++, count[j]++, count[k]++;
        }
    }
    cout << "NO\n";
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