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

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int a[55][55];
int b[55][55];

char s[55];

int main() {
    sciid(na, ma);
    for (int i = 0; i < na; i++) {
        scanf("%s", s);
        for (int j = 0; j < ma; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    sciid(nb, mb);
    for (int i = 0; i < nb; i++) {
        scanf("%s", s);
        for (int j = 0; j < mb; j++) {
            b[i][j] = s[j] - '0';
        }
    }
    int am = -1;
    int ax = -1;
    int ay = -1;
    for (int x = -na + 1; x <= nb - 1; x++) {
        for (int y = -ma + 1; y <= mb - 1; y++) {
            int t = 0;
            for (int i = 0; i < na; i++) {
                for (int j = 0; j < ma; j++) {
                    if (i + x < 0 || i + x >= nb || j + y < 0 || j + y >= mb) {
                        continue;
                    }
                    t += a[i][j] * b[i + x][j + y];
                }
            }
            if (t > am) {
                am = t;
                ax = x;
                ay = y;
            }
        }
    }
    printf("%d %d", ax, ay);
    return 0;
}