#include <bits/stdc++.h>

using namespace std;
#define int long long


signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        string ss;
        cin >> ss;
        int minn = ss.size();
        int n = ss.size();
        for (char f = '0'; f <= '9'; ++f) {
            for (char s = '0'; s <= '9'; ++s) {
                bool now = true;
                int cur = 0;
                for (int i = 0; i < n; ++i) {
                    if (now && ss[i] == f) {
                        ++cur;
                        now = false;
                    }
                    else if (!now && ss[i] == s) {
                        ++cur;
                        now = true;
                    }
                }
                if (f != s) cur = cur - cur % 2;
                minn = min(minn, n - cur);
            }
        }
        cout << minn << "\n";
    }
}