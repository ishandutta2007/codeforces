#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define sz(x) ((int)x.size())
#define endl "\n"
#define inf (1LL<<62)
#define ninf (-inf)

/// \class point
/// @brief A simple class to represent a point in a two dimensional space

class point {
    public:
    /// x coordinate of the point represented by the object
    long double x;
    /// y coordinate of the point represented by the object
    long double y;
    
    /// @brief This constructor is used to initialise the object with given x and y coordinates
    /// @param _x x coordinate
    /// @param _y y coordinate
    /// @return The object with initialised with the given coordinates
    point(long double _x, long double _y);
};

point::point(long double _x, long double _y) : x(_x), y(_y) {}

//finds area of the triangle defined by points a, b, and c
long double triangleArea(const point &a, const point &b, const point &c) {
    return (b.y - a.y) * (c.x-b.x) - (b.x - a.x) * (c.y - b.y);
}

//checks if given set of points a, b and c make a turn in counter-clockwise direction
bool isCCW(const point &a, const point &b, const point &c) {
    return (triangleArea(a, b, c) < 0);
}

//checks if given set of points a, b and c make a turn in clockwise direction
bool isCW(const point &a, const point &b, const point &c) {
    return (triangleArea(a, b, c) > 0);
}

//finds the square of the distance between points a and b
long double squareDistance(const point &a, const point &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool isBelow(const point &a, const point &b) {
    return (a.y < b.y) || (a.y == b.y && a.x > b.x);
}

bool isAbove(const point &a, const point &b) {
    return (a.y > b.y) || (a.y == b.y && a.x < b.x);
}

struct line {
    double a, b, c;
    line(point l, point r)
    {
        b = 1;
        a = -(r.y-l.y)/(r.x-l.x);
        c = -(b*r.y + a*r.x);
    }
};

const double EPS = 1e-9;

double det(double a, double b, double c, double d) {
    return a*d - b*c;
}

bool intersect(line m, line n, point &res) {
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

int x[200005], y[200005];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, H;
    cin >> n >> H;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    point eye(x[n], y[n]+H), last(x[n], y[n]);
    long double ans = 0, down = 0;
    for(int i = n-1; i >= 1; i--)
    {
        point p(x[i], y[i]);
        // cout << setprecision(20) << eye.x << " " << eye.y << "\n";
        // cout << setprecision(20) << last.x << " " << last.y << "\n";
        // cout << setprecision(20) << p.x << " " << p.y << "\n";
        if(!isCCW(eye, last, p))
        {
            if(down == 0)
            {
                ans += squareDistance(last, p);
            }
            else
            {
                point prev(x[i+1], y[i+1]);
                line l1(p, prev), l2(eye, last);
                point res(0, 0);
                intersect(l1, l2, res);
                // cout << res.x << " " << res.y << "\n";
                ans += squareDistance(p, res);
            }
            last = p;
            down = 0;
        }
        else
            down = 1;
    }
    cout << setprecision(20) << ans << "\n";
}