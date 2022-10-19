#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int f0 = -1, l0 = -1;
        bool one = false;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '1') one = true;
            else {
                if (f0 == -1) f0 = i;
                l0 = i;
            }
        }
        if (f0 == -1) cout << "0\n";
        else if (!one) {
            cout << "1\n";
        } else {
            one = false;
            for (int i = f0; i <= l0; ++i) {
                if (s[i] == '1') one = true;
            }
            if (one) cout << "2\n";
            else cout << "1\n";
        }
    }
}