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

char a[33][33];

int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        scanf("\n%s", a[i]);
    }
    int ans = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = x1; x2 < n; x2++) {
                for (int y2 = y1; y2 < m; y2++) {
                    bool ok = true;
                    for (int i = x1; ok && i <= x2; i++) {
                        for (int j = y1; j <= y2; j++) {
                            if (a[i][j] == '1') {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) {
                        ans = max(ans, 2 * (x2 - x1 + 1) + 2 * (y2 - y1 + 1));
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}