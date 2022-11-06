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

int main() {
    sciid(n, m);
    sciid(tmn, tmx);
    int mn = 1e9, mx = -1e9;
    for (int i = 0; i < m; i++) {
        scid(x);
        mn = min(mn, x);
        mx = max(mx, x);
    }
    if (mn < tmn || mx > tmx) {
        cout << "Incorrect";
        return 0;
    }
    int nd = 2;
    if (mn == tmn) {
        nd--;
    }
    if (mx == tmx) {
        nd--;
    }
    if (nd <= n - m) {
        cout << "Correct";
    } else {
        cout << "Incorrect";
    }

    return 0;
}