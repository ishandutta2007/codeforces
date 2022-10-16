#include <iostream>

using namespace std;

const int MAXN = 105, MAXM = 10 * 1000 + 5;
char c[MAXN][MAXM];
int prv[MAXN][MAXM], nxt[MAXN][MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> c[i][j];
            c[i][j] -= '0';
        }
    for(int i = 0; i < n; i++) {
        prv[i][0] = (c[i][0]? 0 : -1);
        for(int j = 1; j < m; j++)
            prv[i][j] = (c[i][j]? j : prv[i][j - 1]);
        if(prv[i][m - 1] == -1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        nxt[i][m - 1] = (c[i][m - 1]? m - 1 : -1);
        for(int j = m - 2; j >= 0; j--)
            nxt[i][j] = (c[i][j]? j : nxt[i][j + 1]);
    }
    int ans = n * m;
    for(int i = 0; i < m; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++)
            sum += min((i - (prv[j][i] == -1? prv[j][m - 1] :
                             prv[j][i]) + m) % m,
                       ((nxt[j][i] == -1? nxt[j][0] : nxt[j][i]) - i + m) % m);
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}