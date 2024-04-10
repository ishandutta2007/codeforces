#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, h, m;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> h >> m;
        if (h == 0 && m == 0) cout << 0 << '\n';
        else cout << 24 * 60 - h * 60 - m << '\n';
    }
    return 0;
}