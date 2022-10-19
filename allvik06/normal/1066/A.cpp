#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; ++z) {
        int ll, w, l, r;
        cin >> ll >> w >> l >> r;
        int kol = ll / w;
        int kol1 = (l - 1) / w;
        int kol2 = r / w;
        cout << kol - (kol2 - kol1) << "\n";
    }
    return 0;
}