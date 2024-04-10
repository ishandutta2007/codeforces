#include <bits/stdc++.h>

using namespace std;

int const maxn = 5e5, k = 720;
int a[maxn];
int answer[k][k];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, t, x, y;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> t >> x >> y;
        if (t == 1) {
            for (int go = 1; go < k; ++go) {
                answer[go][x % go] += y;
            }
            a[x] += y;
        }
        else {
            if (x >= k) {
                int ans = 0;
                for (int j = y; j <= 500000; j += x) ans += a[j];
                cout << ans << '\n';
            }
            else cout << answer[x][y] << '\n';
        }
    }
    return 0;
}