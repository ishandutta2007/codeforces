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

char a[55][55];
bool used[55][55];

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int cw(int x, int y) {
    used[x][y] = true;
    int res = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '.') {
            continue;
        }
        if (!used[nx][ny]) {
            res += cw(nx, ny);
        }
    }
    return res;
}

int dcw() {
    memset(used, 0, sizeof(bool) * 55 * 55);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                return cw(i, j);
            }
        }
    }
    return 0;
}

int main() {
    scii(n, m);
    for (int i = 0; i < n; i++) {
        scanf("\n%s", a[i]);
    }
    int oc = dcw();
    if (oc <= 2) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                continue;
            }
            a[i][j] = '.';
            int cc = dcw();
            if (cc + 1 != oc) {
                cout << 1;
                return 0;
            }
            a[i][j] = '#';
        }
    }
    cout << 2;

    return 0;
}