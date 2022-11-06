#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) double vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

void inter(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y) {
    double d = a1 * b2 - b1 * a2;
    x = (-c1 * b2 + b1 * c2) / d;
    y = (-a1 * c2 + c1 * a2) / d;
}

const double eps = 1e-13;

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    scid(x1, y1, x2, y2);
//    if (x1 == x2 || y1 == y2) {
//        cout << -1;
//        return 0;
//    }
    double gtin = -1e31;
    double gtout = 1e31;
    for (int in = 0; in < n; in++) {
        scidl(x, y, vx, vy);
        if (vx == 0) {
            if (x <= x1 || x >= x2) {
                cout << -1;
                return 0;
            }
        }
        if (vy == 0) {
            if (y <= y1 || y >= y2) {
                cout << -1;
                return 0;
            }
        }
        double a = vy;
        double b = -vx;
        double c = -(a * x + b * y);

        double tin = 1e31;
        double tout = -1e31;

        double ix, iy;
        inter(a, b, c, 1, 0, -x1, ix, iy);

        if (vx != 0 && iy < y2 + eps && iy > y1 - eps) {
            double t = 1.0 * (x1 - x) / vx;
            if (t >= 0) {
                tin = min(tin, t);
                tout = max(tout, t);
            }
        }

        inter(a, b, c, 1, 0, -x2, ix, iy);

        if (vx != 0 && iy < y2 + eps && iy > y1 - eps) {
            double t = 1.0 * (x2 - x) / vx;
            if (t >= 0) {
                tin = min(tin, t);
                tout = max(tout, t);
            }
        }

        inter(a, b, c, 0, 1, -y1, ix, iy);

        if (vy != 0 && ix < x2 + eps && ix > x1 - eps) {
            double t = 1.0 * (y1 - y) / vy;
            if (t >= 0) {
                tin = min(tin, t);
                tout = max(tout, t);
            }
        }

        inter(a, b, c, 0, 1, -y2, ix, iy);

        if (vy != 0 && ix < x2 + eps && ix > x1 - eps) {
            double t = 1.0 * (y2 - y) / vy;
            if (t >= 0) {
                tin = min(tin, t);
                tout = max(tout, t);
            }
        }

        if (vx == 0 && vy == 0) {
            tin = 0;
            tout = 1e31;
        }

        if (x > x1 && x < x2 && y > y1 && y < y2) {
            tin = 0;
        }

        if (tout - tin > 3 * eps) {
            gtin = max(gtin, tin + eps);
            gtout = min(gtout, tout - eps);
        } else {
            cout << -1;
            return 0;
        }
    }

    if (gtin < 0 || gtin > gtout - eps) {
        cout << -1;
        return 0;
    }

    cout << setprecision(11) << fixed << gtin;

    return 0;
}