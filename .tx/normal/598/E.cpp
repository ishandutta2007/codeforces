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

int d[33][33][55];

int main() {
    for (int i = 0; i < 33; i++) {
        for (int j = 0; j < 33; j++) {
            for (int k = 1; k < 55; k++) {
                d[i][j][k] = 1e9;
            }
        }
    }

    for (int n = 1; n <= 30; n++) {
        for (int m = 1; m <= 30; m++) {
            for (int k = 1; k <= min(n * m, 50); k++) {
                if (n * m == k) {
                    d[n][m][k] = 0;
                    continue;
                }
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j <= k; j++) {
                        d[n][m][k] = min(d[n][m][k], d[i][m][j] + d[n - i][m][k - j] + m * m);
                    }
                }
                for (int i = 1; i < m; i++) {
                    for (int j = 0; j <= k; j++) {
                        d[n][m][k] = min(d[n][m][k], d[n][i][j] + d[n][m - i][k - j] + n * n);
                    }
                }
            }
        }
    }

    scid(n);
    while (n-- > 0) {
        sciiid(a, b, c);
        cout << d[a][b][c] << "\n";
    }

    return 0;
}