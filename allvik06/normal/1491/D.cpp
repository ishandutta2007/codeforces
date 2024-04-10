#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int kol1u = 0, kol1v = 0;
        bool ok = true;
        for (int i = 0; i < 30; ++i) {
            if ((u >> i) & 1) ++kol1u;
            if ((v >> i) & 1) ++kol1v;
            if (kol1v > kol1u) ok = false;
        }
        if (kol1v > kol1u || !ok || u > v) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}