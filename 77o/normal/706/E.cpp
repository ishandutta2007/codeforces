#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> mat(n + 1, vector<int>(m + 1));
    auto r = mat;
    auto dd = mat;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            r[i][j] = i * (m + 1) + j + 1;
            dd[i][j] = i * (m + 1) + j + m + 1;
        }
    auto move_right = [&](int pos) {
        return r[pos / (m + 1)][pos % (m + 1)];
    };
    auto move_down = [&](int pos) {
        return dd[pos / (m + 1)][pos % (m + 1)];
    };
    while (q--) {
        int a, b, c, d, h, w;
        cin >> a >> b >> c >> d >> h >> w;
        auto swap_column = [&](int a, int b, int c, int d) {
            int cur1 = dd[0][b];
            for (int i = 0; i < a - 1; i++)
                cur1 = move_down(cur1);
            int cur2 = dd[0][d];
            for (int i = 0; i < c - 1; i++)
                cur2 = move_down(cur2);
            for (int i = 0; i < h; i++) {
                int x1 = cur1 / (m + 1);
                int y1 = cur1 % (m + 1);
                int x2 = cur2 / (m + 1);
                int y2 = cur2 % (m + 1);
                swap(r[x1][y1], r[x2][y2]);
                cur1 = move_down(cur1);
                cur2 = move_down(cur2);
            }
        };
        auto swap_row = [&](int a, int b, int c, int d) {
            int cur1 = r[a][0];
            for (int i = 0; i < b - 1; i++)
                cur1 = move_right(cur1);
            int cur2 = r[c][0];
            for (int i = 0; i < d - 1; i++)
                cur2 = move_right(cur2);
            for (int i = 0; i < w; i++) {
                int x1 = cur1 / (m + 1);
                int y1 = cur1 % (m + 1);
                int x2 = cur2 / (m + 1);
                int y2 = cur2 % (m + 1);
                swap(dd[x1][y1], dd[x2][y2]);
                cur1 = move_right(cur1);
                cur2 = move_right(cur2);
            }
        };
        swap_column(a, b - 1, c, d - 1);
        swap_column(a, b + w - 1, c, d + w - 1);
        swap_row(a - 1, b, c - 1, d);
        swap_row(a + h - 1, b, c + h - 1, d);
    }
    for (int i = 1; i <= n; i++) {
        int cur = r[i][0];
        for (int j = 1; j <= m; j++) {
            int x = cur / (m + 1);
            int y = cur % (m + 1);
            cout << mat[x][y] << " \n"[j == m];
            cur = r[x][y];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}