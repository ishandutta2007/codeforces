#include<bits/stdc++.h>

using namespace std;

int x[105];

main() {
#ifdef karpovich
    freopen("input.txt", "r", stdin);
#endif // karpovich
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, l;
    cin >> t;
    while (t--) {
        cin >> n >> l;
        for (int i = 1; i <= n; ++i) cin >> x[i];
        int ans = 0;
        for (int i = 0; i < l; ++i) {
            int cnt = 0;
            for (int j = 1; j <= n; ++j) {
                if ((x[j]&(1 << i))) cnt++;
            }
            if (cnt >= (n + 1) / 2) ans += (1 << i);
        }
        cout << ans << '\n';
    }
    return 0;
}