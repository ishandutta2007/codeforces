#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(int _x, int _y): x(_x), y(_y) {}

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

const int MAXN = 100 * 1000 + 5;
pair<Point, int> p[MAXN];

long long cp(const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

long long sp(const Point &a, const Point &b) {
    return (long long)a.x * b.x + (long long)a.y * b.y;
}

bool cmp0(const Point &a, const Point &b) {
    long long cpp = cp(a, b);
    return cpp > 0 || (cpp == 0 && sp(a, a) < sp(b, b));
}

bool cmp(const pair<Point, int> &a, const pair<Point, int> &b) {
    return cmp0(a.first, b.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first.x >> p[i].first.y;
        p[i].second = i;
    }
    for(int i = 1; i < n; i++)
        if(p[i] < p[0])
            swap(p[i], p[0]);
    for(int i = 1; i < n; i++)
        p[i].first = p[i].first - p[0].first;
    sort(p + 1, p + n, cmp);
    cout << p[0].second + 1 << ' ' << p[1].second + 1 << ' ';
    for(int i = 2; i < n; i++)
        if(cp(p[1].first, p[i].first) > 0) {
            cout << p[i].second + 1 << '\n';
            break;
        }
    return 0;
}