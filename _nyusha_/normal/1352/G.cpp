#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 3) {
            cout << -1 << '\n';
            continue;
        }
        if (n % 2 == 0) {
            for (int i = 1; i <= n / 2; ++i) {
                cout << 2 * i << " ";
            }
            cout << n - 3 << " ";
            cout << n - 1 << " ";
            for (int i = 1; i <= n / 2 - 2; ++i) cout << n - 2 * (i + 2) + 1 << " ";
        }
        else {
            for (int i = 1; i <= (n + 1) / 2; ++i) {
                cout << 2 * i - 1 << " ";
            }
            cout << n - 3 << " " << n - 1 << " ";
            for (int i = 1; i <= n / 2 - 2; ++i) cout << n - 2 * (i + 2) + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}