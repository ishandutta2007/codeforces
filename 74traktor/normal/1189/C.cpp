#include <bits/stdc++.h>

using namespace std;

int const maxn = 100005;
int dp[20][maxn];
int tmp[20][maxn];
int a[maxn];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) tmp[0][i] = a[i];
    for (int i = 1; i <= 18; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x = tmp[i - 1][j], y = tmp[i - 1][j + (1 << (i - 1))], ok = 0;
            if (x + y >= 10) ok = 1;
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j + (1 << (i - 1))] + ok;
            tmp[i][j] = (x + y) % 10;
        }
    }
    int q, l, r;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> l >> r;
        for (int j = 0; j <= 18; ++j) {
            if ((1 << j) == r - l + 1) cout << dp[j][l] << '\n';
        }
    }
    return 0;
}