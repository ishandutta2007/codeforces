#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, t;

    Point() {}

    Point(int _x, int _y): x(_x), y(_y), t(-1) {}

    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y > p.y);
    }

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
};

const int MAXN = 100 * 1000 + 5;
Point p[2 * MAXN];

long long cp(const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].t = 1;
    }
    for(int i = 0; i < m; i++) {
        cin >> p[n + i].x >> p[n + i].y;
        p[n + i].t = 0;
    }
    sort(p, p + n + m);
    int s = 0;
    for(int i = 1; i < n + m; i++)
        if(p[i].y > p[s].y)
            s = i;
    vector<Point> ch;
    ch.push_back(p[s]);
    for(int i = s + 1; i < n + m; i++) {
        if(p[i].x == ch.back().x && p[i].y == ch.back().y) {
            if(p[i].t)
                ch.back().t = 1;
            continue;
        }
        while(ch.size() > 1 &&
              cp(ch.back() - ch[(int)ch.size() - 2], p[i] - ch.back()) > 0)
            ch.pop_back();
        ch.push_back(p[i]);
    }
    for(size_t i = 0; i < ch.size(); i++)
        if(ch[i].t) {
            cout << "Max\n";
            return 0;
        }
    cout << "Min\n";
    return 0;
}