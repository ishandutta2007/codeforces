#include<bits/stdc++.h>

using namespace std;

int a[100005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ok = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == x) ok = 1;
        }
        if (ok) {
            cout << 1 << '\n';
            continue;
        }
        sort(a + 1, a + n + 1);
        cout << max((x + a[n] - 1) / a[n], 2) << '\n';
    }
    return 0;
}