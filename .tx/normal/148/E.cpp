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

int c[111][111];
int k[111];
int d[2][11111];
int a[111][111];

int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        sci(k[i]);
        for (int j = 0; j < k[i]; j++) {
            sci(a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k[i]; j++) {
            int s = 0;
            int res = 0;
            for (int t = 0; t < j; t++) {
                s += a[i][t];
            }
            res = s;
            for (int t = 0; t < j; t++) {
                s += a[i][k[i] - t - 1] - a[i][j - 1 - t];
                res = max(res, s);
            }
            c[i][j] = res;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cur = i & 1;
        int prev = 1 - cur;
        fill(d[cur], d[cur] + m + 1, 0);
        for (int j = 1; j <= m; j++) {
            for (int t = 0; t <= j && t <= k[i]; t++) {
                d[cur][j] = max(d[cur][j], d[prev][j - t] + c[i][t]);
            }
        }
        ans = max(ans, *max_element(d[cur], d[cur] + m + 1));
    }

    cout << ans;

    return 0;
}