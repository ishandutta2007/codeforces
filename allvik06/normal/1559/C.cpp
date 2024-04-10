#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = false;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == 0 && a[i + 1] == 1) {
                for (int j = 0; j <= i; ++j) cout << j + 1 << " ";
                cout << n + 1 << " ";
                for (int j = i + 1; j < n; ++j) cout << j + 1 << " ";
                cout << "\n";
                ok = true;
                break;
            }
        }
        if (a[0] == 1 && !ok) {
            cout << n + 1 << " ";
            for (int i = 0; i < n; ++i) cout << i + 1 << " ";
            cout << "\n";
            ok = true;
        }
        if (a.back() == 0 && !ok) {
            for (int i = 0; i <= n; ++i) cout << i + 1 << " ";
            cout << "\n";
            ok = true;
        }
        assert(ok);
    }
}