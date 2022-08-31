#include <bits/stdc++.h>

using namespace std;

#define y1 ildar
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

const int N = (int) 1000 + 1;
const int LOG = (int) 10;
int st[N][N][LOG][LOG];
int dp[N][N];
int a[N][N];
int lg[N];
int n, m;

int get(int x1, int y1, int x2, int y2) {
    int a = lg[x2 - x1], b = lg[y2 - y1];
    return max(
            max(st[x1][y1][a][b], st[x2 - (1 << a)][y1][a][b]),
            max(st[x1][y2 - (1 << b)][a][b], st[x2 - (1 << a)][y2 - (1 << b)][a][b])
            );
}

void build() {
    for (int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            st[i][j][0][0] = dp[i][j];
        }
    }
    for (int a = 0; a < LOG; a++) {
        for (int b = 0; b < LOG; b++) {
            if (a + b == 0) continue;
            for (int i = 0; i <= n - (1 << a); i++) {
                for (int j = 0; j <= m - (1 << b); j++) {
                    if (!a) {
                        st[i][j][a][b] = max(st[i][j][a][b - 1], st[i][j + (1 << (b - 1))][a][b - 1]); 
                    } else {
                        st[i][j][a][b] = max(st[i][j][a - 1][b], st[i + (1 << (a - 1))][j][a - 1][b]);
                    } 
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!a[i][j]) continue;    
            dp[i][j] = min((j > 0) * dp[i][j - 1], (i > 0) * dp[i - 1][j]);
            int k = dp[i][j];
            dp[i][j] += a[i - k][j - k];
        }
    }
    build();
    int q;
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1--, y1--;
        int l = 0, r = min(y2 - y1, x2 - x1) + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (get(x1 + m - 1, y1 + m - 1, x2, y2) >= m) {
                l = m;
            } else {
                r = m;
            }
        }
        printf("%d\n", l);
    }
}