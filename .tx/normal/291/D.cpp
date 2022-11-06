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

int a[11111];
int ta[11111];
int ti[11111];

int main() {
    sciid(n, k);
    for (int i = 0; i < n - 1; i++) {
        a[i] = 1;
    }

    while (k-- > 0) {
        for (int i = 0; i < n; i++) {
            ti[i] = i;
            if (2 * a[i] > n - 1 - i) {
                int ll = n - 1 - i - a[i];
                ti[i] = n - 1 - ll;
            }
            ta[i] = a[ti[i]];
        }
        for (int i = 0; i < n; i++) {
            cout << ti[i] + 1 << " ";
            a[i] += ta[i];
        }
        cout << "\n";
    }

    return 0;
}