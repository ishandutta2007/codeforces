#include <iostream>

using namespace std;

const int MAXN = 505;
char lab[MAXN][MAXN];
int gox[] = {-1, 0, 1, 0}, goy[] = {0, -1, 0, 1}, n, m, t;

void dfs(int x, int y) {
    lab[x][y] = '.';
    t--;
    if(!t)
        return;
    for(int i = 0; i < 4; i++) {
        int xx = x + gox[i], yy = y + goy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m || lab[xx][yy] != 'X')
            continue;
        dfs(xx, yy);
        if(!t)
            return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int k;
    cin >> n >> m >> k;
    int s = 0, sx, sy;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if(lab[i][j] == '.') {
                lab[i][j] = 'X';
                sx = i;
                sy = j;
                s++;
            }
        }
    t = s - k;
    dfs(sx, sy);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << lab[i][j];
        cout << '\n';
    }
    return 0;
}