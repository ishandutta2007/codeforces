#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k1 = 0, k2 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0')
                k1++;
            else
                k2++;
        }
        if (min(k1, k2) % 2 == 0)
            cout << "NET\n";
        else
            cout << "DA\n";
    }
    return 0;
}