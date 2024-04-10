#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 9;

typedef double DB;

const DB eps = 1e-8;
const DB PI = acos(-1.0L);

int cmp(DB a, DB b) { return a - b < -eps ? -1 : a - b > eps; }

struct Vector {
    DB x, y;
    DB abs() { return hypot(x, y); }
    DB arg() { return atan2(y, x); }
};

DB stdarg(DB arg) { return arg < -PI ? arg + 2 * PI : (arg < PI ? arg : arg - 2 * PI); }

typedef Vector Point;

int n, k;

Point p[N];

bool check(DB r) {
    vector<pair<DB, int>> vc;
    for (int i = 1; i <= n; ++i) {
        DB d = p[i].abs();
        if (cmp(d, 2 * r) <= 0) {
            DB theta = acos(d / 2 / r);
            DB a = stdarg(p[i].arg() - theta);
            DB b = stdarg(p[i].arg() + theta);
            if (a <= b) {
                vc.push_back({a, 1});
                vc.push_back({b, -1});
            }
            else {
                vc.push_back({a, 1});
                vc.push_back({PI, -1});
                vc.push_back({-PI, 1});
                vc.push_back({b, -1});
            }
        }
    }
    sort(vc.begin(), vc.end());
    int cnt = 0, maxv = 0;
    for (int i = 0, sz = vc.size(); i < sz; ++i) {
        cnt += vc[i].second;
        maxv = max(cnt, maxv);
    }
    return maxv >= k;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    DB L = 0.0, R = 200000.0;
    while (cmp(L, R) == -1) {
        DB M = (L + R) / 2;
        if (check(M)) R = M;
        else L = M;
    }
    printf("%.10lf\n", L);
    return 0;
}