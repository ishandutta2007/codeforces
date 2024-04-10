#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
    
    Point() {}

    Point(double x, double y): x(x), y(y) {}

    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    Point operator*(double k) const {
        return Point(x * k, y * k);
    }

    Point operator/(double k) const {
        return Point(x / k, y / k);
    }
};

struct Vertex {
    int id, lid, rid;
    double r;

    bool operator<(const Vertex &v) const {
        return r > v.r + EPS || (r > v.r - EPS && id < v.id);
    }
};

const int MAXN = 100 * 1000 + 5;
Point pol[MAXN], ch[MAXN];
Vertex v[MAXN];
char del[MAXN];
set<Vertex> st;

double sp(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

double cp(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double len(const Point &p) {
    return sqrt(sp(p, p));
}

bool operator<(const Point &a, const Point &b) {
    double cpp = cp(a - pol[0], b - pol[0]);
    return cpp > EPS || (cpp > -EPS && sp(a - pol[0], a - pol[0]) <
                         sp(b - pol[0], b - pol[0]));
}

double getR(const Point &a, const Point &b, const Point &c) {
    return len(b - a) * len(c - b) * len(a - c) / (2 * fabs(cp(b - a, c - a)));
}

double getAngle(const Point &a, const Point &b) {
    return atan2(cp(a, b), sp(a, b));
}

double get2SegmentS(const Point &a, const Point &b, double r) {
    Point h = (a + b) / 2;
    double hlen = sqrt(r * r - sp(h - a, h - a));
    Point d = h - a;
    swap(d.x, d.y);
    d.x *= -1;
    d = d / len(d) * hlen;
    Point o = h + d;
    return (fabs(getAngle(a - o, b - o)) * r * r - fabs(cp(a - o, b - o)));
}

int buildCH(int n) {
    for(int i = 1; i < n; i++)
        if(pol[i].x < pol[0].x - EPS ||
           (pol[i].x < pol[0].x + EPS && pol[i].y < pol[0].y - EPS))
            swap(pol[i], pol[0]);
    if(n == 1)
        return 1;
    sort(pol + 1, pol + n);
    ch[0] = pol[0];
    ch[1] = pol[1];
    int h = 2;
    for(int i = 2; i < n; i++) {
        while(h >= 2 && cp(ch[h - 1] - ch[h - 2], pol[i] - ch[h - 1]) < EPS)
            h--;
        ch[h] = pol[i];
        h++;
    }
    while(h > 2 && cp(ch[h - 1] - ch[h - 2], pol[0] - ch[h - 1]) < EPS)
        h--;
    for(int i = 0; i < h; i++)
        pol[i] = ch[i];
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    int n, r;
    cin >> n >> r;
    for(int i = 0; i < n; i++)
        cin >> pol[i].x >> pol[i].y;
    n = buildCH(n);
    rotate(pol, pol + 1, pol + n);
    for(int i = 0; i < n; i++) {
        v[i].id = i;
        v[i].lid = (i == 0? n - 1 : i - 1);
        v[i].rid = (i == n - 1? 0 : i + 1);
        if(n > 2)
            v[i].r = getR(pol[i], pol[v[i].lid], pol[v[i].rid]);
    }
    for(int i = 0; i < n; i++)
        st.insert(v[i]);
    while(st.size() > 3 && st.begin()->r > r + EPS) {
        Vertex p = *st.begin();
        st.erase(st.begin());
        st.erase(v[p.lid]);
        st.erase(v[p.rid]);
        del[p.id] = true;
        v[p.lid].rid = p.rid;
        v[p.rid].lid = p.lid;
        v[p.lid].r = getR(pol[p.lid], pol[v[p.lid].lid], pol[v[p.lid].rid]);
        v[p.rid].r = getR(pol[p.rid], pol[v[p.rid].lid], pol[v[p.rid].rid]);
        st.insert(v[p.lid]);
        st.insert(v[p.rid]);
    }
    if(st.size() == 3 && st.begin()->r > r + EPS)
        for(set<Vertex>::iterator it = st.begin(); it != st.end(); it++)
            if(sp(pol[it->lid] - pol[it->id],
                  pol[it->rid] - pol[it->id]) < EPS) {
                del[it->id] = true;
                st.erase(it);
                break;
            }
    if(st.size() == 1) {
        cout << 0 << '\n';
        return 0;
    }
    double s = 0;
    int fst = -1, lst = -1;
    for(int i = 0; i < n; i++)
        if(!del[i]) {
            if(fst == -1)
                fst = i;
            if(lst != -1) {
                s += cp(pol[lst], pol[i]);
                s += get2SegmentS(pol[lst], pol[i], r);
            }
            lst = i;
        }
    s += cp(pol[lst], pol[fst]);
    s += get2SegmentS(pol[lst], pol[fst], r);
    s /= 2;
    cout << s << '\n';
    return 0;
}