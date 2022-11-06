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

int a[111][111];

int main() {
    scid(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        sciiid(x, y, z);
        a[--x][--y] = z;
        s += z;
    }
    int ans = 0;
    int c = 0, p = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((a[c][j] != 0 || a[j][c] != 0) && j != p) {
                ans += max(-a[c][j], a[j][c]);
                p = c;
                c = j;
                break;
            }
        }
    }

    cout << min(ans, s - ans);


    return 0;
}