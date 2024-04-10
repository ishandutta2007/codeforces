#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = (int) 500 + 7;
bool vis[MAXN * MAXN];
bool used[MAXN][MAXN];
int comp[MAXN][MAXN];
int csz[MAXN * MAXN];
char a[MAXN][MAXN];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, c, ans;

bool good(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n && a[i][j] == '.');
}

void dfs(int i, int j) {
    used[i][j] = 1;
    comp[i][j] = c;
    csz[c]++;
    forn (t, 4) {
        int x = i + dx[t], y = j + dy[t];
        if (good(x, y) && !used[x][y]) {
            dfs(x, y);
        }
    }
}

void inc(int i, int j) {
    if (good(i, j)) {
        int r = comp[i][j];
        if (!vis[r]) {
            ans += csz[r];
            vis[r] = 1;
        }
    }
}

int main() {
    int k;
    scanf("%d%d", &n, &k);
    forn (i, n) {
        forn (j, n) {
            scanf(" %c", &a[i][j]);
        }
    }
    forn (i, n) {
        forn (j, n) {
            if (!used[i][j] && good(i, j)) {
                c++;
                dfs(i, j);
            }
        }
    }
    int res = 0;
    forn (j, n - k + 1) {
        forn (i, k) {
            fort (p, j, j + k) {
                csz[comp[i][p]]--;
            }
        }
        forn (i, n - k + 1) {
            ans = k * k;
            fort (x, i, i + k) {
                inc(x, j - 1);
                inc(x, j + k);
            }
            fort (y, j, j + k) {
                inc(i - 1, y);
                inc(i + k, y);
            }
            memset(vis, 0, sizeof vis);
            res = max(res, ans);
            if (i + k < n) {
                fort (y, j, j + k) {
                    csz[comp[i][y]]++;
                    csz[comp[i + k][y]]--;
                }
            } 
        }
        fort (x, n - k, n) {
            fort (y, j, j + k) {
                csz[comp[x][y]]++;
            }
        }
    }
    printf("%d", res);
    puts("");
}