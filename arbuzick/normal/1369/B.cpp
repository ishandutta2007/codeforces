#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0')
                ans += '0';
            else
                break;
        }
        string ans2 = "";
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1')
                ans2 += '1';
            else {
                if (i > ans.size())
                    ans += '0';
                break;
            }
        }
        cout << ans << ans2 << "\n";
    }
    return 0;
}