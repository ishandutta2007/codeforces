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

int n, m, x, y, a, b;

int go(int i, int j) {
    if (i == x && j == y) {
        return 0;
    }
    if (x + a > n && x - a <= 0) {
        return 1e9;
    }
    if (y + b > m && y - b <= 0) {
        return 1e9;
    }
    if (abs(x - i) % a != 0 || abs(y - j) % b != 0) {
        return 1e9;
    }
    if (abs(x - i) / a % 2 != abs(y - j) / b % 2) {
        return 1e9;
    }
    return max(abs(x - i) / a, abs(y - j) / b);
}

int main() {
    scii(n, m);
    scii(x, y);
    scii(a, b);
    int ans = 1e9;
    ans = min(ans, go(1, 1));
    ans = min(ans, go(1, m));
    ans = min(ans, go(n, m));
    ans = min(ans, go(n, 1));
    if (ans == 1e9) {
        cout << "Poor Inna and pony!";
    } else {
        cout << ans;
    }

    return 0;
}