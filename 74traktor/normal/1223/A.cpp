#include <bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> n;
        if (n == 2) {
            cout << 2 << '\n';
        }
        else if (n == 3) {
            cout << 1 << '\n';
        }
        else {
            if ((n - 1) % 2 == 1) {
                cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
    }
    return 0;
}