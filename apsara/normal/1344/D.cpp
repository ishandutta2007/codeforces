#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 100100;
LL oo;
const double eps = 1e-6;
// f(x) = x(y - x^2) = -x^3 + xy; f'(x) = -3x^2 + y
// f(x) - f(x-1) = -(x^3-x^3+3x^2-3x+1)+y >= z
// -(3x^2-3x+1)+y-z=0 -> 3x^2-3x+1-y+z=0;
// b^2-4ac = 9-(12-12y+12z) = 12(y-z)-3;
// x=(3+sqrt(12(y-z)-3))/6

LL del(int x, int y) {
    return y - (3 * (LL) x * x - 3 * (LL) x + 1);
}

int solve(int y, LL z) {
    if ((y - z) < 0) return 0;
    double res = (3.0 + pow(12.0 * (y - z) - 3.0, 0.5)) / 6.0;
    int tmp = min((LL) y, (LL) floor(res));
    tmp = max(0, tmp - 2);
    while (tmp < y && del(tmp + 1, y) >= z) ++tmp;
    return tmp;
}

int solve2(int y, LL z) {
    int lo = 1, up = y;
    while (lo < up) {
        int mid = (lo + up + 1) / 2;
        if (del(mid, y) >= z) lo = mid;
        else up = mid - 1;
    }
    if (lo == 1 && del(1, y) < z) lo--;
    return lo;
}

int n, a[V], b[V], ans[V];

LL cal(LL mid) {
    LL has = 0;
    for (int i = 0; i < n; ++i) {
        LL tmp = solve(a[i], mid);
        tmp = min(tmp, (LL) a[i]);
        tmp = max(tmp, 0LL);
        ans[i] = tmp;
        has += tmp;
    }
    return has;
}

LL m;
int main() {
    while (~scanf("%d%I64d", &n, &m)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        LL oo = 0;
        for (int i = 0; i < n; ++i) {
            oo = max(del(1, a[i]), oo);
            oo = max(-del(a[i], a[i]), oo);
        }
        LL lo = -oo - 1, up = oo + 1;
        while (lo < up) {
            LL mid = lo + (up - lo + 1) / 2;
            LL has = cal(mid);
            //printf("%I64d %I64d %I64d %I64d\n", lo, up, mid, has);
            if (has >= m) lo = mid;
            else up = mid - 1;
        }
        LL T = cal(lo);
        //printf("T %I64d %I64d %I64d\n", lo, up, T);
        //if (m == 20071483408634LL) printf("%I64d %I64d\n", cal(lo), cal(lo + 1));
        LL cur = 0;
        for (int i = 0; i < n; ++i) cur += ans[i];
        for (int i = 0; i < n; ++i) {
            if (cur > m && ans[i] > 0 && del(ans[i], a[i]) == lo) {
                ans[i]--;
                cur--;
            }
        }
        for (int i = 0; i < n; ++i) printf("%d ", ans[i]); puts("");
        //LL F = 0; for (int i = 0; i < n; ++i) F += f(ans[i], a[i]); printf("%I64d\n", F);
    }
    return 0;
}

/*
10 32
1 2 3 4 5 5 5 5 5 5
5 8
4 4 8 2 1
5 353
191 148 145 73 150
*/