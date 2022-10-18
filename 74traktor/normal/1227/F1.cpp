#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2005;
int a[maxn];
int mod = 998244353;
int dp[maxn][2 * maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0][maxn] = 1;
    for (int i = 1; i <= n; ++i) {
        set < int > Q = {a[i], a[i % n + 1]};
        for (int j = 1; j <= k; ++j) {
            if (Q.find(j) == Q.end()) {
                Q.insert(j);
                break;
            }
        }
        for (auto key : Q) {
            int val = 0;
            if (key == a[i]) val--;
            if (key == a[i % n + 1]) val++;
            int cnt = 1;
            if (key != a[i] && key != a[i % n + 1]) cnt = k - (int)Q.size() + 1;
            for (int j = 0; j < 2 * maxn; ++j) {
                if (j - val >= 0 && j - val < 2 * maxn) dp[i][j] += dp[i - 1][j - val] * cnt;
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = maxn + 1; i < 2 * maxn; ++i) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}