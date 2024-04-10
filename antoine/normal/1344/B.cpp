#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 1009;
int n, m;
string grid[MxN + 9];
bool vis[MxN + 9][MxN + 9];

void bfs(const int startX, const int startY) {
    vector<pair<int, int>> q;
    q.emplace_back(startX, startY);
    vis[startX][startY] = 1;
    while(!q.empty()) {
        const int x = q.back().first;
        const int y = q.back().second;
        q.pop_back();
        for(int dx = -1; dx <= 1; ++dx)
            for(int dy = -1; dy <= 1; ++dy)
                if(abs(dx) + abs(dy) == 1) {
                    const int i = x + dx;
                    const int j = y + dy;
                    if(i < 0 || i >= n) continue;
                    if(j < 0 || j >= m) continue;
                    if(!vis[i][j] && grid[i][j] == '#') {
                        q.emplace_back(i, j);
                        vis[i][j] = 1;
                    }
                }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
    for (int i = 0; i < n; ++i) {
        char prev = '.';
        int flag = 0;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != prev) {
                if (++flag == 3) {
                    cout << -1;
                    return 0;
                }
                prev = grid[i][j];
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        char prev = '.';
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] != prev) {
                if (++flag == 3) {
                    cout << -1;
                    return 0;
                }
                prev = grid[i][j];
            }
        }
    }

    {
        vector<bool> rows(n, false), cols(m, false);
        vector<int> cntRows(n, 0), cntCols(m, 0);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == '#')
                    ++cntRows[i], ++cntCols[j], rows[i] = true, cols[j] = true;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(!cntRows[i] && !cntCols[j])rows[i] = true, cols[j] = true;
        for(bool b: rows)
            if(!b) {
                cout << -1;
                return 0;
            }
        for(bool b: cols)
            if(!b) {
                cout << -1;
                return 0;
            }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(!vis[i][j] && grid[i][j] == '#') {
                bfs(i, j);
                ++ans;
            }
    cout << ans;
    return 0;
}