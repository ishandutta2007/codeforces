#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <char> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        vector <char> ans = s;
        int k = 1;
        for (int i = 1; i <= n; ++i) {
            vector <char> now(n);
            int sk = n - i + 1;
            if (sk == 1) {
                int fl = 0;
            }
            for (int j = 0; j < n - sk; ++j) {
                    if (sk % 2 == 0) {
                        now[j + n - i + 1] = s[j];
                    } else {
                        now[i - j - 1 + (n - i)] = s[j];
                    }
            }
            for (int j = 0; j < sk; ++j) {
                now[j] = s[j + i - 1];
            }
            int mi = 0;
            for (int j = 0; j < n; ++j) {
                if (now[j] < ans[j]) {
                    mi = 1;
                    break;
                }
                if (now[j] > ans[j]) {
                    mi = -1;
                    break;
                }
            }
            if (mi == 1) {
                ans = now;
                k = i;
            }
            if (mi == 0 && i < k) {
                ans = now;
                k = i;
            }
        }
        for (char i : ans) {
            cout << i;
        }
        cout << "\n" << k << "\n";
    }
}