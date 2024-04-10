#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long INF = 1e16 + 10;

int n, m, k, a[N];
long long dp[N][N][N], p[N][N];

long long call (int nn, int mm, int kk) {
    if (kk <= 0) return INF;
    if (nn == 1) {
        if (kk > 1) return INF;
        if (a[1] == 0) return p[1][mm];
        if (a[1] == mm) return 0;
        return INF;
    }
    if (dp[nn][mm][kk] != -1) return dp[nn][mm][kk];

    long long &ret = dp[nn][mm][kk];
    ret = INF;
    if (a[nn] != mm and a[nn] != 0) return ret;
    else if (a[nn] == mm) {
        if (a[nn - 1] == mm) {
            ret = min(ret, call(nn - 1, mm, kk));
        } else if (a[nn - 1] != 0) {
            ret = min(ret, call(nn - 1, a[nn - 1], kk - 1));
        } else {
            ret = min(ret, call(nn - 1, mm, kk));
            for (int i = 1; i <= m; ++i) {
                if (i != mm) ret = min(ret, call(nn - 1, i, kk - 1));
            }
        }
    } else {
        if (a[nn - 1] == mm) {
            ret = min(ret, p[nn][mm] + call(nn - 1, mm, kk));
        } else if (a[nn - 1] != 0) {
            ret = min(ret, p[nn][mm] + call(nn - 1, a[nn - 1], kk - 1));
        } else {
            ret = min(ret, p[nn][mm] + call(nn - 1, mm, kk));
            for (int i = 1; i <= m; ++i) {
                if (i != mm) ret = min(ret, p[nn][mm] + call(nn - 1, i, kk - 1));
            }
        }
    }
    return ret;
}

int main (int argc, char const *argv[]) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) scanf("%lld", p[i] + j);
    }
    memset(dp, -1, sizeof dp);

    long long ans = INF;
    for (int i = 1; i <= m; ++i) ans = min(ans, call(n, i, k));
    if (ans >= INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}