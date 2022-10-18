#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        int lef = c - r, righ = c + r;
        int good = min(righ, max(a, b)) - max(lef, min(a, b));
        good = max(good, 0);
        cout << max(a, b) - min(a, b) - good<< '\n';
    }
    return 0;
}