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

int d[1111][1111][15][2];

char s[1111];
char t[1111];

int main() {
    sciiid(n, m, k);
    scanf("\n%s", s);
    scanf("\n%s", t);

    memset(d, -1, sizeof(int) * 1111 * 1111 * 15 * 2);
    d[0][0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int v = 0; v <= k; v++) {
                d[i + 1][j][v][0] = max(d[i + 1][j][v][0], d[i][j][v][0]);
                d[i + 1][j][v][0] = max(d[i + 1][j][v][0], d[i][j][v][1]);

                d[i][j + 1][v][0] = max(d[i][j + 1][v][0], d[i][j][v][0]);
                d[i][j + 1][v][0] = max(d[i][j + 1][v][0], d[i][j][v][1]);

                if (s[i] == t[j]) {
                    if (d[i][j][v][1] != -1) {
                        d[i + 1][j + 1][v][1] = max(d[i + 1][j + 1][v][1], d[i][j][v][1] + 1);
                        d[i + 1][j + 1][v + 1][1] = max(d[i + 1][j + 1][v + 1][1], d[i][j][v][1] + 1);
                    }
                    if (d[i][j][v][0] != -1) {
                        d[i + 1][j + 1][v + 1][1] = max(d[i + 1][j + 1][v + 1][1], d[i][j][v][0] + 1);
                    }
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            ans = max(ans, d[i][j][k][0]);
            ans = max(ans, d[i][j][k][1]);
        }
    }

    cout << ans;

    return 0;
}