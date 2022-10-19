#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    for (int i = 0; i < (n + 1) / 2; ++i) {
        ans.push_back(a[i]);
        ans.push_back(-1);
    }
    int pos = 1;
    for (int i = (n + 1) / 2; i < n; ++i) {
        ans[pos] = a[i];
        pos += 2;
    }
    a = ans;
    for (int i = 0; i < n; ++i) {
        if (!(a[i] > a[(i + 1) % n] && a[i] > a[(i - 1 + n) % n]) && !(a[i] < a[(i + 1) % n] && a[i] < a[(i - 1 + n) % n])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (auto v : a) {
        cout << v << ' ';
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