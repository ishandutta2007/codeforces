#include <bits/stdc++.h>
using namespace std;

int best[11][505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < m; j++) cin >> a[i][j];
    }   
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < m; j++) cin >> b[i][j];
    }   

    if (k % 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
        return 0;
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            best[0][i][j] = 0;
        }
    }
    for (int t = 1; t <= k / 2; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                best[t][i][j] = 1e9;
                for (int dir = 0; dir < 4; dir++) {
                    int xx = i + dx[dir];
                    int yy = j + dy[dir];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                    int c = (dir % 2 ? a[min(i, xx)][min(j, yy)] : b[min(i, xx)][min(j, yy)]);
                    best[t][i][j] = min(best[t][i][j], best[t - 1][xx][yy] + c);
                }
            }
        }   
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << 2 * best[k / 2][i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}