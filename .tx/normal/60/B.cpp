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

bool used[11][11][11];

int dx[6] {1, -1, 0, 0, 0, 0};
int dy[6] {0, 0, 1, -1, 0, 0};
int dz[6] {0, 0, 0, 0, 1, -1};

char a[11][11][11];

int n, m, k;

int ans = 0;

void dfs(int vx, int vy, int vz) {
    used[vx][vy][vz] = true;
    ans++;
    for (int i = 0; i < 6; i++) {
        int x = vx + dx[i];
        int y = vy + dy[i];
        int z = vz + dz[i];
        if (x < 0 || y < 0 || z < 0) {
            continue;
        }
        if (x >= n || y >= m || z >= k) {
            continue;
        }
        if (a[x][y][z] == '#' || used[x][y][z]) {
            continue;
        }

        dfs(x, y, z);
    }
}

int main() {
    scanf("%d %d %d\n", &k, &n, &m);
    for (int i = 0; i < k; i++) {
        scanf("\n");
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < m; t++) {
                scanf("%c", &a[j][t][i]);
            }
            scanf("\n");
        }
    }

//    for (int i = 0; i < k; i++) {
//        for (int j = 0; j < n; j++) {
//            for (int t = 0; t < m; t++) {
//                cout << a[j][t][i];
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//    }

    sciid(x, y);
    dfs(--x, --y, 0);

    cout << ans;

    return 0;
}