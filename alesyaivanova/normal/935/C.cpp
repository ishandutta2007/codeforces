#include <iostream>
#include <cmath>

using namespace std;

const double E = 1e-9;

struct point
{
    long long x, y;
    point() {}
    point(long long a, long long b): x(a), y(b) {}

    void operator-=(point k)
    {
        x -= k.x;
        y -= k.y;
    }

    void operator+=(point k)
    {
        x += k.x;
        y += k.y;
    }
};

int main()
{
    long long r;
    point p, t;
    cin >> r >> p.x >> p.y >> t.x >> t.y;
    t -= p;
    long long d = t.x * t.x + t.y * t.y;
    if (d >= r * r)
    {
        cout << p.x << " " << p.y << " " << r;
        return 0;
    }
    if (d == 0)
    {
        cout.precision(20);
        double q = double(r) / 2;
        cout << fixed << q + p.x << " " << p.y << " " << q;
        return 0;
    }
    double d1 = sqrt(d);
    double x = -double(t.x) / d1 * r;
    double y = -double(t.y) / d1 * r;
    x = (x + t.x) / 2;
    y = (y + t.y) / 2;
    cout.precision(20);
    cout << fixed << x + p.x << " " << y + p.y << " ";
    d1 = (d1 + r) / 2;
    cout << fixed << d1;
}