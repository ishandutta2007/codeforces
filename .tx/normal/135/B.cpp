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

int x[11];
int y[11];

int p[11];

int dot(int x1, int y1, int x2, int y2) {
    return x1 * x2 + y1 * y2;
}

bool isOrtAngle(int a, int b, int c) {
    return dot(x[b] - x[a], y[b] - y[a], x[c] - x[a], y[c] - y[a]) == 0;
}

bool isRectangle(int a, int b, int c, int d) {
    return isOrtAngle(a, b, d) && isOrtAngle(b, a, c) && isOrtAngle(c, b, d) && isOrtAngle(d, a, c);
}

int sqDist(int a, int b) {
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

bool isSquare(int a, int b, int c, int d) {
    return isRectangle(a, b, c, d) && sqDist(a, b) == sqDist(b, c) && sqDist(a, b) == sqDist(c, d) && sqDist(a, b) == sqDist(a, d);
}

int main() {
    int n = 8;
    for (int i = 0; i < n; i++) {
        scii(x[i], y[i]);
        p[i] = i;
    }

    do {
        if (isSquare(p[0], p[1], p[2], p[3]) && isRectangle(p[4], p[5], p[6], p[7])) {
            cout << "YES\n";
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << p[i * 4 + j] + 1 << " ";
                }
                cout << "\n";
            }
            return 0;
        }
    } while (next_permutation(p, p + n));

    cout << "NO";

    return 0;
}