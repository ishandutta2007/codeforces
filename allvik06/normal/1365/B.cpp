#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        bool nul = false, one = false;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0) nul = true;
            else one = true;
        }
        bool sor = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) sor = false;
        }
        if ((nul && one) || sor) cout << "Yes\n";
        else cout << "No\n";
    }
}