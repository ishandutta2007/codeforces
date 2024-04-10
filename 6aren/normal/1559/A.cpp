#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        for (int i = 1; i < n; i++) {
            int u;
            cin >> u;
            x &= u;
        }
        cout << x << '\n';
    }

    return 0;
}