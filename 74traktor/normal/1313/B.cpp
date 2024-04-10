#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int solve(int n, int x, int y, int ok) {
    if (x > y) swap(x, y);
    int lef = x, righ = n + 1;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        int b = mid - x;
        if (b >= y) ++b;
        if (x + 1 + b < x + y + ok) lef = mid;
        else righ = mid;
    }
    return lef;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, y, ball;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        cout << n - solve(n, n - x + 1, n - y + 1, 0) + 1 << " " << solve(n, x, y, 1) << '\n';
    }
    return 0;
}