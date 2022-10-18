#include<bits/stdc++.h>

using namespace std;

string a[25], b[25];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, x;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> x;
        cout << a[(x - 1) % n + 1];
        cout << b[(x - 1) % m + 1] << '\n';
    }
    return 0;
}