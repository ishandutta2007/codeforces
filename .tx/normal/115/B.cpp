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

char a[222][222];

int main() {
    sciid(n, m);
    int last = -1;
    for (int i = 0; i < n; i++) {
        scanf("\n%s", a[i]);
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'W') {
                last = i;
                break;
            }
        }
    }
    n = last + 1;
    if (n == 0) {
        cout << 0;
        return 0;
    }

    int x = 0;
    int d = 1;
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        int f = x;
        int ox = x;
        while (x >= 0 && x < m) {
            if (a[i][x] == 'W' || a[i + 1][x] == 'W') {
                f = x;
            }
            x += d;
        }
        ans += abs(f - ox);
        x = f;
        d = -d;
    }

    cout << ans;

    return 0;
}