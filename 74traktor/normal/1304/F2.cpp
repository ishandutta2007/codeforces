#include<bits/stdc++.h>

using namespace std;

int a[55][20005];
int pref[55][20005];
int dp[55][20005];
int imax[(1 << 18)], imax1[(1 << 18)], imax2[(1 << 18)];
int k;
int inf = 1e9 + 7;

void build(int i, int l, int r, int x) {
    if (r - l == 1) {
        imax[i] = dp[x][l] + pref[x + 1][l + k - 1] - pref[x + 1][l - 1];
        imax1[i] = dp[x][l] - pref[x + 1][l - 1];
        //if (l == 3 && x == 1) cout << imax1[i] << endl;
        imax2[i] = dp[x][l] + pref[x + 1][l + k - 1];
        return;
    }
    int m = (r + l) / 2;
    build(2 * i + 1, l, m, x);
    build(2 * i + 2, m, r, x);
    imax[i] = max(imax[2 * i + 1], imax[2 * i + 2]);
    imax1[i] = max(imax1[2 * i + 1], imax1[2 * i + 2]);
    imax2[i] = max(imax2[2 * i + 1], imax2[2 * i + 2]);
}

int get(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return -inf;
    if (lq <= l && r <= rq) return imax[i];
    int m = (r + l) / 2;
    return max(get(2 * i + 1, l, m, lq, rq), get(2 * i + 2, m, r, lq, rq));
}

int get1(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return -inf;
    if (lq <= l && r <= rq) return imax1[i];
    int m = (r + l) / 2;
    return max(get1(2 * i + 1, l, m, lq, rq), get1(2 * i + 2, m, r, lq, rq));
}

int get2(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return -inf;
    if (lq <= l && r <= rq) return imax2[i];
    int m = (r + l) / 2;
    return max(get2(2 * i + 1, l, m, lq, rq), get2(2 * i + 2, m, r, lq, rq));
}


main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            pref[i][j] = pref[i][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            for (int j = 1; j + k - 1 <= m; ++j) dp[i][j] = pref[i][j + k - 1] - pref[i][j - 1];
        }
        else {
            build(0, 1, m - k + 2, i - 1);
            for (int j = 1; j + k - 1 <= m; ++j) {
                int L = j, R = j + k - 1;
                if (R + 1 <= m - k + 1) dp[i][j] = max(dp[i][j], get(0, 1, m - k + 2, R + 1, m - k + 2) + pref[i][R] - pref[i][L - 1]);
                if (L - k >= 1) dp[i][j] = max(dp[i][j], get(0, 1, m - k + 2, 1, L - k + 1) + pref[i][R] - pref[i][L - 1]);
                //if (i == 2 && j == 3) cout << dp[i][j] << endl;
                dp[i][j] = max(dp[i][j], get1(0, 1, m - k + 2, max(j - k + 1, 1), j + 1) + pref[i][R]);
                //if (i == 2 && j == 3) cout << dp[i][j] << " " << max(j - k + 1, 1) << " " << j << " " << get1(0, 1, m - k + 2, max(j - k + 1, 1), j + 1) << endl;
                dp[i][j] = max(dp[i][j], get2(0, 1, m - k + 2, j, min(j + k, m - k + 2)) - pref[i][L - 1]);
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
    }
    int ans = 0;
    for (int j = 1; j + k - 1 <= m; ++j) ans = max(ans, dp[n][j]);
    cout << ans << '\n';
    return 0;
}