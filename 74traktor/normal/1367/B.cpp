#include<bits/stdc++.h>

using namespace std;

int a[45];

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
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i - 1) % 2 == a[i] % 2) continue;
            if (i % 2 == 1) cnt0++;
            else cnt1++;
        }
        if (cnt0 != cnt1) cout << -1 << '\n';
        else {
            cout << cnt0 << '\n';
        }
    }
    return 0;
}