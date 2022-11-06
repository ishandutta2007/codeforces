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

int a[222222];
int x[222222];
int nx[222222];

int getNx(int x) {
    return nx[x] == x ? x : nx[x] = getNx(nx[x]);
}

int main() {
    scid(n);
    rea(a, n);
    for (int i = 0; i <= n; i++) {
        nx[i] = i;
    }
    scid(m);
    while (m-- > 0) {
        scid(t);
        if (t == 1) {
            sciid(p, v);
            --p;
            while ((p = getNx(p)) < n && v > 0) {
                int q = min(v, a[p] - x[p]);
                v -= q;
                x[p] += q;
                if (x[p] == a[p]) {
                    nx[p] = p + 1;
                }
            }
        } else {
            scid(p);
            cout << x[--p] << "\n";
        }
    }

    return 0;
}