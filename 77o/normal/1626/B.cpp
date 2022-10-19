#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = n - 2; i >= 0; i--)
        if (s[i] - '0' + s[i + 1] - '0' >= 10) {
            for (int j = 0; j < i; j++)
                cout << s[j];
            cout << 1;
            cout << (s[i] - '0' + s[i + 1] - '0') % 10;
            for (int j = i + 2; j < n; j++)
                cout << s[j];
            cout << '\n';
            return;
        }
    cout << (s[0] - '0' + s[1] - '0');
    for (int i = 2; i < n; i++)
        cout << s[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}