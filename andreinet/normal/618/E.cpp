#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 300005;
const double EPS = 1e-10;

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y):
        x(_x), y(_y) {}
    Point operator*(const Point& o) const {
        return Point(x * o.x - y * o.y, x * o.y + y * o.x);
    }
    Point operator+(const Point& o) const {
        return Point(x + o.x, y + o.y);
    }
    Point operator-(const Point& o) const {
        return Point(x - o.x, y - o.y);
    }
};

Point add[4 * NMAX], mul[4 * NMAX];

void build(int node, int left, int right) {
    if (left == right) {
        add[node] = Point(left, 0);
        mul[node] = Point(0, 0);
    } else {
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        mul[node] = Point(1, 0);
        add[node] = Point(0, 0);
    }
}

void split(int node, int left, int right) {
    if (left < right) {
        mul[2 * node + 1] = mul[2 * node + 1] * mul[node];
        mul[2 * node + 2] = mul[2 * node + 2] * mul[node];
        add[2 * node + 1] = add[2 * node + 1] * mul[node];
        add[2 * node + 2] = add[2 * node + 2] * mul[node];
        add[2 * node + 1] = add[2 * node + 1] + add[node];
        add[2 * node + 2] = add[2 * node + 2] + add[node];
        mul[node] = Point(1, 0);
        add[node] = Point(0, 0);
    }
}

Point query(int node, int left, int right, int pos) {
    split(node, left, right);
    if (left == right) {
        return add[node];
    } else {
        int mid = (left + right) / 2;
        if (pos <= mid) return query(2 * node + 1, left, mid, pos);
        else return query(2 * node + 2, mid + 1, right, pos);
    }
}

Point uadd(int node, int left, int right, int lq, Point val) {
    split(node, left, right);
    if (lq <= left) {
        add[node] = add[node] + val;
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) {
            uadd(2 * node + 1, left, mid, lq, val);
        }
        uadd(2 * node + 2, mid + 1, right, lq, val);
    }
}

Point umul(int node, int left, int right, int lq, Point val) {
    split(node, left, right);
    if (lq <= left) {
        mul[node] = mul[node] * val;
        add[node] = add[node] * val;
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) {
            umul(2 * node + 1, left, mid, lq, val);
        }
        umul(2 * node + 2, mid + 1, right, lq, val);
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    build(0, 0, n);

    cout << setprecision(17) << fixed;
    double PI = acos(-1);
    while (m-- > 0) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, l;
            cin >> p >> l;

            Point a = query(0, 0, n, p - 1);
            Point b = query(0, 0, n, p);
            double x = b.x - a.x, y = b.y - a.y;
            double len = sqrt(x * x + y * y);
            double addx = (double) x / len * l;
            double addy = (double) y / len * l;
            uadd(0, 0, n, p, Point(addx, addy));

            Point ans = query(0, 0, n, n);
            cout << ans.x << ' ' << ans.y << '\n';
        } else {
            int p, l;
            cin >> p >> l;

            double ang = (double) l / 180 * PI;
            if (ang > PI) {
                ang -= 2 * PI;
            }

            Point a = query(0, 0, n, p - 1);

            double x = a.x, y = a.y;

            uadd(0, 0, n, p, Point(-x, -y));
            umul(0, 0, n, p, Point(cos(-ang), sin(-ang)));
            uadd(0, 0, n, p, Point(x, y));

            Point ans = query(0, 0, n, n);
            cout << ans.x << ' ' << ans.y << '\n';
        }
    }
}