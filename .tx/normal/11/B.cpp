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
    scid(x);
    x = abs(x);
    int c = 0;
    int i = 0;
    while (c + i + 1 <= x) {
        c += i + 1;
        i++;
    }
    if (c == x) {
        cout << i;
        return 0;
    }
    c += i + 1;
    int d = c - x;
    if (d % 2 == 0) {
        cout << i + 1;
        return 0;
    }
    if (i % 2 == 1) {
        cout << i + 2;
        return 0;
    }
    cout << i + 3;
    return 0;

    return 0;
}