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
        int ans = 0, now = 0, cha = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '+') ++now;
            else --now;
            if (now >= 0) continue;
            if (abs(now) <= cha) continue;
            ans += i + 1;
            ++cha;
        }
        cout << ans + s.size() << "\n";
    }
}