#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        bool f = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] >= a[i - 1]) f = false;
        }
        if (f) cout << "NO\n";
        else cout << "YES\n";
    }
}