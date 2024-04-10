#include <bits/stdc++.h>

using namespace std;

typedef double T;

const int IT = 45;
const T C = 10'000;
const int N = 200'007;

int x[4], y[4];

T dist(T xa, T ya, T xb, T yb)
{
    auto square = [](const T v) {
        return v * v;
    };

    return sqrt(square(xa - xb) + square(ya - yb));
}

T solve_triangle_for_y(T ox, T oy, int t, T xm)
{
    auto sum_dist = [&](T ym) {
        return dist(ox, oy, xm, ym) + dist(x[t], y[t], xm, ym)
             + dist(x[t + 1], y[t + 1], xm, ym);
    };

    T ys = -C, ye = C;
    for (int ity = 0; ity < IT; ++ity) {
        T ylm = (ys + ys + ye) / 3;
        T yrm = (ys + ye + ye) / 3;

        if (sum_dist(ylm) < sum_dist(yrm)) {
            ye = yrm;
        } else {
            ys = ylm;
        }
    }

    return sum_dist((ys + ye) / 2.);
}

T solve_triangle(T ox, T oy, int t)
{
    T xs = -C, xe = C;
    for (int itx = 0; itx < IT; ++itx) {
        T xlm = (xs + xs + xe) / 3;
        T xrm = (xs + xe + xe) / 3;

        if (solve_triangle_for_y(ox, oy, t, xlm) < solve_triangle_for_y(ox, oy, t, xrm)) {
            xe = xrm;
        } else {
            xs = xlm;
        }
    }

    return solve_triangle_for_y(ox, oy, t, (xs + xe) / 2.);
}

T get_dist(T ox, T oy)
{
    T ret = 0.;
    for (int i = 0; i < 3; ++i) {
        ret = max(ret, solve_triangle(ox, oy, i));
    }

    return ret;
}

int main()
{
    for (int i = 0; i < 3; ++i)
        scanf("%d %d", &x[i], &y[i]);
    x[3] = x[0], y[3] = y[0];

    auto get_opt_dist = [&](T xm) {
        T ys = -C, ye = C;
        for (int ity = 0; ity < IT; ++ity) {
            T ylm = (ys + ys + ye) / 3;
            T yrm = (ys + ye + ye) / 3;

            if (get_dist(xm, ylm) < get_dist(xm, yrm)) {
                ye = yrm;
            } else {
                ys = ylm;
            }
        }

        return get_dist(xm, (ys + ye) / 2.);
    };

    T xs = -C, xe = C;
    for (int itx = 0; itx < IT; ++itx) {
        T xlm = (xs + xs + xe) / 3;
        T xrm = (xs + xe + xe) / 3;

        if (get_opt_dist(xlm) < get_opt_dist(xrm)) {
            xe = xrm;
        } else {
            xs = xlm;
        }
    }

    printf("%.10lf\n", get_opt_dist((xs + xe) / 2));
    return 0;
}