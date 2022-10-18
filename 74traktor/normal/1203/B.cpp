#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, x, s;
    cin >> q;
    bool f;
    for (int i = 1; i <= q; ++i) {
        cin >> n;
        vector < int > a;
        for (int j = 1; j <= 4 * n; ++j) {
            cin >> x;
            a.push_back(x);
        }
        f = true;
        sort(a.begin(), a.end());
        for (int j = 0; j < 2 * n; j += 2) {
            if (a[j] != a[j + 1] || a[4 * n - j - 1] != a[4 * n - j - 2]) f = false;
            if (j == 0) {
                s = a[j] * a[4 * n - 1];
            }
            if (s != a[j] * a[4 * n - j - 1] || s != a[j + 1] * a[4 * n - j - 2]) f = false;
        }
        if (f) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}