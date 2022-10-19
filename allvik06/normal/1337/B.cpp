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
        int x, n, m;
        cin >> x >> n >> m;
        while (x > 0) {
            if (n > 0 && x / 2 + 10 < x) {
                x = x / 2 + 10;
                --n;
            } else if (m == 0) break;
            else {
                --m;
                x -= 10;
            }
        }
        if (x <= 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}