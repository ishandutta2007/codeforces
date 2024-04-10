#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> res(h, vector<int>(w, 0));
        auto check = [&](int x, int y) {
            if (x < 0 || x >= h || y < 0 || y >= w) return true;
            return res[x][y] == 0;
        };
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || j == 0 || i + 1 == h || j + 1 == w) {
                    bool ok = true;
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            ok &= check(i + dx, j + dy);
                        }
                    }
                    if (ok) res[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << res[i][j];
            }
            cout << '\n';
        }

    }

    return 0;
}