#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << 2 << '\n';
        set < int > Q;
        for (int i = 1; i <= n; i++) Q.insert(i);
        while ((int)Q.size()) {
            int p = (*Q.begin());
            while (p <= n) {
                cout << p << " ";
                Q.erase(p);
                p *= 2;
            }
        }
        cout << '\n';
    }
    return 0;
}