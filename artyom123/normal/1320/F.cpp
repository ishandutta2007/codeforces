#include <bits/stdc++.h>

using namespace std;

vector <int> dx = {1, -1, 0, 0, 0, 0};
vector <int> dy = {0, 0, 1, -1, 0, 0};
vector <int> dz = {0, 0, 0, 0, 1, -1};

struct cube{
    int x, y, z;
    int dir;
    int col;
    cube(){}
    cube(int _x, int _y, int _z, int _dir, int _col) {
        x = _x;
        y = _y;
        z = _z;
        dir = _dir;
        col = _col;
    }
};

int main() {
    queue <cube> q;
    int n, m, k;
    cin >> n >> m >> k;
    int emp[n][m][k];
    int col[n][m][k];
    vector <cube> in[n][m][k];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int p = 0; p < k; p++) {
                emp[i][j][p] = 0;
                col[i][j][p] = -1;
                in[i][j][p].clear();
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int p = 0; p < k; p++) {
            cin >> col[0][j][p];
            if (col[0][j][p] == 0) {
                for (int i = 0; i < n; i++) {
                    emp[i][j][p] = 1;
                }
            } else {
                q.push(cube(0, j, p, 0, col[0][j][p]));
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int p = 0; p < k; p++) {
            cin >> col[n - 1][j][p];
            if (col[n - 1][j][p] == 0) {
                for (int i = 0; i < n; i++) {
                    emp[i][j][p] = 1;
                }
            } else {
                q.push(cube(n - 1, j, p, 1, col[n - 1][j][p]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < k; p++) {
            cin >> col[i][0][p];
            if (col[i][0][p] == 0) {
                for (int j = 0; j < m; j++) {
                    emp[i][j][p] = 1;
                }
            } else {
                q.push(cube(i, 0, p, 2, col[i][0][p]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < k; p++) {
            cin >> col[i][m - 1][p];
            if (col[i][m - 1][p] == 0) {
                for (int j = 0; j < m; j++) {
                    emp[i][j][p] = 1;
                }
            } else {
                q.push(cube(i, m - 1, p, 3, col[i][m - 1][p]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> col[i][j][0];
            if (col[i][j][0] == 0) {
                for (int p = 0; p < k; p++) {
                    emp[i][j][p] = 1;
                }
            } else {
                q.push(cube(i, j, 0, 4, col[i][j][0]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> col[i][j][k - 1];
            if (col[i][j][k - 1] == 0) {
                for (int p = 0; p < k; p++) {
                    emp[i][j][p] = 1;
                }
            } else {
                q.push(cube(i, j, k - 1, 5, col[i][j][k - 1]));
            }
        }
    }
    int ans[n][m][k];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int p = 0; p < k; p++) {
                ans[i][j][p] = -1;
            }
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.x < 0 || cur.x >= n || cur.y < 0 || cur.y >= m || cur.z < 0 || cur.z >= k) {
            cout << -1;
            return 0;
        }
        if (emp[cur.x][cur.y][cur.z]) {
            q.push(cube(cur.x + dx[cur.dir], cur.y + dy[cur.dir], cur.z + dz[cur.dir], cur.dir, cur.col));
            continue;
        }
        if (ans[cur.x][cur.y][cur.z] == -1) {
            ans[cur.x][cur.y][cur.z] = cur.col;
            in[cur.x][cur.y][cur.z].push_back(cur);
            continue;
        }
        bool correct = true;
        for (auto &f : in[cur.x][cur.y][cur.z]) {
            if (f.col != cur.col) {
                correct = false;
            }
        }
        in[cur.x][cur.y][cur.z].push_back(cur);
        if (correct) {
            continue;
        }
        emp[cur.x][cur.y][cur.z] = 1;
        ans[cur.x][cur.y][cur.z] = 0;
        for (auto &f : in[cur.x][cur.y][cur.z]) {
            q.push(cube(f.x + dx[f.dir], f.y + dy[f.dir], f.z + dz[f.dir], f.dir, f.col));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int p = 0; p < k; p++) {
                if (ans[i][j][p] == -1) {
                    cout << 0 << " ";
                    continue;
                }
                cout << ans[i][j][p] << " ";
            }
        }
    }
    return 0;
}