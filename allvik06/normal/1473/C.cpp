#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < 2 * k - n - 1; ++i) cout << i + 1 << " ";
        for (int i = 0; i <= n - k; ++i) cout << k - i << " ";
        cout << "\n";
    }
}