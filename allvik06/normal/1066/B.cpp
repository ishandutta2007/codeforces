#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, r;
    cin >> n >> r;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> now(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (now[i] == 1) {
            continue;
        }
        int no = -1;
        for (int j = 0; j < n; ++j) {
            if (a[j] == 0) {
                continue;
            }
            if (j - r + 1 <= i && j + r - 1 >= i) {
                no = j;
            }
        }
        if (no == -1) {
            cout << -1;
            return 0;
        }
        ++ans;
        for (int j = 0; j < n; ++j) {
            if (no + r - 1 >= j && no - r + 1 <= j) {
                now[j] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}