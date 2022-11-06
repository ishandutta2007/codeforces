#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

bool u[3][111];
char a[3][111];

int main() {
    scid(t);
    while (t-- > 0) {
        memset(u, false, sizeof(bool) * 3 * 111);
        memset(a, '.', sizeof(char) * 3 * 111);
        queue<int> q;
        sciid(n, k);
        scanf("\n");
        int sx = -1, sy = -1;
        for (int i = 0; i < 3; i++) {
            scanf("%s", a[i]);
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 's') {
                    sx = i;
                    sy = j;
                }
            }
            for (int j = n; j < 111; j++) {
                a[i][j] = '.';
            }
        }
        q.push(sx);
        q.push(sy);
        u[sx][sy] = true;
        if (n % 3 != 1) {
            n += n % 3 / 2 + 1;
        }

        while (!q.empty()) {
            int vx = q.front();
            q.pop();
            int vy = q.front();
            q.pop();
            if (vy >= n) {
                continue;
            }
            if (a[vx][vy + 1] != '.') {
                continue;
            }
            if (!u[vx][vy + 3] && a[vx][vy + 3] == '.' && a[vx][vy + 2] == '.') {
                u[vx][vy + 3] = true;
                q.push(vx);
                q.push(vy + 3);
            }
            if (vx < 2 && !u[vx + 1][vy + 3] && a[vx + 1][vy + 1] == '.' && a[vx + 1][vy + 2] == '.' && a[vx + 1][vy + 3] == '.') {
                u[vx + 1][vy + 3] = true;
                q.push(vx + 1);
                q.push(vy + 3);
            }
            if (vx > 0 && !u[vx - 1][vy + 3] && a[vx - 1][vy + 1] == '.' && a[vx - 1][vy + 2] == '.' && a[vx - 1][vy + 3] == '.') {
                u[vx - 1][vy + 3] = true;
                q.push(vx - 1);
                q.push(vy + 3);
            }
        }
        if (u[0][n - 1] || u[1][n - 1] || u[2][n - 1]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}