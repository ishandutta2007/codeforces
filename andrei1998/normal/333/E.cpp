#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

const int NMAX = 3000 + 5;
int n;

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0):
        x(_x), y(_y) {}
} points[NMAX];
bool active[NMAX];

int dist(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int ccw(const Point &a, const Point &ref, const Point &b) {
    return (a.x - ref.x) * (b.y - ref.y) - (a.y - ref.y) * (b.x - ref.x);
}

bool operator<(const Point &a, const Point &b) {
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int hull[2 * NMAX];
int hullSz;

inline int urm(int x) {
    if (x == hullSz)
        return 1;
    else
        return x + 1;
}

int works(const Point &center, int radius) {
    for (int i = 1; i <= n; ++i) {
        if (dist(center, points[i]) < radius)
            active[i] = false;
        else
            active[i] = true;
    }

    hullSz = 0;
    //Convex hull - lower envelope
    for (int i = 1; i <= n; ++i)
        if (active[i]) {
            while (hullSz > 1 && ccw(points[hull[hullSz - 1]], points[hull[hullSz]], points[i]) >= 0)
                --hullSz;
            hull[++hullSz] = i;
        }

    //Convex hull - upper envelope
    --hullSz;
    int auxSz = hullSz;

    for (int i = n; i; --i)
        if (active[i]) {
            while (hullSz > auxSz + 1 && ccw(points[hull[hullSz - 1]], points[hull[hullSz]], points[i]) >= 0)
                --hullSz;
            hull[++hullSz] = i;
        }
    --hullSz;

    //Rotating calipers
    int res = 0;
    if (hullSz > 1)
        for (int i = 1, j = 1; i <= hullSz; ++ i) {
            while (dist(points[hull[i]], points[hull[j]]) <= dist(points[hull[i]], points[hull[urm(j)]]))
                j = urm(j);
            res = max(res, dist(points[hull[i]], points[hull[j]]));
        }

    return res;
}

int dists[NMAX];
int best(const Point &center) {
    for (int i = 1; i <= n; ++ i)
        dists[i] = dist(center, points[i]);
    sort(dists + 1, dists + n + 1);

    int st = 2;
    int dr = n;
    int mid;
    int ans = 1;

    while (st <= dr) {
        mid = (st + dr) >> 1;
        if (works(center, dists[mid]) >= dists[mid]) {
            ans = mid;
            st = mid + 1;
        }
        else
            dr = mid - 1;
    }

    return dists[ans];
}

int main()
{
    //freopen("data.in", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> points[i].x >> points[i].y;
    sort(points + 1, points + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        ans = max(ans, best(points[i]));
    cout << fixed << setprecision(20) << sqrtl(1.0L * ans) * 0.5 << '\n';
    return 0;
}