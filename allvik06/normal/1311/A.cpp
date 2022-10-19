#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }
        if (a > b) {
            if (a % 2 == b % 2) {
                cout << 1;
            }
            else {
                cout << 2;
            }
        }
        else {
            if (a % 2 == b % 2) {
                cout << 2;
            }
            else {
                cout << 1;
            }
        }
        cout << "\n";
    }
    return 0;
}