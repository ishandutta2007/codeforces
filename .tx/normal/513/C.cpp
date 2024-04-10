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

int l[5];
int r[5];
int c[5];

ldouble d[11][11][11];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scii(l[i], r[i]);
        c[i] = r[i] - l[i] + 1;
    }

    ldouble ans = 0;

    for (int x = 1; x <= 10000; x++) {
        memset(d, 0, sizeof(ldouble) * 11 * 11 * 11);
        d[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int more = 0; more <= n; more++) {
                for (int eq = 0; eq <= n; eq++) {
                    if (x + 1 <= r[i]) {
                        d[i + 1][more + 1][eq] += d[i][more][eq] * (r[i] - max(x + 1, l[i]) + 1) / c[i];
                    }
                    if (l[i] <= x && x <= r[i]) {
                        d[i + 1][more][eq + 1] += d[i][more][eq] * 1.0 / c[i];
                    }
                    if (x - 1 >= l[i]) {
                        d[i + 1][more][eq] += d[i][more][eq] * (min(x - 1, r[i]) - l[i] + 1) / c[i];
                    }
                }
            }
        }
        ldouble p = 0;
        for (int eq = 1; eq < n; eq++) {
            p += d[n][1][eq];
        }
        for (int eq = 2; eq <= n; eq++) {
            p += d[n][0][eq];
        }
        ans += p * x;
    }

    cout.precision(11);
    cout << fixed << ans;

    return 0;
}