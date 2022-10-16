#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 505, gox[] = {-1, 0, 1, 0}, goy[] = {0, -1, 0, 1};
char c[MAXN][MAXN], used[MAXN][MAXN];
int id[MAXN][MAXN], sz[MAXN * MAXN], cnt[MAXN * MAXN], n, freeid, cur;
vector<int> g[MAXN * MAXN];

void dfs(int x, int y, int comp) {
    used[x][y] = true;
    id[x][y] = comp;
    sz[comp]++;
    for(int dir = 0; dir < 4; dir++) {
        int xx = x + gox[dir], yy = y + goy[dir];
        if(0 <= xx && xx < n && 0 <= yy && yy < n &&
           c[xx][yy] == '.' && !used[xx][yy])
            dfs(xx, yy, comp);
    }
}

void add(int x, int y) {
    if(c[x][y] == '.')
        return;
    cur++;
    for(size_t i = 0; i < g[id[x][y]].size(); i++) {
        int comp = g[id[x][y]][i];
        if(!cnt[comp])
            cur += sz[comp];
        cnt[comp]++;
    }
}

void del(int x, int y) {
    if(c[x][y] == '.')
        return;
    cur--;
    for(size_t i = 0; i < g[id[x][y]].size(); i++) {
        int comp = g[id[x][y]][i];
        cnt[comp]--;
        if(!cnt[comp])
            cur -= sz[comp];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(c[i][j] == 'X') {
                id[i][j] = freeid++;
                sz[id[i][j]] = 1;
            }
            else if(!used[i][j]) {
                dfs(i, j, freeid++);
                ans = max(ans, sz[id[i][j]]);
            }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(c[i][j] == 'X') {
                for(int dir = 0; dir < 4; dir++) {
                    int x = i + gox[dir], y = j + goy[dir];
                    if(0 <= x && x < n && 0 <= y && y < n && c[x][y] == '.')
                        g[id[i][j]].push_back(id[x][y]);
                }
            }
    for(int i = 0; i + k <= n; i++) {
        for(int ii = 0; ii < k; ii++)
            for(int jj = 0; jj < k; jj++)
                add(i + ii, jj);
        ans = max(ans, cur);
        for(int j = 0; j + k < n; j++) {
            for(int ii = 0; ii < k; ii++)
                del(i + ii, j);
            for(int ii = 0; ii < k; ii++)
                add(i + ii, j + k);
            ans = max(ans, cur);
        }
        for(int ii = 0; ii < k; ii++)
            for(int jj = 0; jj < k; jj++)
                del(i + ii, n - k + jj);
    }
    cout << ans << '\n';
    return 0;
}