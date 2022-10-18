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
        int k = n / 2020;
        int sum = n % 2020;
        if (sum <= k)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}