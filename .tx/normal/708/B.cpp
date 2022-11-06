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

void fail() {
    cout << "Impossible" << endl;
    exit(0);
}

int main() {
    lint a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;

    lint d00 = floor(sqrt((long double) 1.0 + 8 * a00));
    lint k0 = 1 + d00;
    if (d00 * d00 != 1 + 8 * a00 || k0 % 2 != 0) {
        fail();
    }
    k0 /= 2;

    lint d11 = floor(sqrt((long double) 1.0 + 8 * a11));
    lint k1 = 1 + d11;
    if (d11 * d11 != 1 + 8 * a11 || k1 % 2 != 0) {
        fail();
    }
    k1 /= 2;

    lint s = a00 + a01 + a10 + a11;
    lint n = k1 + k0;

    if (a00 == 0 && a10 == 0 && a01 == 0) {
        for (int i = 0; i < k1; i++) {
            cout << "1";
        }
        return 0;
    }

    if (a11 == 0 && a10 == 0 && a01 == 0) {
        for (int i = 0; i < k0; i++) {
            cout << "0";
        }
        return 0;
    }

    if (n * (n - 1) / 2 != s) {
        fail();
    }

    int x = 0;
    for (int i = 0; i < k0; i++) {
        lint t = min(a01, k1);
        a01 -= t;
        t = k1 - t;
        for (int j = 0; j < t; j++) {
            cout << "1";
            k1--;
        }
        cout << "0";
    }

    for (int i = 0; i < k1; i++) {
        cout << "1";
    }


    return 0;
}