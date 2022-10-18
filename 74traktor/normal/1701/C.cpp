#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int cnt[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, x;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        n = min(n, m);
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= m; i++) {
            cin >> x;
            cnt[x]++;
        }
        int lef = 0, righ = m + 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            int bal = 0;
            for (int i = 1; i <= n; i++) {
                if (cnt[i] <= mid) bal += (mid - cnt[i]) / 2;
                else bal -= (cnt[i] - mid);
            }
            if (bal >= 0) righ = mid;
            else lef = mid;
        }
        cout << righ << '\n';
    }
    return 0;
}