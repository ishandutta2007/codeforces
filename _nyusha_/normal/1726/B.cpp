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
        if (m < n) {
            cout << "No" << '\n';
            continue;
        }
        if (n % 2 == 1) {
            cout << "Yes" << '\n';
            for (int i = 1; i < n; i++) cout << 1 << " ";
            cout << m - (n - 1) << '\n';
        } else {
            if ((m - n + 2) % 2 == 1) {
                cout << "No" << '\n';
            } else {
                cout << "Yes" << '\n';
                for (int i = 1; i < n - 1; i++) cout << 1 << " ";
                cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << '\n';
            }
        }
    }
    return 0;
}