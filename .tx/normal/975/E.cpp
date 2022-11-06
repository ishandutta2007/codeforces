#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void rot(double& x, double& y, double a) {
    double r = dist(x, y, 0, 0);
    x /= r;
    y /= r;
    double xx = x * cos(a) - y * sin(a);
    double yy = x * sin(a) + y * cos(a);
    x = xx * r;
    y = yy * r;
}

double ang(double x1, double y1, double x2, double y2) {
    double cross = x1 * y2 - x2 * y1;
    double dot = x1 * x2 + y1 * y2;
    return atan2(cross, dot);
}

void solve(istream& cin, ostream& cout) {
    cout << setprecision(11) << fixed;
    int n, q;
    cin >> n >> q;
    vector<double> x(n), y(n);
    double xm = 0, ym = 0;
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
    }

    double ox = x[0];
    double oy = y[0];
    rep(i, 0, n) {
        x[i] -= ox;
        y[i] -= oy;
    }

    double sar = 0;

    rep(i, 0, n) {
        double x1 = x[i];
        double y1 = y[i];
        double x2 = x[(i + 1) % n];
        double y2 = y[(i + 1) % n];

        double ar = (x1 * y2 - x2 * y1);
        sar += ar;
        xm += (x1 + x2) * ar;
        ym += (y1 + y2) * ar;
    }

    xm /= 3 * sar;
    ym /= 3 * sar;

    vector<double> rm(n);
    vector<double> am1(n);
    rep(i, 0, n) {
        rm[i] = dist(x[i], y[i], xm, ym);

        if (!i) {
            am1[i] = 0;
            continue;
        }

        double x1 = x[i] - xm;
        double y1 = y[i] - ym;
        double x2 = x[0] - xm;
        double y2 = y[0] - ym;

        am1[i] = ang(x2, y2, x1, y1);
    }

    int c1 = 0, c2 = 1;

    auto cur = [&](int i, double& ax, double& ay) {
        ax = x[0] - xm;
        ay = y[0] - ym;
        double tr = dist(ax, ay, 0, 0);
        ax /= tr;
        ay /= tr;
        rot(ax, ay, am1[i]);
        ax *= rm[i];
        ay *= rm[i];
        ax += xm;
        ay += ym;
    };

    rep(iq, 0, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int f, t;
            cin >> f >> t;
            --f; --t;
            int c = c1 == f ? c2 : c1;
            double cx, cy;
            cur(c, cx, cy);

            double xm1 = cx;
            double ym1 = cy - rm[c];

            double ma = ang(xm - cx, ym - cy, xm1 - cx, ym1 - cy);

            if (c != 0) {
                x[0] -= cx;
                y[0] -= cy;
                rot(x[0], y[0], ma);
                x[0] += cx;
                y[0] += cy;
            }

            xm = xm1;
            ym = ym1;

            c1 = c;
            c2 = t;
        } else {
            int v;
            cin >> v;
            --v;
            double ax, ay;
            cur(v, ax, ay);
            cout << ax + ox << " " << ay + oy << "\n";
        }
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//fhyhjw