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

lint d[111][111][111];
lint mnp[111][111];
lint mns[111][111];
int c[111];
lint p[111][111];
int n, m, k;

void calc_mn(int i) {
    for (int g = 0; g <= n; g++) {
        for (int j = 0; j < m; j++) {
            mnp[g][j] = d[i][j][g];
            mns[g][m - 1 - j] = d[i][m - 1 - j][g];
            if (j) {
                mnp[g][j] = min(mnp[g][j], mnp[g][j - 1]);
                mns[g][m - 1 - j] = min(mns[g][m - 1 - j], mns[g][m - j]);
            }
        }
    }
}

lint get_mn(int j, int g) {
    lint res = 1e18;
    if (j) {
        res = min(res, mnp[g][j - 1]);
    }
    if (j + 1 < m) {
        res = min(res, mns[g][j + 1]);
    }
    return res;
}

int main() {
    sciii(n, m, k);
    for (int i = 0; i < n; i++) {
        sci(c[i]);
        --c[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scid(x);
            p[i][j] = x;
            if (c[i] == j) {
                p[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 111; i++) {
        for (int j = 0; j < 111; j++) {
            for (int g = 0; g < 111; g++) {
                d[i][j][g] = 1e18;
            }
        }
    }

    if (c[0] == -1) {
        for (int i = 0; i < m; i++) {
            d[0][i][1] = p[0][i];
        }
    } else {
        d[0][c[0]][1] = 0;
    }

    calc_mn(0);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i] != -1 && c[i] != j) {
                continue;
            }
            for (int g = 1; g <= n; g++) {
                d[i][j][g] = min(d[i][j][g], get_mn(j, g - 1) + p[i][j]);
                d[i][j][g] = min(d[i][j][g], d[i - 1][j][g] + p[i][j]);
            }
        }
        calc_mn(i);
    }

    lint ans = 1e18;
    for (int i = 0; i < m; i++) {
        ans = min(ans, d[n - 1][i][k]);
    }

    if (ans == 1e18) {
        cout << -1;
    } else {
        cout << ans;
    }



    return 0;
}