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

int cd(lint x, int d) {
    int res = 0;
    while (x % d == 0) {
        res++;
        x /= d;
    }
    return res;
}

int d3(int& a, int& b) {
    if (a % 3 == 0) {
        a = a / 3 * 2;
    } else {
        b = b / 3 * 2;
    }
}

int d2(int& a, int &b) {
    if (a % 2 == 0) {
        a /= 2;
    } else {
        b /= 2;
    }
}

int main() {
    sciid(a1, b1);
    sciid(a2, b2);
    lint x = 1LL * a1 * b1;
    lint y = 1LL * a2 * b2;
    int x2 = cd(x, 2);
    int y2 = cd(y, 2);
    int x3 = cd(x, 3);
    int y3 = cd(y, 3);
    int ans = 0;
    while (x3 > y3) {
        d3(a1, b1);
        x3--;
        x2++;
        ans++;
    }
    while (x3 < y3) {
        d3(a2, b2);
        y3--;
        y2++;
        ans++;
    }
    while (x2 > y2) {
        d2(a1, b1);
        x2--;
        ans++;
    }
    while (x2 < y2) {
        d2(a2, b2);
        y2--;
        ans++;
    }
    if (1LL * a1 * b1 != 1LL * a2 * b2) {
        cout << -1;
        return 0;
    }
    cout << ans << "\n";
    cout << a1 << " " << b1 << "\n";
    cout << a2 << " " << b2 << "\n";

    return 0;
}