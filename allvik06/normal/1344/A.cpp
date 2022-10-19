#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <int> ans(n);
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            ++ans[(i + a[i] % n + n) % n];
            if (ans[(i + a[i] % n + n) % n] > 1) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}