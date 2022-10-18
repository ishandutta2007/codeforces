#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        int t = a % b;
        a = b, b = t;
    }
    return a + b;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, sx, ex, sy, ey;
    cin >> n >> m >> q;
    int t = gcd(n, m);
    int x1 = n / t, x2 = m / t;
    for (int i = 1; i <= q; ++i) {
        cin >> sx >> ex >> sy >> ey;
        if (sx == 1) ex = (ex - 1) / x1;
        else ex = (ex - 1) / x2;
        if (sy == 1) ey = (ey - 1) / x1;
        else ey = (ey - 1) / x2;
        if (ex == ey) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}