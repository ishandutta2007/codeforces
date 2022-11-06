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
typedef long double ldouble;

using namespace std;

bool a[11][11];

int main() {
    sciiid(r, c, n);
    scid(k);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[--x][--y] = true;
    }
    int ans = 0;
    for (int x1 = 0; x1 < r; x1++) {
        for (int y1 = 0; y1 < c; y1++) {
            for (int x2 = x1; x2 < r; x2++) {
                for (int y2 = y1; y2 < c; y2++) {
                    int x = 0;
                    for (int i = x1; i <= x2; i++) {
                        for (int j = y1; j <= y2; j++) {
                            if (a[i][j]) {
                                x++;
                            }
                        }
                    }
                    if (x >= k) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;


    return 0;
}