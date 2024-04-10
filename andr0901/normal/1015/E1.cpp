#include <bits/stdc++.h>

using namespace std;

vector <vector <char>> field;
vector <vector <bool>> visited;
int n, m;

int up(int x, int y) {
    int ans = -1;
    while (y >= 0 && field[x][y] == '*') {
        ans++;
        y--;
    }
    return ans;
}

int down(int x, int y) {
    int ans = -1;
    while (y < m && field[x][y] == '*') {
        ans++;
        y++;
    }
    return ans;
}

int right(int x, int y) {
    int ans = -1;
    while (x < n && field[x][y] == '*') {
        ans++;
        x++;
    }
    return ans;
}

int left(int x, int y) {
    int ans = -1;
    while (x >= 0 && field[x][y] == '*') {
        ans++;
        x--;
    }
    return ans;
}

int calcLen(int x, int y) {
    return min({up(x, y), down(x, y), right(x, y), left(x, y)});
}

void change(int x, int y, int len) {
    visited[x][y] = 1;
    for (int i = 1; i <= len; i++) {
        visited[x + i][y] = 1;
        visited[x - i][y] = 1;
        visited[x][y + i] = 1;
        visited[x][y - i] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    field.resize(n, vector <char> (m));
    visited.resize(n, vector <bool> (m, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
            if (field[i][j] == '*')
                visited[i][j] = 0;
        }
    }
    vector <vector <int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                int len = calcLen(i, j);
                if (len > 0) {
                    //cout <<  i << " " << j << "\n";
                    change(i, j, len);
                    /*for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++)
                            cout << visited[i][j];
                        cout << "\n";
                    }*/
                    ans.push_back({i + 1, j + 1, len});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
    }
    return 0;
}