#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int kol0 = 0, kol1 = 0;
    for (int i : a) {
        if (i == 0) ++kol0;
        else ++kol1;
    }
    while (q--) {
        int c, i;
        cin >> c >> i;
        if (c == 1) {
            if (a[i - 1] == 1) {
                a[i - 1] = 0;
                --kol1;
                ++kol0;
            } else {
                a[i - 1] = 1;
                --kol0;
                ++kol1;
            }
        } else {
            if (kol1 >= i) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}