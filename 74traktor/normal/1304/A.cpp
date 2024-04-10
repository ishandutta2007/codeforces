#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, x, y, a, b;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> x >> y >> a >>b;
        if ((y - x) % (a + b) == 0) cout << (y - x) / (a + b) << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}