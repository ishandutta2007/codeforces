#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> k;
        int cnt = (n / k) * k, c = n % k;
        cout << cnt + min(c, k / 2) << '\n';
    }
    return 0;
}