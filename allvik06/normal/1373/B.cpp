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
        string s;
        cin >> s;
        int one = 0, two = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') ++one;
            else ++two;
        }
        if (min(one, two) % 2 == 1) cout << "DA\n";
        else cout << "NET\n";
    }
}