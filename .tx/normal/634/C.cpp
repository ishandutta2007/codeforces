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

struct Fenv {
    lint* a;
    int* act;
    int n, mx;

    Fenv(int n, int mx) : n(n), mx(mx) {
        a = new lint[n];
        act = new int[n];
        memset(a, 0, sizeof(lint) * n);
        memset(act, 0, sizeof(int) * n);
    }

    void add(int i, int x) {
        int na = min(mx, act[i] + x);
        x = na - act[i];
        act[i] += x;
        for (; i < n; i |= (i + 1)) {
            a[i] += x;
        }
    }

    lint get(int r) {
        lint res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += a[r];
        }
        return res;
    }

    lint get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    sciid(n, k);
    sciid(a, b);
    scid(q);
    Fenv fa(n, a);
    Fenv fb(n, b);
    while (q-- > 0) {
        scid(t);
        if (t == 1) {
            sciid(d, x);
            --d;
            fa.add(d, x);
            fb.add(d, x);
        } else {
            scid(d);
            --d;
            cout << fb.get(d - 1) + fa.get(d + k, n - 1) << "\n";
        }
    }


    return 0;
}