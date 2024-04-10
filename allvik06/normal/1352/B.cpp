#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 0 && 2 * k <= n) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; ++i) {
                cout << 2 << " ";
                n -= 2;
            }
            cout << n << "\n";
        }
        else if ((n - k) % 2 == 0 && n >= k) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; ++i) {
                cout << 1 << " ";
                --n;
            }
            cout << n << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}