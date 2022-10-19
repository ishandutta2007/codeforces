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
        int kol = (n + 3) / 4;
        for (int i = 0; i < n - kol; ++i) cout << 9;
        for (int i = 0; i < kol; ++i) cout << 8;
        cout << "\n";
    }
}