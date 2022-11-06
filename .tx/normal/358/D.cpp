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

int d[3333][2];
int a[3333];
int b[3333];
int c[3333];

int get(int i, int t) {
    if (i == 0) {
        if (t == 0) {
            return a[i];
        }
        return b[i];
    }
    if (d[i][t] != -1) {
        return d[i][t];
    }
    if (t == 0) {
        d[i][t] = max(get(i - 1, 0) + b[i], get(i - 1, 1) + a[i]);
    } else {
        d[i][t] = max(get(i - 1, 0) + c[i], get(i - 1, 1) + b[i]);
    }
    return d[i][t];
}

int main() {
    scid(n);
    rea(a, n);
    rea(b, n);
    rea(c, n);
    memset(d, -1, sizeof(int) * 3333 * 2);
    cout << get(n - 1, 0);

    return 0;
}