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
    int t, n, m, r, c;
    cin >> t;
    while (t--) {
        cin >> n >> m >> r >> c;
        cout << max({r + c - 2, n - r + c - 1, m - c + r - 1, n - r + m - c}) << '\n';
    }
    return 0;
}