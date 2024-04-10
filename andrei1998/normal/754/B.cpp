#include <iostream>

using namespace std;

char mat[4][4];

const int dx[4] = {1, 1, 0, 1};
const int dy[4] = {0, 1, 1, -1};

bool won() {
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
            for (int k = 0; k < 3; ++ k) {
                int nx = i + 2 * dx[k];
                int ny = j + 2 * dy[k];

                if (nx < 4 && ny < 4) {
                    bool works = true;

                    nx = i, ny = j;
                    for (int l = 0; l < 3; ++ l, nx += dx[k], ny += dy[k])
                        if (mat[nx][ny] != 'x')
                            works = false;

                    if (works)
                        return true;
                }
            }
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
            for (int k = 3; k < 4; ++ k) {
                int nx = i + 2 * dx[k];
                int ny = j + 2 * dy[k];

                if (nx < 4 && ny >= 0) {
                    bool works = true;

                    nx = i, ny = j;
                    for (int l = 0; l < 3; ++ l, nx += dx[k], ny += dy[k])
                        if (mat[nx][ny] != 'x')
                            works = false;

                    if (works)
                        return true;
                }
            }
    return false;
}

int main()
{
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
            cin >> mat[i][j];

    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
            if (mat[i][j] == '.') {
                mat[i][j] = 'x';
                if (won()) {
                    cout << "YES\n";
                    return 0;
                }
                mat[i][j] = '.';
            }

    cout << "NO\n";
    return 0;
}