#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 1000000;
const double EPS = 1e-10; 

struct Point {
    double x, y;
};

Point A[NMAX];

double distSq(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    Point p;
    cin >> n >> p.x >> p.y;

    for (int i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y;
    }
    A[n] = A[0];

    double pmax = -1e99, pmin = 1e99;
    for (int i = 0; i < n; ++i) {
        pmax = max(pmax, distSq(p, A[i]));
        pmin = min(pmin, distSq(p, A[i]));

        double x1 = A[i].x, x2 = A[i + 1].x;
        double y1 = A[i].y, y2 = A[i + 1].y;

        double a1 = y2 - y1;
        double b1 = x1 - x2;
        double c1 = -a1 * x1 - b1 * y1;

        double a2 = x2 - x1;
        double b2 = y2 - y1;
        double c2 = -a2 * p.x - b2 * p.y;

        double det = b2 * a1 - b1 * a2;
        double x = -(b2 * c1 - c2 * b1) / det;
        double y = (a2 * c1 - c2 * a1) / det;

        Point c = {x, y};
        if (c.x + EPS > min(x1, x2) && c.x - EPS < max(x1, x2) &&
            c.y + EPS > min(y1, y2) && c.y - EPS < max(y1, y2)) {
            pmin = min(pmin, distSq(p, c));
        }
    }

    double ans = acos(-1) * (pmax - pmin);
    cout << setprecision(17) << fixed;
    cout << ans << '\n';
}