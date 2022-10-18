#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 505;
pair < ll, int > dp[maxn][maxn];
int a[maxn], b[maxn];
ll inf = 1e15;
int k, s;

inline pair < ll, int > to(ll cnt, int was_b, int r, int b) {
    s = (r + b) / k, b = min(b, (r + b) % k);
    s += (was_b + b) / k, was_b = (was_b + b) % k;
    return {cnt + (ll)s, was_b};
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    for (int j = 0; j <= n; ++j) {
        for (int i = 0; i < k; ++i) {
            dp[j][i] = {-inf, -inf};
        }
    }
    dp[0][0] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            int nxt;
            ll adds;
            if (dp[i - 1][j].first < 0) continue;
            for (int add = 0; add < min(k, a[i] + 1); ++add) {
                nxt = add + j, adds = 0;
                if (nxt >= k) nxt -= k, adds = 1;
                dp[i][nxt] = max(dp[i][nxt], to(dp[i - 1][j].first + adds, dp[i - 1][j].second, a[i] - add, b[i]));
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < k; ++i) ans = max(ans, dp[n][i].first);
    cout << ans << '\n';
    return 0;
}