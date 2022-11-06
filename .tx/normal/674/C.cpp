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

const double eps = 1e-9;

double t[222222];
double cs[222222];
double is[222222];
double s[222222];

double d[55][222222];

int n;

vector<pair<double, double> > lines;

double cross(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

void add_line(double k, double b) {
    while (lines.size() > 1) {
        auto x = lines[lines.size() - 2];
        auto y = lines.back();
        if (cross(k - x.first, b - x.second, y.first - x.first, y.second - x.second) < eps) {
            lines.pop_back();
        } else {
            break;
        }
    }
    lines.push_back({k, b});
}

double btw(int l, int r) {
    return cs[r] - cs[l - 1] - (s[r] - s[l - 1]) * (is[n] - is[r]);
}

int main() {
    sci(n);
    scid(k);
    for (int i = 1; i <= n; i++) {
        scid(x);
        t[i] = x;
        is[i] = is[i - 1] + 1 / t[i];
        s[i] = s[i - 1] + t[i];
    }
    for (int i = 1; i <= n; i++) {
        cs[i] = cs[i - 1] + t[i] * (is[n] - is[i - 1]);
    }

    for (int i = 1; i <= n; i++) {
        d[1][i] = btw(1, i);
    }

    for (int i = 2; i <= k; i++) {
        lines.clear();
//        for (int j = 1; j < i; j++) {
//            add_line(-s[j], d[i - 1][j] - cs[j] + s[j] * is[n]);
//        }
        add_line(-s[i - 1], d[i - 1][i - 1] - cs[i - 1] + s[i - 1] * is[n]);
        int opt = 0;
        for (int j = i; j <= n; j++) {
            if (opt >= lines.size()) {
                return 1;
            }
            double x = is[j];
            while (opt + 1 < lines.size() && lines[opt].first * x + lines[opt].second > lines[opt + 1].first * x + lines[opt + 1].second) {
                opt++;
            }
            x = lines[opt].first * x + lines[opt].second;
            d[i][j] = x + cs[j] - s[j] * (is[n] - is[j]);
            add_line(-s[j], d[i - 1][j] - cs[j] + s[j] * is[n]);
        }
    }

//    for (int i = 1; i <= k; i++) {
//        for (int j = 1; j <= n; j++) {
//            cerr << d[i][j] << " ";
//        }
//        cerr << endl;
//    }

    printf("%.11f", d[k][n]);


    return 0;
}