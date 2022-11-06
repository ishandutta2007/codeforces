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
#include <time.h>
#include <ctime>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

char a[1501][1501];
int used[1500][1500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

int fn(int fx, int fy) {
    return min(2, abs(fx) + abs(fy));
}

const int K = 10000;

void dfs(int vx, int vy) {
    int tx = (vx % n + n) % n;
    int ty = (vy % m + m) % m;
    used[tx][ty] = vx * K + vy;
    for (int i = 0; i < 4; i++) {
        int x = vx + dx[i];
        int y = vy + dy[i];
        int xx = (x % n + n) % n;
        int yy = (y % m + m) % m;
        if (a[xx][yy] == '#') {
            continue;
        }
        if (used[xx][yy] == -1) {
            dfs(x, y);
        } else if (used[xx][yy] != x * K + y) {
            puts("Yes");
            exit(0);
        }
    }
}

int main() {
    scii(n, m);
    int sx, sy;
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    memset(used, -1, sizeof(int) * 1500 * 1500);
    dfs(sx, sy);
    puts("No");
    return 0;
}