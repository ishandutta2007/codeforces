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
        int n, k, ans;
        cin >> n >> k;
        if (k == 1) {
            for (int i = 0;  i < n - 2; ++i) {
                cout << "a";
            }
            cout << "bb\n";
            continue;
        }
        ans = n;
        int ans2 = n;
        for (int i = 0; i < n - 2; ++i) {
            if ((n - i - 1) * (n - i - 2) / 2 < k) {
                ans = i;
                k -= (n - i - 1) * (n - i - 2) / 2;
                break;
            }
        }
        for (int i = ans + 1; i < n; ++i) {
            if ((n - i) == k) {
                ans2 = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == ans) {
                cout << "b";
            }
            else if (i == ans2) {
                cout << "b";
            }
            else {
                cout << "a";
            }
        }
        cout << "\n";
    }
    return 0;
}