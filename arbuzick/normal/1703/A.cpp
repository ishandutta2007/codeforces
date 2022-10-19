#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    for (auto &ch : s) {
        ch = ch | ('a' ^ 'A');
    }
    if (s == "yes") {
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