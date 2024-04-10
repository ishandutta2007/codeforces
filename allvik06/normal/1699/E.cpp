#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <bool> ex(m + 1);
        int cnt_u = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (!ex[x]) ++cnt_u;
            ex[x] = true;
        }
        int ans = INF, mx = m + 1;
        vector <int> dp(m + 1, m + 1);
        vector <int> cnt(m + 2);
        cnt[m + 1] = cnt_u;

        auto upd = [&](int x, int y) {
            --cnt[x];
            ++cnt[y];
            while (!cnt[mx]) --mx;
        };

        for (int mn = m; mn > 0; --mn) {
            for (int i = mn; i <= m; i += mn) {
                int x = dp[i];
                int y = min({i, dp[i], dp[i / mn]});
                dp[i] = y;
                if (ex[i]) upd(x, y);
            }
            if (mx <= m) ans = min(ans, mx - mn);
        }
        cout << ans << "\n";
    }
}

/*

 */