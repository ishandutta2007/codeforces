#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << x << "\n";
            continue;
        }
        if (x < y) {
            cout << y - ((y - x) % x) / 2 << "\n";
        } else {
            cout << x + y << "\n";
        }
    }
}

/*

 */