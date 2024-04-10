#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int s = 0, x;
        for (int i = 1; i <= 4; i++) {
            cin >> x;
            s += x;
        }
        if (s == 0) cout << 0 << '\n';
        else if (s == 4) cout << 2 << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}