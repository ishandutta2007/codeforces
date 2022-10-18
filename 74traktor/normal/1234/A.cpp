#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, x, sum;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        sum = 0;
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            sum += x;
        }
        cout << (sum + n - 1) / n << '\n';
    }
    return 0;
}