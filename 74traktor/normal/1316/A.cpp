#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, m;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            sum += x;
        }
        cout << min(m, sum) << '\n';
    }
    return 0;
}