#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

bool inside(int x, int l, int r) {
    return x >= l && x <= r;
}

int main() {
    sciid(n, m);
    sciid(s, f);
    --s;
    --f;
    char L = 'L';
    char R = 'R';
    bool nswap = false;
    if (s > f) {
        int ss = n - 1 - s;
        int ff = n - 1 - f;
        s = ss;
        f = ff;
        swap(L, R);
        nswap = true;
    }
    int ct = 1;
    for (; m-- > 0; ) {
        sciiid(t, l, r);
        l--;
        r--;
        if (nswap) {
            int ll = n - 1 - r;
            int rr = n - 1 - l;
            l = ll;
            r = rr;
        }
        while (s < f) {
            if (ct == t) {
                if (inside(s, l, r) || inside(s + 1, l, r)) {
                    printf("X");
                } else {
                    printf("%c", R);
                    s++;
                }
                ct++;
                break;
            }
            printf("%c", R);
            ct++;
            s++;
        }
    }
    while (s < f) {
        printf("%c", R);
        ct++;
        s++;
    }

    return 0;
}