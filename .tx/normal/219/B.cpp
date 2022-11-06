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

int main() {
    init_cin();
    lint p, d;
    cin >> p >> d;
    lint x = p;
    lint p10 = 1;
    lint last = p;
    while (true) {
        lint c = x / p10 % 10;
        if (c != 9) {
            x -= p10 * (c + 1);
        }
        if (p - x <= d) {
            last = x;
        } else {
            cout << last;
            return 0;
        }
        p10 *= 10;
    }
    return 0;
}