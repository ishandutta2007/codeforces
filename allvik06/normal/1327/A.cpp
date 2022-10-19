#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k * k > n) {
            cout << "NO\n";
            continue;
        }
        if (n % 2 == k % 2) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}