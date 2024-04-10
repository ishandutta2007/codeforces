#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2005;
char c[MAXN][MAXN];
int cnt[MAXN][MAXN], gox[] = {-1, 0, 1, 0}, goy[] = {0, -1, 0, 1};
queue< pair<int, int> > q;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(c[i][j] == '.') {
                for(int k = 0; k < 4; k++) {
                    int x = i + gox[k], y = j + goy[k];
                    if(0 <= x && x < n && 0 <= y && y < m && c[x][y] == '.')
                        cnt[i][j]++;
                }
                if(cnt[i][j] == 1)
                    q.push(make_pair(i, j));
            }
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = x + gox[i], yy = y + goy[i];
            if(0 <= xx && xx < n && 0 <= yy && yy < m && c[xx][yy] == '.') {
                cnt[x][y]--;
                cnt[xx][yy]--;
                if(xx == x) {
                    c[x][min(y, yy)] = '<';
                    c[x][max(y, yy)] = '>';
                }
                else {
                    c[min(x, xx)][y] = '^';
                    c[max(x, xx)][y] = 'v';
                }
                for(int j = 0; j < 4; j++) {
                    int tox = xx + gox[j], toy = yy + goy[j];
                    if(0 <= tox && tox < n && 0 <= toy && toy < m && c[tox][toy] == '.') {
                        cnt[tox][toy]--;
                        if(cnt[tox][toy] == 1)
                            q.push(make_pair(tox, toy));
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(c[i][j] == '.') {
                cout << "Not unique\n";
                return 0;
            }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << c[i][j];
        cout << '\n';
    }
    return 0;
}