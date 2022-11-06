#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

#define sci(a) int a; scanf("%d", &a)
#define scii(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciii(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define scig(a) scanf("%d", &a)
#define sciig(a, b) scanf("%d%d", &a, &b)
#define sciiig(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef long long lint;

using namespace std;

bool eq(int a, int b, int x, int y) {
    return a == x && b == y;
}

int main() {
    sciii(n, x, y);
    n /= 2;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (eq(n + i, n + j, x, y)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}