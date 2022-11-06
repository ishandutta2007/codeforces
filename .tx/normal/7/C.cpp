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

lint gcd(lint a, lint b, lint& x, lint& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lint x1, y1;
    lint g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

int main() {
    init_cin
    lint a, b, c;
    cin >> a >> b >> c;
    c = -c;

    lint x, y, g;
    g = gcd(a, b, x, y);

    if (c % g != 0) {
        cout << -1;
        return 0;
    }

    c /= g;
    cout << x * c << " " << y * c;

    return 0;
}