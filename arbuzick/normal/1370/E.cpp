#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            k1++;
        if (t[i] == '0')
            k2++;
    }
    if (k1 != k2) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    int f0 = 0, f1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (s[i] == '0') {
                if (f1) {
                    f1--;
                    f0++;
                }
                else {
                    ans++;
                    f0++;
                }
            }
            else {
                if (f0) {
                    f0--;
                    f1++;
                }
                else {
                    ans++;
                    f1++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}