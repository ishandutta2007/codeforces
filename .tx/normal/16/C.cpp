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

lint gcd(lint a, lint b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    init_cin
    lint a, b, x, y;
    cin >> a >> b >> x >> y;
    lint g = gcd(x, y);
    x /= g;
    y /= g;
    lint l = 0, r = 2.5e9;
    while (l + 1 < r) {
        lint m = (l + r) >> 1;
        if (m * x <= a && m * y <= b) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l * x << " " << l * y;

    return 0;
}