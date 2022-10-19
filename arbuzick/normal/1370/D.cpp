#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k2;
    cin >> n >> k2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 1e9;
    int l = 0, r = 1e9;
    while (l < r - 1) {
        int m = (l + r) / 2;
        int k = 0;
        int pr = -2;
        for (int i = 0; i < n - (k2 % 2 + 1) % 2; ++i)
            if (a[i] <= m && pr != i - 1) {
                k++;
                pr = i;
            }
        if (k >= (k2 - 1) / 2 + 1)
            r = m;
        else
            l = m;
    }
    ans = min(ans, r);
    l = 0;
    r = 1e9;
    while (l < r - 1) {
        int m = (l + r) / 2;
        int k = 0;
        int pr = -2;
        for (int i = 1; i < n - k2 % 2; ++i)
            if (a[i] <= m && pr != i - 1) {
                k++;
                pr = i;
            }
        if (k >= k2 / 2)
            r = m;
        else
            l = m;
    }
    ans = min(ans, r);
    cout << ans;
    return 0;
}