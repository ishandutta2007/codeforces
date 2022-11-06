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

double d[1111][1111];

int main() {
    sciid(w, b);
    d[w][b] = 1;
    for (int i = w; i >= 0; i--) {
        for (int j = b; j > 0; j--) {
            int drag = (w - i + b - j) % 3;
            if (drag) {
                if (i >= 1 && j >= 1) {
                    d[i - 1][j - 1] += 1.0 * j / (i + j) * 1.0 * i / (i - 1 + j) * d[i][j];
                }
                if (j >= 2) {
                    d[i][j - 2] += 1.0 * j / (i + j) * 1.0 * (j - 1) / (i + j - 1) * d[i][j];
                }
                if (i + j == 1) {
                    d[i][j - 1] += d[i][j];
                }
            } else {
                d[i][j - 1] += 1.0 * j / (i + j) * d[i][j];
            }
        }
    }

//    for (int i = 0; i <= w; i++) {
//        for (int j = 0; j <= b; j++) {
//            printf("%.3f ", d[i][j]);
//        }
//        printf("\n");
//    }

    double win = 0;
    for (int i = w; i > 0; i--) {
        for (int j = b; j >= 0; j--) {
            int drag = (w - i + b - j) % 3;
            if (drag == 0) {
                win += d[i][j] * i / (i + j);
            }
        }
    }
    printf("%.11f", win);
    return 0;
}