#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int j = 0; j < n; ++j) {
            cin >> b[j];
        }
        int now1 = 0, nowm1 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                ++now1;
            }
            else if (a[i] == -1) {
                ++nowm1;
            }
        }
        bool flag = true;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == 1) {
                --now1;
            }
            if (a[i] == -1) {
                --nowm1;
            }
            if (a[i] == b[i]) {
                continue;
            }
            else if (a[i] < b[i]) {
                if (now1 == 0) {
                    flag = false;
                    break;
                }
            }
            else {
                if (nowm1 == 0) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}