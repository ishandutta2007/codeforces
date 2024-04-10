#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b, n;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> a >> b >> n;
        if (n % 3 == 0) cout << a << '\n';
        else if (n % 3 == 1) cout << b << '\n';
        else cout << (a^b) << '\n';
    }
    return 0;
}