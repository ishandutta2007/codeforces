#include <bits/stdc++.h>

using namespace std;
#define int long long


signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 4 != 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int now = 0;
        for (int i = 1; i <= n / 2; ++i) {
            now += i * 2;
            cout << i * 2 << " ";
        }
        for (int i = 1; i < n / 2; ++i) {
            now -= i * 2 - 1;
            cout << i * 2 - 1 << " ";
        }
        cout << now << "\n";
    }
}