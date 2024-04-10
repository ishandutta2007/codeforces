#include <bits/stdc++.h>

using namespace std;
#define int long long

inline bool check(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (!check(sum)) {
            cout << n << "\n";
            for (int i = 1; i <= n; ++i) cout << i << " ";
            cout << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (!check(sum - a[i])) {
                cout << n - 1 << "\n";
                for (int j = 0; j < n; ++j) {
                    if (j != i) cout << j + 1 << " ";
                }
                cout << "\n";
                break;
            }
        }
    }
}