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

char a[1111][1111];
int was[1111][1111];
int qAns[111111];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int vx, int vy, int q) {
    was[vx][vy] = q;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int x = vx + dx[i];
        int y = vy + dy[i];
        if (a[x][y] == '*') {
            res++;
        } else if (was[x][y] == 0) {
            res += dfs(x, y, q);
        }
    }
    return res;
}

int main() {
    int n, m, k;
    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 1; i <= k; i++) {
        sciid(x, y);
        --x; --y;
        if (was[x][y] != 0) {
            cout << qAns[was[x][y]] << "\n";
            continue;
        }
        cout << (qAns[i] = dfs(x, y, i)) << "\n";
    }

    return 0;
}