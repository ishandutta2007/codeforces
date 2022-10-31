#include<bits/stdc++.h>

using namespace std;

#define int long long

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
        int x0, n;
        cin >> x0 >> n;
        for (int i = 1; i <= n % 4; ++i) {
            int d = n - (n % 4 - i);
            if (x0 % 2 == 0) x0 -= d;
            else x0 += d;
        }
        cout << x0 << '\n';
    }
    return 0;
}