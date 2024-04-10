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
        int a, b;
        cin >> a >> b;
        if (a % b == 0) {
            cout << 0 << "\n";
        }
        else {
            cout << (a - a % b + b) - a << "\n";
        }
    }
    return 0;
}