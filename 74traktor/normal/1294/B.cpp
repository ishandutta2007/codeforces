#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, y;
    cin >> t;
    while (t--) {
        cin >> n;
        vector < pair < int, int > > a;
        for (int i = 1; i <= n; ++i) {
            cin >> x >> y;
            a.push_back({x, y});
        }
        sort(a.begin(), a.end());
        string ans = "";
        x = 0, y = 0;
        int oks = 0;
        for (auto key : a) {
            while (x < key.first) ans += "R", x++;
            while (y < key.second) ans += "U", y++;
            if (x != key.first || y != key.second) oks = 1;
        }
        if (oks) cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            cout << ans << '\n';
        }
    }
    return 0;
}