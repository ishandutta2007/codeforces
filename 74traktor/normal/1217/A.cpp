#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b, c;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> a >> b >> c;
        int d = c + a - b;
        if (d <= 0) cout << 0 << '\n';
        else cout << min((d - 1) / 2 + 1, c + 1) << '\n';
    }
    return 0;
}