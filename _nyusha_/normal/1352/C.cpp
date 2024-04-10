#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int cnt = (k - 1) / (n - 1);
        cout << cnt * n + (k - cnt * (n - 1)) << '\n';
    }
    return 0;
}