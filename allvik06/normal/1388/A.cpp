#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n >= 6 + 10 + 14 + 1) {
            int z = n - 6 - 10 - 14;
            if (z != 6 && z != 10 && z != 14) cout << "YES\n" << 6 << " " << 10 << " " << 14 << " " << z << "\n";
            else cout << "YES\n" << 6 << " " << 10 << " " << 15 << " " << z - 1 << "\n";
        }
        else cout << "NO\n";
    }
}