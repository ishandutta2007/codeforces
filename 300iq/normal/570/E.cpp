#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define nfor(i, n) for(int i = (int)(n); i >= 0; i--)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = (int) 500 + 7;
const int MOD = (int) 1e9 + 7;

int dp[MAXN][MAXN];
int ndp[MAXN][MAXN];
int press[MAXN][MAXN];
char f[MAXN][MAXN];
vector <pair <int, int> > g[2][MAXN * 3];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int dist = n - 1 + m - 1;
    forn (i, n) {
        forn (j, m) {
            scanf(" %c", &f[i][j]);
            press[i][j] = g[0][i + j].size();
            g[0][i + j].pb({i, j});
            g[1][(n - 1 - i) + (m - 1 - j)].pb({i, j});
           
        }
    }
    nfor (t, dist / 2 + 1) {
        memset(ndp, 0, sizeof ndp);
        forn (i, g[0][t].size()) {
            forn (j, g[1][t].size()) {
                int x = g[0][t][i].fc, y = g[0][t][i].sc;
                int x1 = g[1][t][j].fc, y1 = g[1][t][j].sc;
                if (f[x][y] == f[x1][y1] && x1 >= x && y1 >= y) {
                    if (abs(x - x1) + abs(y - y1) <= 1) {
                        ndp[press[x][y]][press[x1][y1]] = 1;
                    } else {
                        int inc = 0;
                        inc += (x1 > 0 && x + 1 < n) * dp[press[x + 1][y]][press[x1 - 1][y1]];
                        inc %= MOD;
                        inc += (y1 > 0 && x + 1 < n) * dp[press[x + 1][y]][press[x1][y1 - 1]];
                        inc %= MOD;
                        inc += (x1 > 0 && y + 1 < m) * dp[press[x][y + 1]][press[x1 - 1][y1]];
                        inc %= MOD;
                        inc += (y1 > 0 && y + 1 < m) * dp[press[x][y + 1]][press[x1][y1 - 1]];
                        inc %= MOD;
                        ndp[press[x][y]][press[x1][y1]] = inc;
                    }
                }
            }
        }
        forn (i, n) {
            forn (j, m) {
                dp[i][j] = ndp[i][j];
            }
        }
    }
    printf("%d\n", dp[press[0][0]][press[n - 1][m - 1]]);
}