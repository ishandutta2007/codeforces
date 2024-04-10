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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    scid(c);
    sciid(hr, hb);
    sciid(wr, wb);

    lint ans = 0;

    lint nok = 1LL * wr * wb / gcd(wr, wb);
    if (nok <= c) {
        lint xr = nok / wr;
        lint xb = nok / wb;
        ans += max(xr * hr, xb * hb) * ((c - nok) / nok);
        c = c % nok + nok;
    }

    if (wr < wb) {
        swap(wr, wb);
        swap(hr, hb);
    }

    lint a1 = 0;
    lint ar = -1, ab = -1;
    for (lint i = 0; i * wr <= c; i++) {
        lint t = i * hr + (c - i * wr) / wb * hb;
        if (t > a1) {
            a1 = t;
            ar = i;
            ab = (c - i * wr) / wb;
        }
    }

    cout << a1 + ans << "\n";
    cerr << ar << " " << ab << endl;
    return 0;
}