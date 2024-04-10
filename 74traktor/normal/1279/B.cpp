#include<bits/stdc++.h>

using namespace std;

#define int long long
int a[100005];
int pref[100005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, s;
    cin >> t;
    for (int j = 1; j <= t; ++j) {
        cin >> n >> s;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
        if (pref[n] <= s) {
            cout << 0 << '\n';
        }
        else {
            int ans = -1, pos = 0;
            for (int i = 1; i <= n; ++i) {
                int lef = i, righ = n + 1;
                while (righ - lef > 1) {
                    int mid = (righ + lef) / 2;
                    if (pref[mid] - a[i] <= s) lef = mid;
                    else righ = mid;
                }
                if (lef - 1 > ans && pref[lef] - a[i] <= s) {
                    ans = lef - 1, pos = i;
                }
            }
            cout << pos << '\n';
        }
    }
    return 0;
}