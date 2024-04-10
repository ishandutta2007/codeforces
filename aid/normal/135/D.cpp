#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
char c[MAXN][MAXN], used[MAXN][MAXN], onCycle[MAXN][MAXN];
int col[MAXN][MAXN], n, m,
    gox[] = {-1, -1, -1, 0, 1, 1, 1, 0}, goy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool bad;

void dfs1(int x, int y, int color) {
    col[x][y] = color;
    for(int i = 1; i < 8; i += 2) {
        int xx = x + gox[i], yy = y + goy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m ||
           c[xx][yy] != '1' || col[xx][yy] != -1)
            continue;
        dfs1(xx, yy, color);
    }
}

void dfs0(int x, int y, vector< pair<int, int> > &cycle) {
    used[x][y] = true;
    for(int i = 0; i < 8; i++) {
        int xx = x + gox[i], yy = y + goy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m) {
            bad = true;
            continue;
        }
        if(c[xx][yy] == '1') {
            cycle.push_back(make_pair(xx, yy));
            continue;
        }
        if(used[xx][yy])
            continue;
        dfs0(xx, yy, cycle);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];
    int ans = 0;
    for(int i = 0; i + 1 < n; i++)
        for(int j = 0; j + 1 < m; j++)
            if(c[i][j] == '1' && c[i][j + 1] == '1' &&
               c[i + 1][j] == '1' && c[i + 1][j + 1] == '1')
                ans = 4;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            col[i][j] = -1;
    int freec = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(c[i][j] == '1' && col[i][j] == -1)
                dfs1(i, j, freec++);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(c[i][j] == '0' && !used[i][j]) {
                vector< pair<int, int> > cycle;
                bad = false;
                dfs0(i, j, cycle);
                if(bad)
                    continue;
                sort(cycle.begin(), cycle.end());
                cycle.resize(unique(cycle.begin(), cycle.end()) -
                             cycle.begin());
                for(size_t k = 1; k < cycle.size(); k++)
                    if(col[cycle[k].first][cycle[k].second] !=
                       col[cycle[0].first][cycle[0].second]) {
                        bad = true;
                        break;
                    }
                if(bad)
                    continue;
                for(size_t k = 0; k < cycle.size(); k++)
                    onCycle[cycle[k].first][cycle[k].second] = true;
                for(size_t k = 0; k < cycle.size(); k++) {
                    int x = cycle[k].first, y = cycle[k].second, cnt = 0;
                    for(int l = 1; l < 8; l += 2) {
                        int xx = x + gox[l], yy = y + goy[l];
                        if(0 <= xx && xx < n && 0 <= yy && yy < m)
                            cnt += onCycle[xx][yy];
                    }
                    if(cnt != 2) {
                        bad = true;
                        break;
                    }
                }
                for(size_t k = 0; k < cycle.size(); k++)
                    onCycle[cycle[k].first][cycle[k].second] = false;
                if(bad)
                    continue;
                ans = max(ans, (int)cycle.size());
            }
    cout << ans << '\n';
    return 0;
}