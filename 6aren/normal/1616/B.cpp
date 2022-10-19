#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.size() == 1 || s[0] == s[1]) {
            cout << s[0] << s[0] << '\n';
            continue;
        }
        string res;
        res += s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] <= s[i - 1]) res += s[i];
            else break;
        }
        cout << res;
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }
    return 0;
}