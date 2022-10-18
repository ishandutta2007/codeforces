#include<bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 1e5 + 5;
int a[maxn], b[maxn][8], dp[maxn][128], cnt[128];
int inf = 1e18;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, k, ans = 0;
    cin >> n >> p >> k;
    for (int i = 0; i < (1 << p); ++i) {
        for (int j = 0; j < p; ++j) if ((i&(1 << j)) > 0) cnt[i]++;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= p; ++j) cin >> b[i][j];
    }
    vector < int > Q;
    for (int i = 1; i <= n; ++i) {
        Q.push_back(i);
    }
    sort(Q.begin(), Q.end(), [](int x, int y) {
        return a[x] > a[y];
    });
    for (int i = 0; i <= n; ++i) {
        for (int mask = 0; mask < (1 << p); ++mask) dp[i][mask] = -inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int f = Q[i - 1];
        for (int mask = 0; mask < (1 << p); ++mask) {
            dp[i][mask] = dp[i - 1][mask];
            if (cnt[mask] + k >= i) dp[i][mask] += a[f];
        }
        for (int j = 0; j < p; ++j) {
            for (int mask = 0; mask < (1 << p); ++mask) {
                if ((mask&(1 << j)) > 0) continue;
                int to = mask + (1 << j);
                dp[i][to] = max(dp[i][to], dp[i - 1][mask] + b[f][j + 1]);
            }
        }
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
    }
    cout << dp[n][(1 << p) - 1] << '\n';
    return 0;
}