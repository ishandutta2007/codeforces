#include <iostream>

using namespace std;

const int MAXN = 1005;
int a[MAXN][MAXN], up[MAXN][MAXN], ll[MAXN][MAXN],
    down[MAXN][MAXN], rr[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < m; i++)
        up[0][i] = a[0][i]? -1 : 0;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            up[i][j] = a[i][j]? up[i - 1][j] : i;
    for(int i = 0; i < n; i++) {
        ll[i][0] = a[i][0]? -1 : 0;
        for(int j = 1; j < m; j++)
            ll[i][j] = a[i][j]? ll[i][j - 1] : j;
    }
    for(int i = 0; i < m; i++)
        down[n - 1][i] = a[n - 1][i]? n : n - 1;
    for(int i = n - 2; i >= 0; i--)
        for(int j = 0; j < m; j++)
            down[i][j] = a[i][j]? down[i + 1][j] : i;
    for(int i = 0; i < n; i++) {
        rr[i][m - 1] = a[i][m - 1]? m : m - 1;
        for(int j = m - 2; j >= 0; j--)
            rr[i][j] = a[i][j]? rr[i][j + 1] : j;
    }
    for(int i = 0; i < q; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        x--;
        y--;
        if(op == 1) {
            a[x][y] ^= 1;
            for(int j = x; j < n; j++)
                up[j][y] = a[j][y]? (j? up[j - 1][y] : -1) : j;
            for(int j = y; j < m; j++)
                ll[x][j] = a[x][j]? (j? ll[x][j - 1] : -1) : j;
            for(int j = x; j >= 0; j--)
                down[j][y] = a[j][y]? (j == n - 1? n : down[j + 1][y]) : j;
            for(int j = y; j >= 0; j--)
                rr[x][j] = a[x][j]? (j == m - 1? m : rr[x][j + 1]) : j;
        }
        else {
            if(!a[x][y]) {
                cout << 0 << '\n';
                continue;
            }
            int l = -1, r = m, ans = 0;
            for(int j = x; j < n; j++) {
                l = max(l, ll[j][y]);
                r = min(r, rr[j][y]);
                if(l + 1 >= r)
                    break;
                ans = max(ans, (r - l - 1) * (j - x + 1));
            }
            l = -1;
            r = n;
            for(int j = y; j < m; j++) {
                l = max(l, up[x][j]);
                r = min(r, down[x][j]);
                if(l + 1 >= r)
                    break;
                ans = max(ans, (r - l - 1) * (j - y + 1));
            }
            l = -1;
            r = m;
            for(int j = x; j >= 0; j--) {
                l = max(l, ll[j][y]);
                r = min(r, rr[j][y]);
                if(l + 1 >= r)
                    break;
                ans = max(ans, (r - l - 1) * (x - j + 1));
            }
            l = -1;
            r = n;
            for(int j = y; j >= 0; j--) {
                l = max(l, up[x][j]);
                r = min(r, down[x][j]);
                if(l + 1 >= r)
                    break;
                ans = max(ans, (r - l - 1) * (y - j + 1));
            }
            cout << ans << '\n';
        }
    }
    return 0;
}