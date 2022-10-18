#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
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
        int mx = 0;
        for (int i = 0; i < maxn; i++) open[i].clear();
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i - 1]) continue;
            open[a[i] / k].push_back(i);
            mx = max(mx, a[i] / k);
        }
        int ans = maxn;
        for (int v = 0; v <= a[1]; v++) {
            ans = min(ans, mx - v);
            if (v == a[1]) break;
            for (auto key : open[v]) {
                int nxt = a[key] / (a[key] / (v + 1));
                open[nxt].push_back(key);
                mx = max(mx, nxt);
            }
            vector < int > ().swap(open[v]);
        }
        cout << ans << '\n';
    }
    return 0;
}