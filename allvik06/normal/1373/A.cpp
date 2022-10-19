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
        int a, b, c;
        cin >> a >> b >> c;
        if (a < c) {
            cout << 1 << " ";
        }
        else {
            cout << -1 << " ";
        }
        if (c < b * a) {
            cout << b << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}