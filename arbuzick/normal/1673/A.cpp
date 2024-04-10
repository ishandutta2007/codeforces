#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    for (auto ch : s) {
        sum += (ch - 'a') + 1;
    }
    if (n % 2 == 0) {
        cout << "Alice " << sum << '\n';
    } else {
        if (s[0] < s[n - 1]) {
            swap(s[0], s[n - 1]);
        }
        if (sum - (s[n - 1] - 'a' + 1) < s[n - 1] - 'a' + 1) {
            cout << "Bob " << (s[n - 1] - 'a' + 1) * 2 - sum << '\n';
        } else {
            cout << "Alice " << sum - (s[n - 1] - 'a' + 1) * 2 << '\n';
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