#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define ll long long
#define double long double

struct Point{
    double x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(20);
    double a, b, c;
    cin >> a >> b >> c;
    Point st, fin;
    cin >> st.x >> st.y >> fin.x >> fin.y;
    double ans = abs(st.x - fin.x) + abs(st.y - fin.y);
    if (a == 0 || b == 0)  {
        cout << abs(st.x - fin.x) + abs(st.y - fin.y);
        return 0;
    }
    Point p, q, r, s;
    p.x = st.x, p.y = -(a * st.x + c) / b;
    q.x = -(b * st.y + c) / a, q.y = st.y;
    r.x = fin.x, r.y = -(a * fin.x + c) / b;
    s.x = -(b * fin.y + c) / a, s.y = fin.y;
    //cout << p.x << " " << p.y << "\n" << q.x << " " << q.y << "\n" << r.x << " " << r.y << "\n" << s.x << " " << s.y << "\n";
    cout << min({ans, dist(st, p) + dist(p, r) + dist(r, fin),
                                                  dist(st, p) + dist(p, s) + dist(s, fin),
                                                  dist(st, q) + dist(q, r) + dist(r, fin),
                                                  dist(st, q) + dist(q, s) + dist(s, fin)});
    return 0;
}