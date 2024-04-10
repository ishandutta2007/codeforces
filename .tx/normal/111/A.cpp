#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    init_cin();

    lint n, x, y;
    cin >> n >> x >> y;

    if (n > y || (y - n + 1) * (y - n + 1) + n - 1 < x) {
        cout << -1;
        return 0;
    }

    cout << y - n + 1 << "\n";
    for (int i = 0; i + 1 < n; ++i) {
        cout << 1 << "\n";
    }

    return 0;
}