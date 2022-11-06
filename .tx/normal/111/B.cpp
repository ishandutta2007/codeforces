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

int last[111111];

int main() {
    scid(n);
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        int res = 0;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                if (last[j] < i - y) {
                    res++;
                }
                if (j * j != x && last[x / j] < i - y) {
                    res++;
                }
                last[j] = last[x / j] = i;
            }
        }
        cout << res << "\n";
    }

    return 0;
}