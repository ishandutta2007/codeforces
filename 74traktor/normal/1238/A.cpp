#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
    cin >> x >> y;
    if (x != y + 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    }
    return 0;
}