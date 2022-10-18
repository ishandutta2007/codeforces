#include <bits/stdc++.h>

using namespace std;

int cnt1[26], cnt2[26];

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int j = 0; j < 26; ++j) cnt1[j] = 0, cnt2[j] = 0;
    for (auto c : s) cnt1[c - 'a']++;
    for (auto c : t) cnt2[c - 'a']++;
    for (int j = 0; j < 26; ++j) {
        if (cnt1[j] != cnt2[j]) {
            cout << "NO" << '\n';
            return;
        }
    }
    for (int j = 0; j < 26; ++j) {
        if (cnt1[j] > 1) {
            cout << "YES" << '\n';
            return;
        }
    }
    int ok1 = 0, ok2 = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (s[j] > s[i]) ok1++;
        }
    }
    for (int i = 0; i < (int)t.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (t[j] > t[i]) ok2++;
        }
    }
    if (ok1 % 2 == ok2 % 2) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}