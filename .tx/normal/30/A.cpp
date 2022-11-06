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

int main() {
    sciiid(a, b, n);
    if (b == 0) {
        cout << 0;
        return 0;
    }
    if (a == 0) {
        cout << "No solution";
        return 0;
    }
    if (b % a != 0) {
        cout << "No solution";
        return 0;
    }
    if (a * b < 0 && n % 2 == 0) {
        cout << "No solution";
    }

    int x = floor(powl(abs(b / a), (long double) 1 / n) + 0.5);
    if (b * a < 0) {
        x = -x;
    }
    int c = 1;
    for (int i = 0; i < n; i++) {
        c *= x;
    }
    if (a * c == b) {
        cout << x;
    } else {
        cout << "No solution";
    }


    return 0;
}