#include<bits/stdc++.h>

using namespace std;

int const maxn = 2020;
int a[maxn], b[maxn], c[2 * maxn];
int dp[2][maxn][maxn], used[maxn][maxn];
int inf = 1e9;
pair < int, int > good[maxn * maxn], add[maxn * maxn];

inline int get(int i, int j) {
    int cur = 0;
    while (j > 0) {
        cur += j * c[i];
        ++i;
        j /= 2;
    }
    return cur;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ptr = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n + m; ++i) cin >> c[i];
    for (int z = 0; z <= 1; ++z) {
        for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp[z][i][j] = -inf;
    }
    dp[0][0][0] = 0;
    good[ptr++] = {0, 0};
    int ok = 0;
    for (int i = n; i >= 1; --i) {
        ok = (ok^1);
        int numb = 0;
        for (int j = 0; j < ptr; ++j) {
            int x = good[j].first, y = good[j].second;
            dp[ok][x][y] = max(dp[ok][x][y], dp[(1^ok)][x][y]);
            if (a[i] == x) {
                dp[ok][x][y + 1] = max(dp[ok][x][y + 1], dp[(1^ok)][x][y] - b[i]);
                if (used[x][y + 1] == 0) {
                    used[x][y + 1] = 1;
                    add[numb++] = {x, y + 1};
                }
            }
            if (a[i] > x && y == 0) {
                dp[ok][a[i]][1] = max(dp[ok][a[i]][1], dp[(1^ok)][x][y] - b[i]);
                if (used[a[i]][1] == 0) {
                    used[a[i]][1] = 1;
                    add[numb++] = {a[i], 1};
                }
            }
        }
        for (int j = 0; j < numb; ++j) good[ptr++] = add[j];
        for (int j = 0; j < ptr; ++j) {
            int x = good[j].first, y = good[j].second, sum = 0, f = dp[ok][x][y];
            while (1) {
                if (y == 0) break;
                sum += y * c[x];
                dp[ok][x + 1][y / 2] = max(dp[ok][x + 1][y / 2], f + sum);
                if (used[x + 1][y / 2] == 0) {
                    used[x + 1][y / 2] = 1;
                    good[ptr++] = {x + 1, y / 2};
                }
                x++;
                y /= 2;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < ptr; ++i) {
        ans = max(ans, dp[ok][good[i].first][good[i].second] + get(good[i].first, good[i].second));
    }
    cout << ans << '\n';
    return 0;
}