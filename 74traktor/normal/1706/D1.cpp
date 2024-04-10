#include<bits/stdc++.h>

using namespace std;

int const maxn = 3005;
int a[maxn];
int cnt[maxn];
vector < int > open[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < maxn; i++) open[i] = {};
        for (int i = 1; i <= n; i++) {
            int j = 1;
            while (j <= k) {
                int x = a[i] / j;
                open[x].push_back(i);
                if (x == 0) break;
                j = (a[i] + x) / x;
            }
        }
        int sz = 0, r = 0, ans = maxn;
        for (int v = 0; v < maxn; v++) {
            while (r < maxn && sz < n) {
                for (auto key : open[r]) {
                    if (cnt[key] == 0) {
                        sz++;
                    }
                    cnt[key]++;
                }
                r++;
            }
            if (sz == n && r - v - 1 < ans) {
                ans = r - v - 1;
            }
            for (auto key : open[v]) {
                cnt[key]--;
                if (cnt[key] == 0) sz--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}