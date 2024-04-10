#include <iostream>

using namespace std;

const int MAXN = 105;
char c[MAXN][MAXN], cov[MAXN][MAXN], ans[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    for(int i = -n + 1; i <= n - 1; i++)
        for(int j = -n + 1; j <= n - 1; j++) {
            if(i == 0 && j == 0) {
                ans[n - 1 + i][n - 1 + j] = 'o';
                continue;
            }
            bool ok = true;
            for(int x = 0; x < n && ok; x++)
                for(int y = 0; y < n; y++)
                    if(c[x][y] == 'o') {
                        int xx = x + i, yy = y + j;
                        if(0 <= xx && xx < n && 0 <= yy && yy < n &&
                           c[xx][yy] == '.') {
                            ok = false;
                            break;
                        }
                    }
            if(ok) {
                ans[n - 1 + i][n - 1 + j] = 'x';
                for(int x = 0; x < n; x++)
                    for(int y = 0; y < n; y++)
                        if(c[x][y] == 'o') {
                            int xx = x + i, yy = y + j;
                            if(0 <= xx && xx < n && 0 <= yy && yy < n)
                                cov[xx][yy] = true;
                        }
            }
            else
                ans[n - 1 + i][n - 1 + j] = '.';
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(c[i][j] == 'x' && !cov[i][j]) {
                cout << "NO\n";
                return 0;
            }
    cout << "YES\n";
    for(int i = 0; i < 2 * n - 1; i++) {
        for(int j = 0; j < 2 * n - 1; j++)
            cout << ans[i][j];
        cout << '\n';
    }
    return 0;
}