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

int a[55][55];

int ans[55];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sci(a[i][j]);
        }
    }

    bool wn = false;

    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = i + 1; j < n; j++) {
            mx = max(mx, a[i][j]);
        }
        for (int j = 0; j < i; j++) {
            mx = max(mx, a[i][j]);
        }
        if (mx == n - 1 && !wn) {
            mx = n;
            wn = true;
        }
        cout << mx << " ";
    }

    return 0;
}