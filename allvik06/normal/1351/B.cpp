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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c && a == b + d) {
            cout << "YES\n";
        }
        else if (a == d && a == b + c) {
            cout << "YES\n";
        }
        else if (b == c && b == a + d) {
            cout << "YES\n";
        }
        else if (b == d && b == a + c) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}