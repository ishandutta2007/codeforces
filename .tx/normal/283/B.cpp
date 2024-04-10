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

using namespace std;

const int N = 222222;

lint dy[N];
int a[N];

int n;

lint get(int x) {
    if (dy[x] != -1) {
        return dy[x];
    }
    if (x + a[x] > n) {
        return dy[x] = a[x];
    }
    if (x + a[x] - a[x + a[x]] <= 0) {
        return dy[x] = a[x] + a[x + a[x]];
    }

    dy[x] = -2;

    lint t = get(x + a[x] - a[x + a[x]]);
    if (t == -2) {
        return dy[x] = -2;
    }

    return dy[x] = a[x] + a[x + a[x]] + t;
}

int main() {
    sci(n);
    for (int i = 2; i <= n; i++) {
        sci(a[i]);
    }
    memset(dy, -1, sizeof(dy));
    for (int i = 1; i < n; i++) {
        a[1] = i;
        dy[1] = -1;
        lint x = get(1);
        if (x == -2) {
            cout << -1;
        } else {
            cout << x;
        }
        cout << "\n";
    }

    return 0;
}