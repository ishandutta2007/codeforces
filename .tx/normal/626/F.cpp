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

int d[222][222][1111];
int a[222];

int mod = 1e9 + 7;

void add(int &a, int x) {
    a += x;
    if (a >= mod) {
        a -= mod;
    }
}

int main() {
    sciid(n, k);
    rea(a, n);
    sort(a, a + n);
    d[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int diff = i == 0 ? 0 : a[i] - a[i - 1];
        for (int t = 0; t <= k; t++) {
            for (int j = 0; j <= i; j++) {
                if (diff * j + t <= k) {
                    add(d[i + 1][j + 1][t + diff * j], d[i][j][t]);
                    add(d[i + 1][j][t + diff * j], d[i][j][t]);
                    if (j > 0) {
                        add(d[i + 1][j][t + diff * j], 1LL * j * d[i][j][t] % mod);
                        add(d[i + 1][j - 1][t + diff * j], 1LL * j * d[i][j][t] % mod);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        add(ans, d[n][0][i]);
    }
    cout << ans;

    return 0;
}