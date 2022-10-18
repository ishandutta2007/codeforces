#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, e;
    cin >> n >> d >> e;
    int ans = n;
    for (int i = 0; i <= 100000000; ++i) {
        if (n - 5 * i * e < 0) break;
        ans = min(ans, (n - 5 * i * e) % d);
    }
    cout << ans << '\n';
    return 0;
}