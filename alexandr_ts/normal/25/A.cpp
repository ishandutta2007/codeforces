#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld EPS = 1e-5;
const ld PI = 3.141592653589793248;

struct Point
{
    ld x, y;
    Point operator + (Point const &b)
    {
        return {x + b.x, y + b.y};
    }
    Point operator / (ld const &k)
    {
        return {x / k, y / k};
    }
    Point operator - (Point const &b)
    {
        return {x - b.x, y - b.y};
    }
};

struct Line
{
    ld a, b, c;
};

Line orthLine(Line a)
{
    return {-a.b, a.a, a.c};
}

Line lineToPoint(Line a, Point b)
{
    return {a.a, a.b, -(a.a * b.x + a.b * b.y)};
}

Line lineFromPoints(Point a, Point b)
{
    return {a.y - b.y, b.x - a.x, a.x * b.y - a.y * b.x};
}

void print(Point a)
{
    cout << a.x << " " << a.y << endl;
}

void printL(Line a)
{
    cout << a.a << " " << a.b << " " << a.c << endl;
}

void read(Point &a)
{
    cin >> a.x >> a.y;
}

Point lineCross(Line a, Line b)
{
    return {(b.b * a.c - a.b * b.c) / (a.b * b.a - a.a * b.b),
        (b.a * a.c - a.a * b.c) / (a.a * b.b - a.b * b.a)};
}

ld pointDist(Point a, Point b)
{
    return hypotl(a.x - b.x, a.y - b.y);
}

ld crossProduct(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

ld dotProduct(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}

ld angleFromPoint(Point a1, Point o, Point a2)
{
    return fabs(atan2(crossProduct(a1 - o, a2 - o), dotProduct(a1 - o, a2 - o)));
}

ld sqr(ld t)
{
    return t * t;
}

int a[10000];

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int quaev, quaod;
    quaev = quaod = 0;
    for (int i = 0;i < n; i++)
        if (a[i] % 2)
            quaod++;
        else
            quaev++;
    for (int i = 0; i < n; i++)
        if (quaod == 1 && a[i] % 2)
            cout << i + 1;
        else if (quaev == 1 && !(a[i] % 2))
            cout << i + 1;

}