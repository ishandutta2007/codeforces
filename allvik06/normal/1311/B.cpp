#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <int> a(n), now(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            int tmp;
            cin >> tmp;
            now[tmp - 1] = 1;
        }

        bool flag = false;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[i]) {
                    for (int k = i; k < j; ++k) {
                        if (now[k] == 0) {
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}