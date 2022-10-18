#include<bits/stdc++.h>

using namespace std;

int p[105], c[105];

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
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> p[i] >> c[i];
        int ok = 1;
        for (int i = 1; i <= n; ++i) {
            if (p[i] - p[i - 1] < c[i] - c[i - 1] || c[i] < c[i - 1]) ok = 0;
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}