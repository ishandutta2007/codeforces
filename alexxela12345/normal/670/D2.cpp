#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int l = 0;
    int r = 2e9 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        __int128_t need = 0;
        for (int i = 0; i < n; i++) {
            __int128_t x = (__int128_t) a[i] * m;
            need += max((__int128_t) 0, x - b[i]);
        }
        if (need <= k) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
}