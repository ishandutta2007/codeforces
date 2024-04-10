#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd1(int a, int b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

signed  main() {
    int t;
    cin >> t;
    while (t--) {
        int m, d, w;
        cin >> m >> d >> w;
        int k = min(m, d);
        int kk = gcd1(w, d - 1);
        int dv = w / kk;
        int cntSmall = dv - k % dv;
        int cntBig = k % dv;
        int smallSize = k / dv;
        int bigSize = smallSize + 1;
        int ans = cntSmall * (smallSize * (smallSize - 1) / 2) + cntBig * (bigSize * (bigSize - 1) / 2);
        cout << ans << endl;
    }
}