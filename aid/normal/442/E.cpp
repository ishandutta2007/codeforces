#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(int x, int y): x(x), y(y) {}

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
};

const int MAXN = 1005;
const double EPS = 1e-9;
Point p[MAXN];
pair<double, char> seg[2 * (MAXN + 3)];
int w, h, n;

double len(const Point &p) {
    return sqrt((long long)p.x * p.x + (long long)p.y * p.y);
}

bool check(double r, int c) {
    int k = 0, bal = 0;
    if(p[c].x < r - EPS) {
        double d = sqrt(r * r - (long long)p[c].x * p[c].x),
            alpha = atan2(d, p[c].x);
        seg[k] = make_pair(M_PI - alpha, 2);
        k++;
        seg[k] = make_pair(-M_PI + alpha, -2);
        k++;
        bal += 2;
    }
    if(p[c].y < r - EPS) {
        double d = sqrt(r * r - (long long)p[c].y * p[c].y),
            alpha = atan2(d, p[c].y);
        seg[k] = make_pair(-M_PI / 2 - alpha, 2);
        k++;
        seg[k] = make_pair(-M_PI / 2 + alpha, -2);
        k++;
    }
    if(w - p[c].x < r - EPS) {
        double d = sqrt(r * r - (long long)(w - p[c].x) * (w - p[c].x)),
            alpha = atan2(d, w - p[c].x);
        seg[k] = make_pair(-alpha, 2);
        k++;
        seg[k] = make_pair(alpha, -2);
        k++;
    }
    if(h - p[c].y < r - EPS) {
        double d = sqrt(r * r - (long long)(h - p[c].y) * (h - p[c].y)),
            alpha = atan2(d, h - p[c].y);
        seg[k] = make_pair(M_PI / 2 - alpha, 2);
        k++;
        seg[k] = make_pair(M_PI / 2 + alpha, -2);
        k++;
    }
    for(int i = 0; i < n; i++) {
        if(p[i] == p[c])
            continue;
        double dist = len(p[i] - p[c]) / 2;
        if(dist > r - EPS)
            continue;
        double d = sqrt(r * r - dist * dist), alpha = atan2(d, dist),
            dir = atan2(p[i].y - p[c].y, p[i].x - p[c].x);
        if(dir - alpha < -M_PI + EPS) {
            seg[k] = make_pair(dir - alpha + 2 * M_PI, 1);
            bal++;
        }
        else
            seg[k] = make_pair(dir - alpha, 1);
        k++;
        if(dir + alpha > M_PI + EPS) {
            seg[k] = make_pair(dir + alpha - 2 * M_PI, -1);
            bal++;
        }
        else
            seg[k] = make_pair(dir + alpha, -1);
        k++;
    }
    sort(seg, seg + k);
    for(int i = 0; i < k && bal > 1; i++)
        bal += seg[i].second;
    return bal <= 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    srand(time(0));
    cin >> w >> h >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    random_shuffle(p, p + n);
    double ans = 0;
    for(int i = 0; i < n; i++) {
        if(!check(ans + EPS, i))
            continue;
        double l = ans + EPS, r = len(Point(w, h));
        for(int j = 0; j < 60; j++) {
            double m = (l + r) / 2;
            if(check(m, i))
                l = m;
            else
                r = m;
        }
        ans = l;
    }
    cout << ans << '\n';
    return 0;
}