#include<bits/stdc++.h>

using namespace std;

int inf = 1e9 + 7;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, l, r;
    cin >> t;
    while (t--) {
        int n, min_r = inf, max_l = -inf;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> l >> r;
            min_r = min(min_r, r);
            max_l = max(max_l, l);
        }
        cout << max(max_l - min_r, 0) << '\n';
    }
    return 0;
}