#include<bits/stdc++.h>

using namespace std;

char a[55][55];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cin >> a[i][j];
        }
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; ++i) {
            int ok = 1;
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] == '1') ok = 0;
            }
            cnt0 += ok;
        }
        for (int j = 1; j <= m; ++j) {
            int ok = 1;
            for (int i = 1; i <= n; ++i) {
                if (a[i][j] == '1') ok = 0;
            }
            cnt1 += ok;
        }
        int cnt = min(cnt0, cnt1);
        if (cnt % 2 == 1) cout << "Ashish" << '\n';
        else cout << "Vivek" << '\n';
    }
    return 0;
}