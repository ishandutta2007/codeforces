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

int x[5555];
int y[5555];
int z[5555];


int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(x[i]);
    }
    scid(m);
    for (int i = 0; i < m; i++) {
        sci(y[i]);
    }
    scid(k);
    for (int i = 0; i < k; i++) {
        sci(z[i]);
    }
    sciid(a, b);
    int r1 = *max_element(x, x + n);
    double mr2 = -1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            int p1 = y[i];
            int p2 = z[j];
            double r2 = 1.0 * r1 * r1 * p1 / (1.0 * a / b + 1.0 * p1 / p2) / p2;
            if (r2 < r1 * r1 - 1e-8) {
                mr2 = max(mr2, r2);
            }
        }
    }

    cout.precision(11);
    cout << fixed << sqrt(mr2);

    return 0;
}