#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << fixed << setprecision(8) << 1 / tan(3.1415926535 / (n * 2)) << "\n";
    }
}