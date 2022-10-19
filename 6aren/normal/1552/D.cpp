#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n; 
        vector<int> a(n);
        for (int &e : a) {
            cin >> e;
            if (e < 0) e = -e;
        }
        if (n == 1) {
            if (a[0] == 0) cout << "YES\n"; 
            else cout << "NO\n";
            continue;
        } 
        bool ok = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int sum1 = 0;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) sum1 += a[i];
            }
            for (int mask2 = 1; mask2 < (1 << n); mask2++) {
                if (mask == mask2) continue;
                int sum2 = 0;
                for (int i = 0; i < n; i++) {
                    if ((mask2 >> i) & 1) sum2 += a[i];
                }
                if (sum1 == sum2) ok = true;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}