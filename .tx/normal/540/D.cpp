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

double d[111][111][111];

int main() {
    sciiid(a, b, c);
    d[a][b][c] = 1;
    for (int i = a; i >= 0; i--) {
        for (int j = b; j >= 0; j--) {
            for (int k = c; k >= 0; k--) {
                double cd = d[i][j][k];
                int cp = i * j + i * k + j * k;
                if (cp == 0) {
                    continue;
                }
                if (i > 0) {
                    d[i - 1][j][k] += cd * i * k / cp;
                }
                if (j > 0) {
                    d[i][j - 1][k] += cd * i * j / cp;
                }
                if (k > 0) {
                    d[i][j][k - 1] += cd * j * k / cp;
                }
            }
        }
    }

    int t[3];
    for (int i = 0; i < 3; i++) {
        t[0] = t[1] = t[2] = 0;
        double ans = 0;
        for (int j = 1; j <= 100; j++) {
            t[i]++;
            ans += d[t[0]][t[1]][t[2]];
        }
        printf("%.11f ", ans);
    }


    return 0;
}