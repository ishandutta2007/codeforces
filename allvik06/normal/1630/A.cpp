#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <map>

using namespace std;


signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k == 0) {
            for (int i = 0; i < n; ++i) {
                int p = n - i - 1;
                if (p > i) cout << i << " " << p << "\n";
            }
        } else if (k == n - 1) {
            if (n <= 4) {
                cout << "-1\n";
                continue;
            }
            cout << n - 1 << " " << n - 2 << "\n" << 1 << " " << ((n - 1) >> 1) << "\n" << 0 << " " << n / 2 << "\n";
            for (int i = 0; i < n; ++i) {
                if (i == 0 || i == n - 1 || i == n - 2 || i == 1 || i == ((n - 1) >> 1)) continue;
                int p = n - 1 - i;
                if (p > i) cout << i << " " << p << "\n";
            }
        } else {
            cout << n - 1 << " " << k << "\n" << "0 " << n - 1 - k << "\n";
            for (int i = 0; i < n; ++i) {
                if (i == 0 || i == n - 1 || i == k || i == n - 1 - k) continue;
                int p = n - 1 - i;
                if (p > i) cout << i << " " << p << "\n";
            }
        }
    }
}

/*

 */