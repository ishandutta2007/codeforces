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

int a[111111];

int main() {
    scid(n);
    int x = 0;
    int cs = 0;
    while (n-- > 0) {
        scid(s);
        int i;
        for (i = 0; ; i++) {
            if (a[i] == 9 || cs >= s) {
                cs -= a[i];
                a[i] = 0;
                continue;
            }
            if (cs + 9 - a[i] + 9 * i >= s) {
                break;
            }
            cs -= a[i];
            a[i] = 0;
        }
        int t = max(1, s - cs - 9 * i);
        a[i] += t;
        cs += t;
        x = max(x, i);
        i = 0;
        while (cs < s) {
            t = min(s - cs, 9);
            a[i] = t;
            cs += t;
            i++;
        }
        for (i = x; i >= 0; i--) {
            cout << a[i];
        }
        cout << "\n";
    }

    return 0;
}