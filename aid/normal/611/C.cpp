#include <iostream>

using namespace std;

const int MAXN = 505;
char c[MAXN][MAXN];
int s[2][MAXN][MAXN];

int getSum(int t, int x0, int y0, int x1, int y1) {
    if(x1 < 0 || y1 < 0)
        return 0;
    int res = s[t][x1][y1];
    if(x0)
        res -= s[t][x0 - 1][y1];
    if(y0)
        res -= s[t][x1][y0 - 1];
    if(x0 && y0)
        res += s[t][x0 - 1][y0 - 1];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m - 1; j++) {
            if(c[i][j] == '.' && c[i][j + 1] == '.')
                s[0][i][j] = 1;
            if(i)
                s[0][i][j] += s[0][i - 1][j];
            if(j)
                s[0][i][j] += s[0][i][j - 1];
            if(i && j)
                s[0][i][j] -= s[0][i - 1][j - 1];
        }
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m; j++) {
            if(c[i][j] == '.' && c[i + 1][j] == '.')
                s[1][i][j] = 1;
            if(i)
                s[1][i][j] += s[1][i - 1][j];
            if(j)
                s[1][i][j] += s[1][i][j - 1];
            if(i && j)
                s[1][i][j] -= s[1][i - 1][j - 1];
        }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        x0--;
        y0--;
        x1--;
        y1--;
        cout << getSum(0, x0, y0, x1, y1 - 1) +
            getSum(1, x0, y0, x1 - 1, y1) << '\n';
    }
    return 0;
}