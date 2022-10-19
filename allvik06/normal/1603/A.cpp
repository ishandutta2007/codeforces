#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool res = true;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            bool ok = false;
            if (res) {
                for (int j = i; j >= 1; --j) {
                    if (x % (j + 1) != 0) {
                        ok = true;
                        break;
                    }
                }
            }
            if (!ok) {
                res = false;
            }
        }
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*

 */