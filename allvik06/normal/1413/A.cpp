#include <bits/stdc++.h>

using namespace std;
#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n / 2; ++i) {
            cout << -a[n - i - 1] << " ";
        }
        for (int i = n / 2; i < n; ++i) {
            cout << a[n - i - 1] << " ";
        }
        cout << "\n";
    }
}