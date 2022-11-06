#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int h[1111][1111];
int n, m;

int toI(int x, int y) {
    return x * m + y;
}

void toXY(int i, int &x, int &y) {
    x = i / m;
    y = i % m;
}

struct Dsu {
    int *a;
    int *mn;
    int *sz;

    Dsu() {
        a = new int[n * m];
        mn = new int[n * m];
        sz = new int[n * m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int id = toI(i, j);
                a[id] = id;
                mn[id] = h[i][j];
                sz[id] = 1;
            }
        }
    }

    int get(int x) {
        return a[x] == x ? x : a[x] = get(a[x]);
    }

    int getSz(int x) {
        return sz[get(x)];
    }

    int getMn(int x) {
        return mn[get(x)];
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        if (rand() & 1) {
            a[x] = y;
            sz[y] += sz[x];
            mn[y] = min(mn[y], mn[x]);
        } else {
            a[y] = x;
            sz[x] += sz[y];
            mn[x] = min(mn[y], mn[x]);
        }
    }
};

struct Cell {
    int v, x, y;

    bool operator<(const Cell &r) const {
        return v > r.v;
    }
};

Cell cs[1111111];

bool used[1111][1111];

int ans[1111][1111];

int main() {
    init_cin
    cin >> n >> m;
    lint k;
    cin >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
            cs[toI(i, j)] = Cell{h[i][j], i, j};
        }
    }

    Dsu dsu;

    int nm = n * m;
    sort(cs, cs + nm);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int ai = -1;
    int ax = -1;
    int ay = -1;

    for (int i = 0; i < nm; i++) {
        Cell c = cs[i];
        int vx = c.x;
        int vy = c.y;
        int vv = c.v;

        for (int t = 0; t < 4; t++) {
            int x = vx + dx[t];
            int y = vy + dy[t];
            if (x < 0 || x >= n || y < 0 || y >= m || h[x][y] < vv) {
                continue;
            }
            dsu.unite(toI(vx, vy), toI(x, y));
        }

        int cm = dsu.getMn(toI(vx, vy));
        int cs = dsu.getSz(toI(vx, vy));
        lint mxs = 1LL * cs * cm;

        if (mxs < k || k % cm != 0) {
            continue;
        }

        ai = toI(vx, vy);
        ax = vx;
        ay = vy;
        break;
    }

    if (ai == -1) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";

    queue<int> q;
    q.push(ax);
    q.push(ay);
    used[ax][ay] = true;
    int mn = h[ax][ay];
    ans[ax][ay] = mn;
    k -= mn;

    while (!q.empty() && k > 0) {
        int vx = q.front(); q.pop();
        int vy = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int x = vx + dx[i];
            int y = vy + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || used[x][y] || h[x][y] < mn || k == 0) {
                continue;
            }
            ans[x][y] = mn;
            k -= mn;
            q.push(x);
            q.push(y);
            used[x][y] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}