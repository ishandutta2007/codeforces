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

bool used[55][55][4][2];
bool jused[55][55];

char a[55][55];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 'B';
}

void dfs(int vx, int vy, int d, int t) {
    used[vx][vy][d][t] = true;
    jused[vx][vy] = true;
    int x = vx + dx[d];
    int y = vy + dy[d];
    if (ok(x, y) && !used[x][y][d][t]) {
        dfs(x, y, d, t);
    }
    if (t == 1) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (i == d) {
            continue;
        }
        if (used[vx][vy][i][1]) {
            continue;
        }
        dfs(vx, vy, i, 1);
    }
}

int main() {
    scii(n, m);
    for (int i = 0; i < n; i++) {
        scanf("\n%s", a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B') {
                memset(used, 0, sizeof(bool) * 55 * 55 * 4 * 2);
                memset(jused, 0, sizeof(bool) * 55 * 55);
                for (int k = 0; k < 4; k++) {
                    dfs(i, j, k, 0);
                }
                for (int ci = 0; ci < n; ci++) {
                    for (int cj = 0; cj < m; cj++) {
                        if (a[ci][cj] == 'B' && !jused[ci][cj]) {
                            cout << "NO";
                            return 0;
                        }
                    }
                }
            };
        }
    }
    cout << "YES";

    return 0;
}