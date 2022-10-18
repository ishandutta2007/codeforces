#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r",  stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, g, b;
        cin >> n >> g >> b;
        int good = (n + 1) / 2;
        int lef = n - 1, righ = (int)3e18;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            int cnt = (mid / (g + b)) * g + min(mid % (b + g), g);
            if (cnt >= good) righ = mid;
            else lef = mid;
        }
        cout << righ << '\n';
    }
    return 0;
}