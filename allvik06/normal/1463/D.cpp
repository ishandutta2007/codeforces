#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e10;

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
        vector <bool> flex(2 * n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            flex[a[i]] = true;
        }
        int kol = 0, minnx = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (flex[i]) {
                if (kol > 0) {
                    --kol;
                } else {
                    ++minnx;
                }
            } else {
                ++kol;
            }
        }
        kol = 0;
        int maxxx = 0;
        for (int i = 2 * n - 1; i >= 0; --i) {
            if (flex[i]) {
                if (kol > 0) {
                    --kol;
                } else {
                    ++maxxx;
                }
            } else {
                ++kol;
            }
        }
        cout << (n - maxxx) - minnx + 1 << "\n";
    }
}