#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

struct Dsu {
    int *a;
    int *sz;

    Dsu(int n) {
        a = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;
            sz[i] = 1;
        }
    }

    int get(int x) {
        return a[x] == x ? x : a[x] = get(a[x]);
    }

    int getSz(int x) {
        return sz[get(x)];
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (rand() & 1) {
                a[x] = y;
                sz[y] += sz[x];
            } else {
                a[y] = x;
                sz[x] += sz[y];
            }
        }
    }
};

char a[1111][1111];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;

bool fit(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.';
}

void dfs(int vx, int vy, Dsu& dsu) {
    int vn = vx * m + vy;
    for (int i = 0; i < 4; i++) {
        int x = vx + dx[i];
        int y = vy + dy[i];
        if (!fit(x, y)) {
            continue;
        }
        int num = x * m + y;
        if (dsu.get(vn) != dsu.get(num)) {
            dsu.unite(vn, num);
            dfs(x, y, dsu);
        }
    }
}

int main() {
    srand(31);

    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    Dsu dsu(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                dfs(i, j, dsu);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                printf(".");
            } else {
                int ans = 1;
                for (int k = 0; k < 4; k++) {
                    int kx = i + dx[k];
                    int ky = j + dy[k];
                    if (!fit(kx, ky)) {
                        continue;
                    }
                    bool ok = true;
                    for (int z = 0; z < k; z++) {
                        int zx = i + dx[z];
                        int zy = j + dy[z];
                        if (!fit(zx, zy)) {
                            continue;
                        }
                        if (dsu.get(kx * m + ky) == dsu.get(zx * m + zy)) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        ans += dsu.getSz(kx * m + ky);
                    }
                }
                printf("%d", ans % 10);
            }
        }
        puts("");
    }


    return 0;
}