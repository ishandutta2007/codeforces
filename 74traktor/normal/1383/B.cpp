#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int a[maxn], b[maxn];
int cnt[31];

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
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans = (ans^a[i]);
        if (ans == 0) {
            cout << "DRAW" << '\n';
            continue;
        }
        int pos = 0;
        for (int i = 0; i < 30; ++i) {
            if ((ans&(1 << i)) > 0) pos = i;
        }
        int cnt_good = 0, cnt_bad = 0;
        for (int i = 1; i <= n; ++i) {
            if ((a[i]&(1 << pos)) > 0) cnt_good++;
            else cnt_bad++;
        }
        assert(cnt_good % 2 == 1);
        if (cnt_bad % 2 == 0 && (cnt_good - 1) % 4 != 0) cout << "LOSE" << '\n';
        else cout << "WIN" << '\n';
    }
    return 0;
}