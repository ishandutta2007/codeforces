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

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

lint a[22];
lint c[22][22];
lint d[(1 << 18)][18];

int bit_count(int x) {
    int res = 0;
    while (x > 0) {
        res++;
        x &= x - 1;
    }
    return res;
}

int main() {
    sciiid(n, m, k);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        sciiid(x, y, z);
        c[--x][--y] = z;
    }
    lint ans = 0;
    for (int ms = 0; ms < (1 << n); ++ms) {
        int bc = bit_count(ms);
        for (int i = 0; i < n; i++) {
            if (ms & (1 << i)) {
                int nms = ms ^ (1 << i);
                for (int j = 0; j < n; j++) {
                    if (nms & (1 << j)) {
                        d[ms][i] = max(d[ms][i], d[nms][j] + c[j][i]);
                    }
                }
                d[ms][i] += a[i];
            }
            if (bc == m) {
                ans = max(ans, d[ms][i]);
            }
        }
    }
    cout << ans;

    return 0;
}