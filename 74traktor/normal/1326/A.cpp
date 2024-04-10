#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) cout << -1 << '\n';
        else {
            string ans = "";
            for (int i = 1; i < n; ++i) ans += "2";
            ans += "3";
            if ((2 * n + 1) % 3 == 0) ans[n - 2] = '4';
            cout << ans << '\n';
        }
    }
    return 0;
}