#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int s, ans = 0;
        cin >> s;
        while (s >= 10) {
            ans += s - s % 10;
            s = s / 10 + s % 10;
        }
        cout << ans + s << "\n";
    }
    return 0;
}