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

int u[4444][4444];
int u2[4444][4444];
int d[888][4444];

int n, k;

void calc(int ki, int f, int t, int cf, int ct) {
    int x = (f + t) >> 1;

    int bc = 1e9;
    int bi = -1;
    for (int i = cf; i <= min(x - 1, ct); i++) {
        int v = d[ki - 1][i] + u2[i + 1][x];
        if (v < bc) {
            bc = v;
            bi = i;
        }
    }

    if (f < x) {
        calc(ki, f, x, cf, bi);
    }

    if (x + 1 < t) {
        calc(ki, x + 1, t, bi, ct);
    }


    d[ki][x] = bc;
}

int getD() {
    while (true) {
        char c = getchar();
        if (c >= '0' && c <= '9') {
            return c - '0';
        }
    }
}

int main() {
    scii(n, k);
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            u[i][j] = getchar() - '0';
            getchar();
            if (j) {
                u[i][j] += u[i][j - 1];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            u2[i][j] = u2[i][j - 1] + u[j][j] - (i == 0 ? 0 : u[j][i - 1]);
        }
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = 1e9;
        }
    }
    d[0][0] = 0;

    for (int i = 0; i < n; i++) {
        d[1][i] = u2[0][i];
    }

    for (int i = 2; i <= k; i++) {
        calc(i, 0, n, 0, n - 1);
    }

    cout << d[k][n - 1];


    return 0;
}