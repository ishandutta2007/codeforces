#include <iostream>
#include <map>

using namespace std;

const int MAXN = 2005;
char used[MAXN][MAXN], col[MAXN][MAXN];
int x[MAXN], y[MAXN],
    gox[] = {-1, 0, 1, 0}, goy[] = {0, -1, 0, 1}, xs, ys;
long long cnt[MAXN][MAXN];
map<int, int> mpx, mpy;

void dfs(int x, int y) {
    used[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int xx = x + gox[i], yy = y + goy[i];
        if(xx < 0 || xx >= xs || yy < 0 || yy >= ys ||
           used[xx][yy] || col[xx][yy])
            continue;
        dfs(xx, yy);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char d;
        int len;
        cin >> d >> len;
        if(d == 'L') {
            x[i + 1] = x[i] - len;
            y[i + 1] = y[i];
            mpx[x[i + 1]];
            mpx[x[i] + 1];
            mpy[y[i + 1]];
            mpy[y[i] + 1];
        }
        else if(d == 'R') {
            x[i + 1] = x[i] + len;
            y[i + 1] = y[i];
            mpx[x[i]];
            mpx[x[i + 1] + 1];
            mpy[y[i]];
            mpy[y[i + 1] + 1];
        }
        else if(d == 'U') {
            x[i + 1] = x[i];
            y[i + 1] = y[i] + len;
            mpx[x[i]];
            mpx[x[i + 1] + 1];
            mpy[y[i]];
            mpy[y[i + 1] + 1];
        }
        else {
            x[i + 1] = x[i];
            y[i + 1] = y[i] - len;
            mpx[x[i + 1]];
            mpx[x[i] + 1];
            mpy[y[i + 1]];
            mpy[y[i] + 1];
        }
    }
    for(map<int, int>::iterator it = mpx.begin();;) {
        it->second = xs;
        map<int, int>::iterator nxt = it;
        nxt++;
        if(nxt == mpx.end()) {
            xs++;
            break;
        }
        for(size_t i = 0; i < mpy.size(); i++)
            cnt[xs][i] = nxt->first - it->first;
        it = nxt;
        xs++;
    }
    for(map<int, int>::iterator it = mpy.begin();;) {
        it->second = ys;
        map<int, int>::iterator nxt = it;
        nxt++;
        if(nxt == mpy.end()) {
            ys++;
            break;
        }
        for(size_t i = 0; i < mpx.size(); i++)
            cnt[i][ys] *= nxt->first - it->first;
        it = nxt;
        ys++;
    }
    for(int i = 0; i <= n; i++) {
        map<int, int>::iterator it = mpx.upper_bound(x[i]);
        it--;
        x[i] = it->second;
        it = mpy.upper_bound(y[i]);
        it--;
        y[i] = it->second;
    }
    for(int i = 0; i < n; i++) {
        if(x[i] == x[i + 1]) {
            int yy = y[i], dy = y[i] < y[i + 1]? 1 : -1;
            while(yy != y[i + 1]) {
                col[x[i]][yy] = true;
                yy += dy;
            }
            col[x[i]][yy] = true;
        }
        else {
            int xx = x[i], dx = x[i] < x[i + 1]? 1 : -1;
            while(xx != x[i + 1]) {
                col[xx][y[i]] = true;
                xx += dx;
            }
            col[xx][y[i]] = true;
        }
    }
    for(int i = 0; i < xs; i++) {
        if(!used[i][0] && !col[i][0])
            dfs(i, 0);
        if(!used[i][ys - 1] && !col[i][ys - 1])
            dfs(i, ys - 1);
    }
    for(int i = 0; i < ys; i++) {
        if(!used[0][i] && !col[0][i])
            dfs(0, i);
        if(!used[xs - 1][i] && !col[xs - 1][i])
            dfs(xs - 1, i);
    }
    long long ans = 0;
    for(int i = 0; i < xs; i++)
        for(int j = 0; j < ys; j++)
            if(!used[i][j])
                ans += cnt[i][j];
    cout << ans << '\n';
    return 0;
}