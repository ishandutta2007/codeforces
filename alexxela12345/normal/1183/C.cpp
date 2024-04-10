#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int k, n, a, b;
        cin >> k >> n >> a >> b;
        int max_anss = (k - 1) / b;
        if (max_anss < n) {
            cout << -1 << endl;
            continue;
        }
        int l = 0;
        int r = k / a + 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (k - a * m <= 0) {
                r = m;
                continue;
            }
            if (m > n) {
                r = m;
                continue;
            }
            if (m + (k - a * m - 1) / b < n) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << l << endl;
    }
}