#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(int x, int y): x(x), y(y) {}

    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

struct State {
    Point pos;
    int mask;

    State() {}

    State(Point pos, int mask): pos(pos), mask(mask) {}
};

const Point P(57, 58);
const int MAXN = 25, MAXT = 10, MASKS = 300, INF = 1000 * 1000 * 1000 + 5;
char a[MAXN][MAXN];
int c[MAXT], d[MAXN][MAXN][MASKS],
    gox[] = {-1, 0, 1, 0}, goy[] = {0, -1, 0, 1}, n, m, t, tb;
Point ob[MAXT];
queue<State> q;

int cp(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

int sgn(int k) {
    return k > 0? 1 : (k < 0? -1 : 0);
}

bool intersect(Point a1, Point b1, Point a2, Point b2) {
    return sgn(cp(b1 - a1, a2 - a1)) * sgn(cp(b1 - a1, b2 - a1)) < 0 &&
        sgn(cp(b2 - a2, a1 - a2)) * sgn(cp(b2 - a2, b1 - a2)) < 0;
}

void bfs(Point s) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < (1 << tb); k++)
                d[i][j][k] = INF;
    d[s.x][s.y][0] = 0;
    q.push(State(s, 0));
    while(!q.empty()) {
        State st = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            Point p = Point(st.pos.x + gox[dir], st.pos.y + goy[dir]);
            if(p.x < 0 || p.x >= n || p.y < 0 || p.y >= m || a[p.x][p.y] != '.')
                continue;
            int m = st.mask;
            for(int i = 0; i < tb; i++)
                if(intersect(ob[i], ob[i] + P, st.pos, p))
                    m ^= 1 << i;
            if(d[p.x][p.y][m] != INF)
                continue;
            d[p.x][p.y][m] = d[st.pos.x][st.pos.y][st.mask] + 1;
            q.push(State(p, m));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    Point s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] > '0' && a[i][j] < '9') {
                ob[a[i][j] - '1'] = Point(i, j);
                t++;
            }
            else if(a[i][j] == 'S') {
                s = Point(i, j);
                a[i][j] = '.';
            }
        }
    tb = t;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 'B') {
                ob[tb] = Point(i, j);
                tb++;
            }
    for(int i = 0; i < t; i++)
        cin >> c[i];
    bfs(s);
    int ans = 0;
    for(int i = 0; i < (1 << tb); i++) {
        bool bomb = false;
        int tr = 0;
        for(int j = 0; j < tb; j++)
            if(i & (1 << j)) {
                if(j < t)
                    tr += c[j];
                else {
                    bomb = true;
                    break;
                }
            }
        if(bomb)
            continue;
        ans = max(ans, tr - d[s.x][s.y][i]);
    }
    cout << ans << '\n';
    return 0;
}