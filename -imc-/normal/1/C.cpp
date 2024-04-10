#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ftype;

struct Point
{
	ftype x, y;

	Point() {}
	Point (ftype x, ftype y) : x (x), y (y) {}

	void read() { cin >> x >> y; }

	Point operator+ (const Point& p) { return Point (x + p.x, y + p.y); }
	Point operator- (const Point& p) { return Point (x - p.x, y - p.y); }
	Point operator* (ftype t) { return Point (x * t, y * t); }

	ftype sprod (const Point& p) { return x * p.x + y * p.y; }
	ftype vprod (const Point& p) { return x * p.y - y * p.x; }

	ftype length() { return sqrtl (x * x + y * y); }
};

struct Line
{
	ftype A, B, C;
};

Line makePerpendicular (Point through, Point vec)
{
	Line l = { vec.x, vec.y, -through.x * vec.x - through.y * vec.y };
	return l;
}

Point getIntersection (Line i, Line j)
{
	return Point ((i.C * j.B - j.C * i.B) / (j.A * i.B - i.A * j.B), (i.C * j.A - j.C * i.A) / (j.B * i.A - i.B * j.A));
}

int sign (ftype x) { return x > 0 ? 1 : -1; }

bool singleSide (Point a, Point b, Point c, Point d)
{
	return sign ((c - a).vprod (b - a)) * sign ((d - a).vprod (b - a)) == 1;
}

ftype getAngle (Point a, Point b, Point o, Point c)
{
	ftype acosWhat = (a - o).sprod (b - o) / (a - o).length() / (b - o).length();
	ftype pure;

	if (acosWhat > 1)
		pure = 0;
	else if (acosWhat < -1)
		pure = M_PI;
	else
		pure = acos (acosWhat);

	if (singleSide (a, b, o, c))
		return pure;
	else
		return M_PI * 2 - pure;
}

void answer (int n, ftype single)
{
	cout << fixed << setprecision (8) << n * single << endl;
	exit (0);
}

bool feq (ftype a, ftype b)
{
	return fabsl (a - b) <= 1e-5;
}

int main()
{
	Point a, b, c;

	a.read();
	b.read();
	c.read();

	Line abp = makePerpendicular ((a + b) * 0.5, a - b);
	Line bcp = makePerpendicular ((b + c) * 0.5, b - c);

	Point o = getIntersection (abp, bcp);

	//printf ("Center %Lg %Lg\n", o.x, o.y);

	ftype abAngle = getAngle (a, b, o, c),
		  bcAngle = getAngle (b, c, o, a),
		  acAngle = getAngle (a, c, o, b);

	ftype r = (a - o).length();
	//printf ("R %Lg Rs %Lg\n", r, r * r);

	//printf ("Angles %Lg %Lg %Lg\n", abAngle / M_PI * 180, bcAngle / M_PI * 180, acAngle / M_PI * 180);

	for (int n = 3; n <= 100; n++)
		for (int i = 1; i < n; i++)
			for (int j = 1; j < n; j++)
			{
				int last = n - i - j;
				if (last < 1) break;

				//printf ("cheching %i %i %i\n", i, j, last);

				if (feq (abAngle / i, bcAngle / j) && feq (abAngle / i, acAngle / last))
					answer (n, r * r * sin (2 * M_PI / n) / 2.0);
			}

	assert (!"Impossible");

	return 0;
}