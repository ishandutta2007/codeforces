#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 105;

int sqDists[NMAX][NMAX];

struct Point {
    int x, y;
};

Point A[NMAX];

int distSq(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double dist(const Point& a, const Point& b) {
    return sqrt(distSq(a, b));
}

int crossProduct(const Point &o, const Point& a, const Point& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

inline int sign(int x) {
    return (x == 0 ? 0: (x < 0 ? -1: 1));
}

bool inside(const Point &o, const Point &a, const Point &b, const Point& c) {
    int x = sign(crossProduct(o, a, b));
    int y = sign(crossProduct(o, b, c));
    int z = sign(crossProduct(o, c, a));
    return (x == 0 && y == z) || 
           (y == 0 && x == z) ||
           (z == 0 && x == y) ||
           (x == y && y == z);
}

pair<double, double> circleCenter(const Point &a, const Point& b, const Point &c) {
    double a1 = b.x - a.x;
    double b1 = b.y - a.y;
    double c1 = -a1 * (a.x + b.x) / 2.0L + -b1 * (a.y + b.y) / 2.0L;

    double a2 = c.x - b.x;
    double b2 = c.y - b.y;
    double c2 = -a2 * (b.x + c.x) / 2.0L + -b2 * (b.y + c.y) / 2.0L;

    double det = a1 * b2 - a2 * b1;
    double x = -(c1 * b2 - c2 * b1) / det;
    double y = -(a1 * c2 - a2 * c1) / det;

    //cerr << x << ' ' << y << endl;
    
    return make_pair(x, y);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sqDists[i][j] = distSq(A[i], A[j]);
        }
    }

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int d1 = sqDists[i][j];
                int d2 = sqDists[j][k];
                int d3 = sqDists[k][i];
                if (d1 >= d2 + d3 || d2 >= d1 + d3 || d3 >= d1 + d2) continue;

                pair<double, double> r = circleCenter(A[j], A[k], A[i]);
                double dp = (A[i].x - r.first) * (A[i].x - r.first) +
                            (A[i].y - r.second) * (A[i].y - r.second);
                bool ok = true;
                for (int p = 0; p < n; ++p) {
                    if (p != i && p != j && p != k) {
                        double d = (A[p].x - r.first) * (A[p].x - r.first) +
                                   (A[p].y - r.second) * (A[p].y - r.second);
                        if (d < dp) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    ans = max(ans, sqrt(dp));
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                for (int l = 0; l < n; ++l) {
                    if (l == k || l == i || l == j) continue;
                    if (!(sqDists[i][j] == sqDists[j][k] &&
                          sqDists[j][k] == sqDists[k][l] &&
                          sqDists[k][l] == sqDists[l][i])) continue;

                    pair<double, double> r =
                        make_pair((A[i].x + A[k].x) / 2.0L,
                                  (A[i].y + A[k].y) / 2.0L);

                    double dp = (A[i].x - r.first) * (A[i].x - r.first) +
                                (A[i].y - r.second) * (A[i].y - r.second);
                    bool ok = true;
                    for (int p = 0; p < n; ++p) {
                        if (p != i && p != j && p != k && p != l) {
                            double d = (A[p].x - r.first) * (A[p].x - r.first) +
                                       (A[p].y - r.second) * (A[p].y - r.second);
                            if (d < dp) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) {
                        ans = max(ans, sqrt(dp));
                    }
                }
            }
        }
    }

    cout << setprecision(17) << fixed;

    if (ans > 0) {
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
}