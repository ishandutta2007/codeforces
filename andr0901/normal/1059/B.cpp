#include <bits/stdc++.h>

using namespace std;

vector <vector <bool>> field;

bool doable(int x, int y) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0)
                continue;
            if (!field[i + x][j + y]) return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    field.resize(n, vector <bool> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#')
                field[i][j] = 1;
            else
                field[i][j] = 0;
        }
    }
    vector <vector <bool>> ans(n, vector <bool> (m));
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (doable(i, j)) {
                for (int x = -1; x < 2; x++) {
                    for (int y = -1; y < 2; y++) {
                        if (x == 0 && y == 0)
                            continue;
                        ans[i + x][j + y] = 1;
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] != field[i][j]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}