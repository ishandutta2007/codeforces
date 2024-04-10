#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                string s0 = s.substr(j, i - j + 1);
                int len = (int) t.size() - (i - j + 1);
                if (len < 0) continue;
                if (i - len < 0) continue;
                string s2 = s.substr(i - len, len);
                reverse(s2.begin(), s2.end());
                if (s0 + s2 == t) ok = true;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}