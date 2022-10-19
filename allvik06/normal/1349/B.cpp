#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        bool f = false;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == k) f = true;
        }
        if (!f) {
            cout << "no\n";
            continue;
        }
        vector <int> b(n + 1);
        for (int i = 0; i < n; ++i) {
            if (a[i] >= k) b[i + 1] = b[i] + 1;
            else b[i + 1] = b[i] - 1;
        }
        int minn = 0;
        f = false;
        for (int i = 2; i <= n; ++i) {
            if (b[i] - minn > 0) {
                f = true;
                break;
            }
            minn = min(minn, b[i - 1]);
        }
        if (f || n == 1) {
            cout << "yes\n";
        }
        else cout << "no\n";
    }
}