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
        int n, k;
        cin >> n >> k;
        if ((n - 2 * k) % 2 == 0 && n >= 2 * k) {
            cout << "YES" << '\n';
            for (int i = 1; i < k; ++i) cout << 2 << " ";
            cout << n - 2 * (k - 1) << '\n';
            continue;
        }
        if ((n - k) % 2 == 0 && n >= k) {
            cout << "YES" << '\n';
            for (int i = 1; i < k; ++i) cout << 1 << " ";
            cout << n - k + 1 << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
    return 0;
}