#include<bits/stdc++.h>

using namespace std;

int a[55], used[55];

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
        int ans = 0, cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] % 2 == 0) cnt0++;
            else cnt1++;
        }
        if (cnt0 % 2 == 0 && cnt1 % 2 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (abs(a[i] - a[j]) == 1) {
                    ans = 1;
                }
            }
        }
        if (ans) {
            if (cnt0 % 2 == 1 && cnt1 % 2 == 1) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}