#include <bits/stdc++.h>

using namespace std;

int a[2005];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = n + 1;
    for (int l = 1; l <= n; ++l) {
        set < int > used;
        for (int j = 1; j < l; ++j) used.insert(a[j]);
        for (int r = n; r >= l - 1; --r) {
            if ((int)used.size() == n - r + l - 1) ans = min(ans, r - l + 1);
            used.insert(a[r]);
        }
    }
    cout << ans << '\n';
    return 0;
}