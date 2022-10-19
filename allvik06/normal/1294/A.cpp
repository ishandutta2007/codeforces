#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t, n;
    cin >> t;
    ++t;
    while (--t) {
        vector <int> a(3);
        cin >> a[0] >> a[1] >> a[2] >> n;
        sort(a.begin(), a.end());
        n -= a[2] - a[0];
        n -= a[2] - a[1];
        if (n >= 0 && n % 3 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO \n";
        }
    }
    return 0;
}