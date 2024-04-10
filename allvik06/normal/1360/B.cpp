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
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int minn = 100000;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                minn = min(minn, abs(a[i] - a[j]));
            }
        }
        cout << minn << "\n";
    }
}