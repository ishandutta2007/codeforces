#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            root = (i + 1) % n;
            break;
        }
    }
    if (root == -1) {
        cout << "NO\n";
        return;
    }
    vector<bool> to_root(n, true);
    for (int i = root + 1; i < n; ++i) {
        if (s[i] == '0') {
            to_root[(i + 1) % n] = false;
        }
    }
    for (int i = 0; i + 1 < root; ++i) {
        if (s[i] == '0') {
            to_root[i + 1] = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i != root && to_root[i]) {
            cnt++;
        }
    }
    if (cnt % 2 != s[root] - '0') {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (i == root) {
            continue;
        }
        if (to_root[i]) {
            cout << i + 1 << ' ' << root + 1 << '\n';
        } else {
            cout << (n + i - 1) % n + 1 << ' ' << i + 1 << '\n';
        }
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