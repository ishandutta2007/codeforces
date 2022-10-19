#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (x == 1) {
            if (n == 1) {
                cout << 1 << endl;
            } else {
                cout << n - 1 << endl;
            }
            continue;
        }
        // 2 -> x - 1
        n += (x - 1 - 2);
        cout << n / x + 1 << endl;
    }
}