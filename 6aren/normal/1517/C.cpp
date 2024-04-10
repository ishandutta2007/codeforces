#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    int n;
    cin >> n;
    vector<vector<int>> res(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            res[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pair<int, int> cur = {i, i};
        res[cur.first][cur.second] = x;
        for (int j = 1; j < x; j++) {
            for (int dir = 0; dir < 4; dir++) {
                int xx = cur.first + dx[dir];
                int yy = cur.second + dy[dir];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && res[xx][yy] == 0) {
                    res[xx][yy] = x;
                    cur = make_pair(xx, yy);
                    break;
                }
                assert(dir != 4);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << res[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}