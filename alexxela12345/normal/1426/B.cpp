#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool bb = false;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (b == c) {
                bb = true;
        }
        }
        if (bb && m % 2 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

    }
}