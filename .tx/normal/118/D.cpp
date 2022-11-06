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

int d[111][111][2][11];

int main() {
    sciid(n1, n2);
    int k[2];
    scii(k[0], k[1]);
    d[1][0][0][1] = 1;
    d[0][1][1][1] = 1;
    int mod = 1e8;
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int u = 0; u < 2; u++) {
                if (u == 0 && i == 0) {
                    continue;
                }
                if (u == 1 && j == 0) {
                    continue;
                }
                for (int v = 1; v <= k[u]; v++) {
                    int& cur = d[i][j][u][v];
                    if (v == 1) {
                        for (int t = 1; t <= k[1 - u]; t++) {
                            cur += d[i - 1 + u][j - u][1 - u][t];
                            cur %= mod;
                        }
                    } else {
                        cur += d[i - 1 + u][j - u][u][v - 1];
                        cur %= mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int u = 0; u < 2; u++) {
        for (int v = 1; v <= k[u]; v++) {
            ans += d[n1][n2][u][v];
            ans %= mod;
        }
    }
    cout << ans;

    return 0;
}