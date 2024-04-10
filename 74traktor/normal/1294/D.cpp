#include<bits/stdc++.h>

using namespace std;

int const maxn = 400005;
int cnt[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, x, y, ans = 0;
    cin >> q >> x;
    for (int i = 1; i <= q; ++i) {
        cin >> y;
        cnt[y % x]++;
        while (1) {
            if (cnt[ans % x] > 0) {
                cnt[ans % x]--;
                ans++;
            }
            else break;
        }
        cout << ans << '\n';
    }
    return 0;
}