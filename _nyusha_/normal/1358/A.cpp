#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n % 2 == 0) cout << n / 2 * m << '\n';
        else if (m % 2 == 0) cout << m / 2 * n << '\n';
        else {
            cout << min(m / 2 * n + n / 2 + 1, n / 2 * m + m / 2 + 1) << '\n';
        }
    }
    return 0;
}