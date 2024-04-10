#include <bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i % 2 == 1) {
                if (j % 2 == 1) cout << "W";
                else cout << "B";
            }
            else {
                if (j % 2 == 0) cout << "W";
                else cout << "B";
            }
        }
        cout << '\n';
    }
    return 0;
}