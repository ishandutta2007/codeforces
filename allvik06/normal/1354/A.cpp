#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b >= a) {
            cout << b << "\n";
        }
        else {
            a -= b;
            int del = c - d;
            if (del <= 0) {
                cout << -1 << "\n";
            }
            else {
                cout << b + (int)ceil((double)a / (double)del) * c << "\n";
            }
        }
    }
}