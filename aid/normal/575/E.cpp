#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
};

const int X = 100 * 1000;
vector<Point> pp, ch;

long long cp(const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

long long sp(const Point &a, const Point &b) {
    return (long long)a.x * b.x + (long long)a.y * b.y;
}

long long sqlen(const Point &p) {
    return sp(p, p);
}

long double len(const Point &p) {
    return sqrt(sp(p, p));
}

bool cmp(const Point &a, const Point &b) {
    long long cpp = cp(a - pp[0], b - pp[0]);
    return cpp > 0 || (cpp == 0 && sqlen(a - pp[0]) < sqlen(b - pp[0]));
}

void add(const Point &p, int v) {
    if(p.x >= v)
        pp.push_back(Point(p.x - v, p.y));
    else {
        pp.push_back(Point(0, max(0, p.y - (v - p.x))));
        pp.push_back(Point(0, min(X, p.y + (v - p.x))));
    }
    if(p.y >= v)
        pp.push_back(Point(p.x, p.y - v));
    else {
        pp.push_back(Point(max(0, p.x - (v - p.y)), 0));
        pp.push_back(Point(min(X, p.x + (v - p.y)), 0));
    }
    if(p.x + v <= X)
        pp.push_back(Point(p.x + v, p.y));
    else {
        pp.push_back(Point(X, max(0, p.y - (v - (X - p.x)))));
        pp.push_back(Point(X, min(X, p.y + (v - (X - p.x)))));
    }
    if(p.y + v <= X)
        pp.push_back(Point(p.x, p.y + v));
    else {
        pp.push_back(Point(max(0, p.x - (v - (X - p.y))), X));
        pp.push_back(Point(min(X, p.x + (v - (X - p.y))), X));
    }
}

long double getr(const Point &a, const Point &b, const Point &c) {
    return len(b - a) * len(c - b) * len(a - c) / 2 / fabs(cp(b - a, c - a));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        Point p;
        int v;
        cin >> p.x >> p.y >> v;
        add(p, v);
    }
    sort(pp.begin(), pp.end());
    pp.resize(unique(pp.begin(), pp.end()) - pp.begin());
    sort(pp.begin() + 1, pp.end(), cmp);
    ch.push_back(pp[0]);
    ch.push_back(pp[1]);
    for(size_t i = 2; i < pp.size(); i++) {
        while(ch.size() >= 2 && cp(ch[ch.size() - 1] - ch[ch.size() - 2],
                                   pp[i] - ch[ch.size() - 1]) <= 0)
            ch.pop_back();
        ch.push_back(pp[i]);
    }
    while(ch.size() >= 3 && cp(ch[ch.size() - 1] - ch[ch.size() - 2],
                               ch[0] - ch[ch.size() - 1]) <= 0)
        ch.pop_back();
    ch.push_back(ch[0]);
    ch.push_back(ch[1]);
    size_t ansp = 0;
    long double ansr = getr(ch[0], ch[1], ch[2]);
    for(size_t i = 1; i + 2 < ch.size(); i++) {
        long double r = getr(ch[i], ch[i + 1], ch[i + 2]);
        if(r > ansr) {
            ansp = i;
            ansr = r;
        }
    }
    cout << ch[ansp].x << ' ' << ch[ansp].y << '\n'
         << ch[ansp + 1].x << ' ' << ch[ansp + 1].y << '\n'
         << ch[ansp + 2].x << ' ' << ch[ansp + 2].y << '\n';
    return 0;
}