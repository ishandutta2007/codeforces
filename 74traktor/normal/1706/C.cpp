#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5, k = 5;
int h[maxn], v[maxn], inf = 1e18;
map < int, int > dp[maxn];

inline int get(int i, int j) {
    if (dp[i].find(j) == dp[i].end()) return inf;
    return dp[i][j];
}

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
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 2; i < n; i++) v[i] = max(0ll, 1 + max(h[i - 1] - h[i], h[i + 1] - h[i]));
        dp[1][0] = 0, dp[0][0] = 0;
        for (int i = 2; i < n; i++) {
            for (int cnt = i / 2 - k; cnt <= i / 2 + k; ++cnt) {
                if (dp[i - 1].find(cnt) != dp[i - 1].end()) {
                    dp[i][cnt] = dp[i - 1][cnt];
                } else dp[i][cnt] = inf;
                dp[i][cnt] = min(dp[i][cnt], get(i - 2, cnt - 1) + v[i]);
            }
        }
        cout << dp[n - 1][(n - 1) / 2] << '\n';
    }
    return 0;
}