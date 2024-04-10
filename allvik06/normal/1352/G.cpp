#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9 + 10;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 3) {
            cout << -1 << "\n";
            continue;
        }
        if (n == 4) {
            cout << "3 1 4 2\n";
            continue;
        }
        if (n == 5) {
            cout << "1 4 2 5 3\n";
            continue;
        }
        vector <int> a(n);
        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; ++i) {
                a[i] = 2 * i + 1;
            }
            a[n / 2] = a[n / 2 - 1] - 3;
            a[n / 2 + 1] = a[n / 2] + 4;
            a[n / 2 + 2] = a[n / 2 + 1] - 2;
            if (n > 6) {
                a[n / 2 + 3] = a[n / 2 + 2] - 4;
            }
            for (int i = n / 2 + 4; i < n; ++i) {
                a[i] = a[i - 1] - 2;
            }
        }
        else {
            for (int i = 0; i <= n / 2; ++i) {
                a[i] = 2 * i + 1;
            }
            a[n / 2 + 1] = a[n / 2] - 3;
            a[n / 2 + 2] = a[n / 2 + 1] + 2;
            a[n / 2 + 3] = a[n / 2 + 2] - 4;
            for (int i = n / 2 + 4; i < n; ++i) {
                a[i] = a[i - 1] - 2;
            }
        }
        for (int i : a) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}