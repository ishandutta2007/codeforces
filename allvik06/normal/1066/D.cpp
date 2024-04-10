#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = -1, r = n;
    while (r - l > 1) {
        bool flag = false;
        int mm = (l + r) / 2;
        int nowk = k, ans = 1;
        for (int i = mm; i < n; ++i) {
            if (k < a[i]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            l = mm;
            continue;
        }
        for (int i = mm; i < n; ++i) {
            if (a[i] <= nowk) {
                nowk -= a[i];
            }
            else {
                ++ans;
                nowk = k - a[i];
            }
        }
        if (ans <= m) {
            r = mm;
        }
        else {
            l = mm;
        }
    }
    cout << n - r;
    return 0;
}