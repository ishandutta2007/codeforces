#include <iostream>

using namespace std;

const int MAXN = 41;
char t[MAXN][MAXN];
int dp0[MAXN], dp[MAXN][MAXN][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> t[i][j];
    for(int a = 0; a < n; a++)
        for(int b = 0; b < m; b++) {
            for(int i = b; i < m; i++)
                dp0[i] = a - 1;
            for(int c = a; c < n; c++)
                for(int d = b; d < m; d++) {
                    if(t[c][d] == '1')
                        dp0[d] = c;
                    int h = dp0[d];
                    for(int i = d; i >= b; i--) {
                        h = max(h, dp0[i]);
                        if(h == c)
                            break;
                        dp[a][b][c][d] += c - h;
                    }
                    if(c > a)
                        dp[a][b][c][d] += dp[a][b][c - 1][d];
                    if(d > b)
                        dp[a][b][c][d] += dp[a][b][c][d - 1];
                    if(c > a && d > b)
                        dp[a][b][c][d] -= dp[a][b][c - 1][d - 1];
                }
        }
    for(int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        cout << dp[a][b][c][d] << '\n';
    }
    return 0;
}