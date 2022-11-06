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

lint m;

lint cw(lint n) {
    lint res = 0;
    for (lint k = 2; ; k++) {
        lint k3 = k * k * k;
        res += n / k3;
        if (n < k3 || res > m) {
            break;
        }
    }
    return res;
}

int main() {
    cin >> m;
    lint l = 0, r = 1e18;
    while (l + 1 < r) {
        lint md = (l + r) >> 1;
        if (cw(md) < m) {
            l = md;
        } else {
            r = md;
        }
    }

    if (cw(r) == m) {
        cout << r;
    } else {
        cout << -1;
    }

    return 0;
}