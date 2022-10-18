#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, q;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    for (int cnt = 0; cnt <= 100; ++cnt) {
        if ((n - cnt * p) >= 0 && (n - cnt * p) % q == 0) {
            cout << cnt + (n - cnt * p) / q << '\n';
            for (int i = 0; i < n;) {
                if (cnt > 0) {
                    for (int j = 0; j < p; ++j) cout << s[i++];
                    cnt--;
                    cout << '\n';
                }
                else {
                    for (int j = 0; j < q; ++j) cout << s[i++];
                    cout << '\n';
                }
            }
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}