#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(int _x, int _y): x(_x), y(_y) {}
    
    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

struct Line {
    long long a, b, c;

    Line(const Point &p, const Point &q): a(q.y - p.y), b(p.x - q.x),
                                          c(-a * p.x - b * p.y) {}
};

const int MAXN = 100 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
Point p[MAXN];

long long cp(const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

long long sp(const Point &a, const Point &b) {
    return (long long)a.x * b.x + (long long)a.y * b.y;
}

long double len(const Point &q) {
    return sqrt(sp(q, q));
}

bool operator<(const Point &a, const Point &b) {
    long long cpp = cp(a, b);
    return cpp > 0 || (cpp == 0 && sp(a, a) < sp(b, b));
}

long double solve1(const Point &a, const Point &q) {
    return max((long double)q.x / a.x, (long double)q.y / a.y);
}

void intersect(const Line &a, const Line &b,
               long double &x, long double &y) {
    long long d = a.a * b.b - a.b * b.a;
    x = (long double)(-a.c * b.b - a.b * -b.c) / d;
    y = (long double)(a.a * -b.c - -a.c * b.a) / d;
}

long double solve2(const Point &a, const Point &b, const Point &q) {
    long double x, y;
    intersect(Line(a, b), Line(Point(0, 0), q), x, y);
    return len(q) / sqrt(x * x + y * y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n;
    Point q;
    cin >> n >> q.x >> q.y;
    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    sort(p, p + n);
    vector<Point> ch;
    ch.push_back(Point(0, 0));
    ch.push_back(p[0]);
    for(int i = 1; i < n; i++) {
        while(ch.size() > 1 &&
              cp(ch[(int)ch.size() - 1] - ch[(int)ch.size() - 2],
                 p[i] - ch[(int)ch.size() - 1]) <= 0)
            ch.pop_back();
        ch.push_back(p[i]);
    }
    ch.erase(ch.begin());
    long double ans = INF;
    for(size_t i = 0; i < ch.size(); i++) {
        ans = min(ans, solve1(ch[i], q));
        if(i + 1 < ch.size() && cp(ch[i], q) > 0 && cp(q, ch[i + 1]) > 0)
            ans = min(ans, solve2(ch[i], ch[i + 1], q));
    }
    cout << ans << '\n';
    return 0;
}