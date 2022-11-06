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

int a[555];
int d[555][555];

const int mod = 1e9 + 7;

int main() {
    scid(n);
    rea(a, n);
    for (int i = 0; i < n; i++) {
        d[i][i] = 1;
        if (i) {
            d[i - 1][i] = 1;
        }
    }
    for (int i = 2; i < n; i++) {
        for (int l = 0; l + i < n; l++) {
            int r = l + i;
            d[l][r] = d[l + 1][r];
            for (int j = l + 2; j <= r; j++) {
                if (a[j] > a[l + 1]) {
                    d[l][r] = (0LL + d[l][r] + 1LL * d[j - 1][r] * d[l + 1][j - 1]) % mod;
                }
            }
        }
    }

    cout << d[0][n - 1];

//
    return 0;
}