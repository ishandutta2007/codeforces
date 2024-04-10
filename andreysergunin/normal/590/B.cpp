#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;


double sqr(double a) {
    return a * a;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    double x1, y1, x2, y2;
    double v, t;
    double vx, vy;
    double wx, wy;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> v >> t;
    cin >> vx >> vy;
    cin >> wx >> wy;
    double l = 0, r = 1000000000;
    for (int i = 0; i < 1000000; i++) {
        double m = (l + r) / 2;
        double dx = min(m, t) * vx + max((double)0, m - t) * wx;
        double dy = min(m, t) * vy + max((double)0, m - t) * wy;
        double len = sqrt(sqr(x1 + dx - x2) + sqr(y1 + dy - y2));
        if (len <= v * m)
            r = m;
        else
            l = m;
    }
    printf("%.12lf", l);
    return 0;
}