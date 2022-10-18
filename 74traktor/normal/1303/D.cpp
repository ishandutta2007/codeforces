#include<bits/stdc++.h>

using namespace std;

#define int long long
int a[100005];
int cnt[61];
int dp[61][100005];
int best[61];
int inf = 1e18;

main() {
#ifdef HOME
    freopen("input.txt", "r",  stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, sum = 0, ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) cin >> a[i];
        for (int i = 1; i <= m; ++i) sum += a[i];
        for (int j = 0; j <= 60; ++j) cnt[j] = 0;
        if (sum < n) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 1; i <= m; ++i) {
            int good = 0;
            while (a[i] != 1) {
                good++;
                a[i] /= 2;
            }
            cnt[good + 1]++;
        }
        for (int j = 0; j <= 60; ++j) {
            for (int i = 0; i <= m; ++i) dp[j][i] = inf;
        }
        dp[0][0] = 0;
        best[0] = 0;
        for (int j = 1; j <= 60; ++j) {
            int oks = 0;
            if ((n&(1ll << (j - 1))) > 0) oks = 1;
            for (int lst = 0; lst <= m; ++lst) {
                //if (j == 1 && lst == 0) cout << dp[j - 1][lst] << " " << lst / 2 + cnt[j] - oks << '\n';
                if (dp[j - 1][lst] != inf && lst / 2 + cnt[j] - oks >= 0) {
                    dp[j][lst / 2 + cnt[j] - oks] = min(dp[j][lst / 2 + cnt[j] - oks], dp[j - 1][lst]);
                }
            }
            if (cnt[j] > oks) {
                for (int z = j - 1; z >= 1; --z) {
                    dp[j][cnt[j] - oks - 1] = min(dp[j][cnt[j] - oks - 1], best[z - 1] + j - z);
                }
            }
            best[j] = inf;
            for (int lst = 0; lst <= m; ++lst) best[j] = min(best[j], dp[j][lst]);
        }
        //cout << dp[1][2] << endl;
        cout << best[60] << '\n';
    }
    return 0;
}