#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

char a[1111][1111];
int d[1111][1111];

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    int ex, ey, sx, sy;
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'E') {
                ex = i;
                ey = j;
            } else if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = 1e9;
        }
    }
    d[ex][ey] = 0;
    queue<int> q;
    q.push(ex);
    q.push(ey);
    while (!q.empty()) {
        int vx = q.front();
        q.pop();
        int vy = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = vx + dx[i];
            int y = vy + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 'T') {
                continue;
            }
            if (d[x][y] > d[vx][vy] + 1) {
                d[x][y] = d[vx][vy] + 1;
                q.push(x);
                q.push(y);
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cerr << (d[i][j] == 1e9 ? 0 : d[i][j]) << " ";
//        }
//        cerr << endl;
//    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= '0' && a[i][j] <= '9' && d[i][j] <= d[sx][sy]) {
                ans += a[i][j] - '0';
            }
        }
    }
    cout << ans;

    return 0;
}