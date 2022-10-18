#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, A = 0, B = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        A = max(A, x);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        B = max(B, x);
    }
    cout << A << " " << B << '\n';
    return 0;
}