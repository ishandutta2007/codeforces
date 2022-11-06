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

pair<double, double> a[111111];

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    init_cin
    double ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    double ans = 1e31;

    for (int tt = 0; tt < 2; tt++) {
        swap(ax, bx);
        swap(ay, by);

        sort(a, a + n, [ax, ay, tx, ty](const pair<double, double> &a, const pair<double, double> &b) {
            puts("");
            double da = dist(a.first, a.second, ax, ay) - dist(a.first, a.second, tx, ty);
            double db = dist(b.first, b.second, ax, ay) - dist(b.first, b.second, tx, ty);
            return da < db;
        });

        double r = dist(ax, ay, a[0].first, a[0].second) + dist(tx, ty, a[0].first, a[0].second);
        for (int i = 1; i < n; i++) {
            r += dist(tx, ty, a[i].first, a[i].second) * 2;
        }

        double gr = r;

        ans = min(ans, r);

        if (n == 1) {
            continue;
        }

        for (int i = 0; i < n; i++) {
            double tt = dist(bx, by, a[i].first, a[i].second) + dist(tx, ty, a[i].first, a[i].second);
            double r;
            if (i == 0) {
                r = dist(ax, ay, a[1].first, a[1].second) + dist(tx, ty, a[1].first, a[1].second);
                for (int j = 2; j < n; j++) {
                    r += dist(tx, ty, a[j].first, a[j].second) * 2;
                }
                r += tt;
            } else {
                r = gr - dist(tx, ty, a[i].first, a[i].second) * 2 + tt;
            }
            ans = min(ans, r);
        }

    }

    printf("%.11f", ans);

    return 0;
}