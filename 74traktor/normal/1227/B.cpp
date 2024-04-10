#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int q[maxn], ans[maxn];

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
        for (int i = 1; i <= n; ++i) cin >> q[i];
        set < int > Q;
        int ok = 1;
        for (int i = 1; i <= n; ++i) Q.insert(i);
        for (int i = 1; i <= n; ++i) {
            if (q[i] > q[i - 1]) ans[i] = q[i];
            else {
                ans[i] = (*Q.begin());
            }
            if (Q.find(ans[i]) == Q.end() || ans[i] > q[i]) {
                ok = 0;
                cout << -1 << '\n';
                break;
            }
            Q.erase(ans[i]);
        }
        if (ok == 0) continue;
        for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}