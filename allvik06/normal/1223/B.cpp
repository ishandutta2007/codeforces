#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int q;
    cin >> q;
    for (int w= 0; w < q; ++w) {
        int ans = 0;
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {
                if (s[i] == t[j]) {
                    ans = 1;
                }
            }
        }
        if (ans == 1) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}