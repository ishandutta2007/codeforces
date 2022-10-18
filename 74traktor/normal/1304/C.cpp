#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, T = 0, l, r, ok = 1, t, L, H;
        cin >> n >> m;
        l = m, r = m;
        for (int i = 1; i <= n; ++i) {
            cin >> t >> L >> H;
            r += (t - T);
            l -= (t - T);
            //cout << l << " " << r << " " << L << " " << H << '\n';
            l = max(l, L);
            r = min(r, H);
            if (l > r) ok = 0;
            T = t;
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}