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

lint a[555][555];
int n;

lint srow(int i) {
    lint res = 0;
    for (int j = 0; j < n; j++) {
        res += a[i][j];
    }
    return res;
}

lint scol(int j) {
    lint res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i][j];
    }
    return res;
}

int main() {
    sci(n);
    if (n == 1) {
        cout << 31;
        return 0;
    }
    int i0 = -1, j0 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scid(x);
            a[i][j] = x;
            if (a[i][j] == 0) {
                i0 = i;
                j0 = j;
            }
        }
    }

    lint s = -1;
    for (int i = 0; s == -1; i++) {
        if (i == i0) {
            continue;
        }
        s = srow(i);
    }

    lint s0 = srow(i0);
    if (s0 >= s) {
        cout << -1;
        return 0;
    }

    a[i0][j0] = s - s0;

    bool ok = true;

    lint sd1 = 0, sd2 = 0;

    for (int i = 0; i < n; i++) {
        if (srow(i) != s || scol(i) != s) {
            ok = false;
        }
        sd1 += a[i][i];
        sd2 += a[n - 1 - i][i];
    }

    if (sd1 != s || sd2 != s) {
        ok = false;
    }

    if (!ok) {
        cout << -1;
    } else {
        cout << a[i0][j0];
    }



    return 0;
}