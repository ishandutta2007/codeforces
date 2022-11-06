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

int a[111];
int x[111];
int y[111];

int d;

int dist(int i, int j) {
    return d * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
}

int main() {
    scid(n);
    sci(d);
    for (int i = 1; i <= n - 2; i++) {
        sci(a[i]);
    }

    for (int i = 0; i < n; i++) {
        sci(x[i]);
        sci(y[i]);
    }

    lint l = 0, r = 1e18;
    const lint inf = 1e18;
    while (l + 1 < r) {
        vector<lint> b(n, -inf);
        vector<bool> used(n);
        lint m = (l + r) >> 1;
        b[0] = m;
        for (int i = 0; i < n; i++) {
            int mx = -1;
            for (int j = 0; j < n; j++) {
                if (!used[j] && (mx == -1 || b[j] > b[mx])) {
                    mx = j;
                }
            }
            if (b[mx] == -inf) {
                break;
            }
            used[mx] = true;
            lint ct = b[mx];
            for (int j = 0; j < n; j++) {
                if (!used[j] && dist(mx, j) <= ct) {
                    lint nt = ct - dist(mx, j) + a[j];
                    if (nt > b[j]) {
                        b[j] = nt;
                    }
                }
            }
        }
        if (b[n - 1] == -inf) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << r;



    return 0;
}