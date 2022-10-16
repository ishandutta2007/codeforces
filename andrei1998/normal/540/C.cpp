#include <iostream>
#include <cstring>

#define NMAX 505
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
char mat[NMAX][NMAX];

bool vis[NMAX][NMAX];
void dfs (int lin, int col) {
    vis[lin][col] = true;

    if (mat[lin][col] == 'X')
        return ;

    int nx, ny;
    for (int k = 0; k < 4; k++) {
        nx = lin + dx[k];
        ny = col + dy[k];

        if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && !vis[nx][ny])
            dfs(nx, ny);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin.get();
        cin.get(mat[i] + 1, NMAX);
    }

    int r1, c1;
    int r2, c2;

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    if (r1 == r2 && c1 == c2) {
        int cate = 0;

        int nx, ny;
        for (int k = 0; k < 4; k++) {
            nx = r2 + dx[k];
            ny = c2 + dy[k];

            if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && mat[nx][ny] == '.')
                cate ++;
        }

        if (cate > 0)
            cout << "YES\n";
        else
            cout << "NO\n";

        return 0;
    }

    mat[r1][c1] = '.';
    dfs(r1, c1);


    if (!vis[r2][c2]) {
        cout << "NO\n";
        return 0;
    }

    if (mat[r2][c2] == 'X') {
        cout << "YES\n";
        return 0;
    }

    int cate = 0;

    int nx, ny;
    for (int k = 0; k < 4; k++) {
        nx = r2 + dx[k];
        ny = c2 + dy[k];

        if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && mat[nx][ny] == '.')
            cate ++;
    }

    if (cate >= 2)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}