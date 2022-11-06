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

int a[4444];
int last[1111111];
int tt[1111111];

int main() {
    scid(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        ans = max(ans, ++last[a[i]]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            last[a[j]] = 0;
            tt[a[j]] = 0;
        }
        int x = a[i];
        int tm = 1;
        int cm = 0;
        for (int j = i + 1; j < n; j++) {
            int y = a[j];
            if (x == y) {
                tm++;
                ans = max(ans, cm + 1);
            } else if (tt[y] != tm) {
                tt[y] = tm;
                last[y]++;
                cm = max(cm, 2 * last[y]);
                ans = max(ans, cm);
            }
        }
    }
    cout << ans;

    return 0;
}