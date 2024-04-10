#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s)
        cnt[c - 'a']++;
    for (int i = 0; i < 26; i++)
        if (cnt[i] == 2)
            cout << char('a' + i);
    for (int i = 0; i < 26; i++)
        if (cnt[i] == 1)
            cout << char('a' + i);
    for (int i = 0; i < 26; i++)
        if (cnt[i] == 2)
            cout << char('a' + i);
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