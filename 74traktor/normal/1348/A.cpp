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
        int n, ans = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            if (i < n / 2 - 1) ans += (1 << i);
            else if (i < n - 1) ans -= (1 << i);
            else ans += (1 << i);
        }
        cout << abs(ans) * 2 << '\n';
    }
    return 0;
}