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
        int n, s;
        cin >> n >> s;
        int kol_less = (n - 1) / 2;
        cout << s / (n - kol_less) << "\n";
    }
}