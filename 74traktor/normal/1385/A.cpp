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
        int x, y, z;
        cin >> x >> y >> z;
        if (min({x, y, z}) == max({x, y, z})) {
            cout << "YES" << '\n';
            cout << x << " " << x << " " << x << '\n';
            continue;
        }
        set < int > Q = {x, y, z};
        if ((int)Q.size() == 3) {
            cout << "NO" << '\n';
            continue;
        }
        int ok = 0;
        if (x == (*Q.rbegin())) ok++;
        if (y == (*Q.rbegin())) ok++;
        if (z == (*Q.rbegin())) ok++;
        if (ok <= 1) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        cout << (*Q.begin()) << " " << (*Q.begin()) << " " << (*Q.rbegin()) << '\n';
    }
    return 0;
}