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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

double get(int c, int b) {
    if (c % (2 * b) == 0) {
        return b;
    }
    double l = 2 * b;
    double r = 1e31;
    for (int i = 0; i < 1000; i++) {
        double m = (l + r) / 2;
        if (abs(floor(c / m) - floor(c / l)) < 1e-10) {
            l = m;
        } else {
            r = m;
        }
    }
    return l / 2;
}

int main() {
    int a, b;
    cin >> a >> b;
    if (b > a) {
        cout << -1;
        return 0;
    }
    double x = get(a - b, b);
    double y = get(a + b, b);
    printf("%.11f", min(x, y));

    return 0;
}