#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 35, MAXM = 905;
int s[MAXN][MAXN], t[MAXN][MAXN], cnt[MAXM],
    gox[] = {-1, -1, -1, 0, 1, 1, 1, 0},
    goy[] = {-1, 0, 1, 1, 1, 0, -1, -1},
    x = -1, y = -1, n, m;
char used[MAXN][MAXN];
vector< pair<int, int> > ans;

int dist(int x0, int y0, int x1, int y1) {
    return abs(x1 - x0) + abs(y1 - y0);
}

void makeMove(int sx, int sy, int tx, int ty) {
    while(x != tx || y != ty) {
        int tox = -1, toy = -1;
        for(int i = 0; i < 8; i++) {
            int xx = x + gox[i], yy = y + goy[i];
            if(0 <= xx && xx < n && 0 <= yy && yy < m &&
               !used[xx][yy] && (xx != sx || yy != sy) &&
               (tox == -1 || dist(tx, ty, xx, yy) < dist(tx, ty, tox, toy))) {
                tox = xx;
                toy = yy;
            }
        }
        swap(s[x][y], s[tox][toy]);
        x = tox;
        y = toy;
        ans.push_back(make_pair(x, y));
    }
    swap(s[x][y], s[sx][sy]);
    x = sx;
    y = sy;
    ans.push_back(make_pair(x, y));
}

void makePath(int tx, int ty) {
    int sx = -1, sy = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if(!used[i][j] && (i != x || j != y) && s[i][j] == t[tx][ty]) {
                sx = i;
                sy = j;
                break;
            }
        if(sx != -1)
            break;
    }
    while(sx != tx || sy != ty) {
        int tox = -1, toy = -1;
        for(int i = 0; i < 8; i++) {
            int xx = sx + gox[i], yy = sy + goy[i];
            if(0 <= xx && xx < n && 0 <= yy && yy < m && !used[xx][yy] &&
               (tox == -1 || dist(tx, ty, xx, yy) < dist(tx, ty, tox, toy))) {
                tox = xx;
                toy = yy;
            }
        }
        makeMove(sx, sy, tox, toy);
        sx = tox;
        sy = toy;
    }
    used[tx][ty] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> s[i][j];
            cnt[s[i][j]]++;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> t[i][j];
            cnt[t[i][j]]--;
        }
    for(int i = 0; i < MAXM; i++)
        if(cnt[i]) {
            cout << -1 << '\n';
            return 0;
        }
    if(n == 1) {
        for(int i = 0; i < m; i++)
            for(int j = i + 2; j <= m; j++) {
                rotate(s[0] + i, s[0] + i + 1, s[0] + j);
                bool ok = true;
                for(int k = 0; k < m; k++)
                    if(s[0][k] != t[0][k]) {
                        ok = false;
                        break;
                    }
                if(ok) {
                    cout << j - i - 1 << '\n';
                    for(int k = i; k < j; k++)
                        cout << 1 << ' ' << k + 1 << '\n';
                    return 0;
                }
                rotate(s[0] + i, s[0] + j - 2, s[0] + j);
                ok = true;
                for(int k = 0; k < m; k++)
                    if(s[0][k] != t[0][k]) {
                        ok = false;
                        break;
                    }
                if(ok) {
                    cout << j - i - 1 << '\n';
                    for(int k = j - 1; k >= i; k--)
                        cout << 1 << ' ' << k + 1 << '\n';
                    return 0;
                }
                rotate(s[0] + i, s[0] + i + 1, s[0] + j);
            }
        cout << -1 << '\n';
        return 0;
    }
    if(m == 1) {
        swap(m, n);
        for(int i = 0; i < m; i++)
            s[0][i] = s[i][0];
        for(int i = 0; i < m; i++)
            t[0][i] = t[i][0];
        for(int i = 0; i < m; i++)
            for(int j = i + 2; j <= m; j++) {
                rotate(s[0] + i, s[0] + i + 1, s[0] + j);
                bool ok = true;
                for(int k = 0; k < m; k++)
                    if(s[0][k] != t[0][k]) {
                        ok = false;
                        break;
                    }
                if(ok) {
                    cout << j - i - 1 << '\n';
                    for(int k = i; k < j; k++)
                        cout << k + 1 << ' ' << 1 << '\n';
                    return 0;
                }
                rotate(s[0] + i, s[0] + j - 2, s[0] + j);
                ok = true;
                for(int k = 0; k < m; k++)
                    if(s[0][k] != t[0][k]) {
                        ok = false;
                        break;
                    }
                if(ok) {
                    cout << j - i - 1 << '\n';
                    for(int k = j - 1; k >= i; k--)
                        cout << k + 1 << ' ' << 1 << '\n';
                    return 0;
                }
                rotate(s[0] + i, s[0] + i + 1, s[0] + j);
            }
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if(s[i][j] == t[n - 1][m - 1]) {
                x = i;
                y = j;
                break;
            }
        if(x >= 0)
            break;
    }
    ans.push_back(make_pair(x, y));
    for(int i = 0; i < n - 2; i++)
        for(int j = 0; j < m; j++)
            makePath(i, j);
    for(int i = 0; i < m - 1; i++)
        for(int j = n - 2; j < n; j++)
            makePath(j, i);
    makePath(n - 2, m - 1);
    cout << (int)ans.size() - 1 << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    return 0;
}