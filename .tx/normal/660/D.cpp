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

int xs[2222];
int ys[2222];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gcdi(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return gcd(a, b);
}

lint dist(lint x1, lint y1, lint x2, lint y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    map<pair<int, int>, map<lint, int>> m;
    scid(n);
    for (int i = 0; i < n; i++) {
        scii(xs[i], ys[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = ys[j] - ys[i];
            int b = xs[i] - xs[j];
            int g = gcdi(abs(a), abs(b));
            a /= g;
            b /= g;
            if (a < 0) {
                a = -a;
                b = -b;
            }
            if (a == 0 && b < 0) {
                b = -b;
            }

            lint d = dist(xs[i], ys[i], xs[j], ys[j]);

            m[{a, b}][d]++;
        }
    }

    lint ans = 0;

    for (auto& i : m) {
        for (auto& j : i.second) {
            ans += 1LL * j.second * (j.second - 1) / 2;
        }
    }

    cout << ans / 2;

    return 0;
}