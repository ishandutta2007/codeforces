#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int val[n][m], sum = 0, x_b = -1, y_b = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            val[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] > a[i][j]) continue;
                val[i][j] = 1;
                break;
            }
            if (!val[i][j] && a[i][j] > 1) {
                x_b = i;
                y_b = j;
            }
            sum += val[i][j];
        }
    }
    if (sum == n * m - 1) {
        cout << 0;
        return 0;
    }
    int cnt1 = 0, cnt2 = 0;
    int used[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            used[i][j] = 0;
        }
    }
    for (int x1 = x_b - 1; x1 <= x_b + 1; ++x1) {
        if (x1 < 0 || x1 >= n) continue;
        for (int y1 = y_b - 1; y1 <= y_b + 1; ++y1) {
            if (y1 < 0 || y1 >= m) continue;
            for (int x2 = 0; x2 < n; ++x2) {
                for (int y2 = 0; y2 < m; ++y2) {
                    swap(a[x1][y1], a[x2][y2]);
                    int tmp_sum = sum;
                    for (int x = x1 - 1; x <= x1 + 1; ++x) {
                        if (x < 0 || x >= n) continue;
                        for (int y = y1 - 1; y <= y1 + 1; ++y) {
                            if (y < 0 || y >= m) continue;
                            bool ok = false;
                            for (int k = 0; k < 4; ++k) {
                                int t_x = x + dx[k], t_y = y + dy[k];
                                if (t_x < 0 || t_x >= n || t_y < 0 || t_y >= m || a[t_x][t_y] > a[x][y]) continue;
                                ok = true;
                                break;
                            }
                            tmp_sum -= val[x][y];
                            tmp_sum += ok;
                            used[x][y] = true;
                        }
                    }
                    for (int x = x2 - 1; x <= x2 + 1; ++x) {
                        if (x < 0 || x >= n) continue;
                        for (int y = y2 - 1; y <= y2 + 1; ++y) {
                            if (y < 0 || y >= m) continue;
                            if (used[x][y]) continue;
                            bool ok = false;
                            for (int k = 0; k < 4; ++k) {
                                int t_x = x + dx[k], t_y = y + dy[k];
                                if (t_x < 0 || t_x >= n || t_y < 0 || t_y >= m || a[t_x][t_y] > a[x][y]) continue;
                                ok = true;
                                break;
                            }
                            tmp_sum -= val[x][y];
                            tmp_sum += ok;
                        }
                    }
                    for (int x = x1 - 1; x <= x1 + 1; ++x) {
                        if (x < 0 || x >= n) continue;
                        for (int y = y1 - 1; y <= y1 + 1; ++y) {
                            if (y < 0 || y >= m) continue;
                            used[x][y] = false;
                        }
                    }
                    if (tmp_sum == n * m - 1) {
                        if (x2 >= x_b - 1 && x2 <= x_b + 1 && y2 >= y_b - 1 && y2 <= y_b + 1) ++cnt2;
                        else ++cnt1;
                    }
                    swap(a[x1][y1], a[x2][y2]);
                }
            }
        }
    }
    int cnt = cnt1 + cnt2 / 2;
    if (cnt) cout << 1 << " " << cnt;
    else cout << 2;
}

/*

 */