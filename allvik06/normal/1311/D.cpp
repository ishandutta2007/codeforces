#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 100000000;
        int ansa = 0, ansb = 0, ansc = 0;
        for (int i = 1; i <= 10000; ++i) {
            for (int j = 1; i * j <= 20000; ++j) {
                int bb = i * j;
                int cc = (c / bb) * bb;
                if (ans > abs(a - i) + abs(b - bb) + abs(c - cc) && i <= bb && bb <= cc) {
                    ans = abs(a - i) + abs(b - bb) + abs(c - cc);
                    ansa = i;
                    ansb = bb;
                    ansc = cc;
                }
                cc = (c / bb) * bb + bb;
                if (ans > abs(a - i) + abs(b - bb) + abs(c - cc) && i <= bb && bb <= cc) {
                    ans = abs(a - i) + abs(b - bb) + abs(c - cc);
                    ansa = i;
                    ansb = bb;
                    ansc = cc;
                }
            }
        }
        cout << ans << "\n" << ansa << " " << ansb << " " << ansc << "\n";
    }
    return 0;
}