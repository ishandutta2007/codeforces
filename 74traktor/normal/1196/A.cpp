#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[4];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        for (int j = 1; j <= 3; ++j) cin >> a[j];
        sort(a + 1, a + 4);
        int x1 = a[1], x2 = a[2], x3 = a[3];
        x3 -= (x2 - x1);
        x1 = x2;
        cout << x1 + x3 / 2 << '\n';
    }
    return 0;
}