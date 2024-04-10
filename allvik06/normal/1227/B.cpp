#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0 ; i < n; ++i) {
            cin >> a[i];
        }
        vector <int> ans(n);
        vector <int> used(n + 1);
        ans[0] = a[0];
        used[a[0]] = 1;
        int flag = 0, now = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i - 1]) {
                ans[i] = a[i];
                used[a[i]] = 1;
            }
            else {
                for (int j = now; j < a[i]; ++j) {
                    if (!used[j]) {
                        ans[i] = j;
                        used[j] = 1;
                        break;
                    }
                }
                if (ans[i] == 0) {
                    cout << -1 << "\n";
                    flag = 1;
                    break;
                }
                now = ans[i] + 1;
            }
        }
        if (flag) {
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] < 1 || ans[i] > n) {
                cout << -1 << "\n";
                flag = 1;
                break;
            }
        }
        if (!flag) {
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
}