#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 100 + 7;
ll dp[MAXN][MAXN][MAXN];
int p[MAXN][MAXN];
int c[MAXN];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &p[i][j]);
        }
    }
    ll inf = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                dp[i][j][k] = LLONG_MAX; 
            }
        }
    }
    if (c[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i][1] = p[0][i];
        }
    } else {
        dp[0][c[0]][1] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                if (dp[i][j][k] == inf) continue;
                if (c[i + 1] == 0) {
                    for (int nc = 1; nc <= m; nc++) {
                        dp[i + 1][nc][k + (nc != j)] = min(dp[i + 1][nc][k + (nc != j)], dp[i][j][k] + p[i + 1][nc]);
                    }
                } else {
                    dp[i + 1][c[i + 1]][k + (c[i + 1] != j)] = min(dp[i + 1][c[i + 1]][k + (c[i + 1] != j)], dp[i][j][k]);
                }
            }
        }
    }
    ll ans = inf;
    for (int j = 1; j <= m; j++) {
        ans = min(ans, dp[n - 1][j][k]);
    }
    if (ans == inf) {
        puts("-1");
    } else {
        printf("%lld\n", ans);
    }
}