#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        set < int > used;
        for (int i = 1; i <= 2 * n; ++i) {
            cin >> x;
            if (used.find(x) != used.end()) {
                cout << x << " ";
            }
            used.insert(x);
        }
        cout << '\n';
    }
    return 0;
}