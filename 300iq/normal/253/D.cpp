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

const int MAXN = (int) 400 + 7;
char a[MAXN][MAXN];
int dp[MAXN][MAXN];

int get(int x1, int y1, int x2, int y2) {
    return dp[x2][y2] - (y1 > 0) * dp[x2][y1 - 1] - (x1 > 0) * dp[x1 - 1][y2] + (x1 > 0 && y1 > 0) * dp[x1 - 1][y1 - 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, abc;
    scanf("%d%d%d", &n, &m, &abc);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = (i > 0) * dp[i - 1][j] + (j > 0) * dp[i][j - 1] - (i > 0 && j > 0) * dp[i - 1][j - 1] + (a[i][j] == 'a');
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            int cur[26];
            memset(cur, 0, sizeof cur);
            int last = 0;
            for (int j = 0; j < m; j++) {
                int c = a[i][j] - 'a';
                while (last < m && get(i, j, k, last) <= abc) {
                    if (a[i][last] == a[k][last]) {
                        cur[a[i][last] - 'a']++;
                    }
                    last++;
                }
                if (last > j && a[i][j] == a[k][j]) {
                    cur[c] -= (get(i, j, k, j)) <= abc;
                    ans += cur[c];
                }
            }
        }
    }
    printf("%lld\n", ans);
}