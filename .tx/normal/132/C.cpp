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

bool d[111][222][55][2];
char s[111];

int main() {
    scanf("%s", s);
    scid(k);
    int n = strlen(s);
    d[0][111][0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 221; j++) {
            for (int v = 0; v <= k; v++) {
                for (int x = 0; x < 2; x++) {
                    int prev = j + x * 2 - 1;
                    if (s[i - 1] == 'F') {
                        d[i][j][v][x] |= d[i - 1][prev][v][x];
                        if (v > 0) {
                            d[i][j][v][x] |= d[i - 1][j][v - 1][1 - x];
                        }
                    } else {
                        d[i][j][v][x] |= d[i - 1][j][v][1 - x];
                        if (v > 0) {
                            d[i][j][v][x] |= d[i - 1][prev][v - 1][x];
                        }
                    }
                }
            }
        }
    }

    int ans = 0;

    for (int j = 0; j < 222; j++) {
        for (int v = k; v >= 0; v -= 2) {
            if (d[n][j][v][0] || d[n][j][v][1]) {
                ans = max(ans, abs(j - 111));
            }
        }
    }

    cout << ans;

    return 0;
}