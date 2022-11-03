#include <iostream>

using namespace std;

struct Vector
{
	double x, y;

	Vector(double x1 = 0, double y1 = 0)
	{
		x = x1;
		y = y1;
	}

	double len()
	{
		return sqrt(x * x + y * y);
	}

	Vector operator + (Vector v)
	{
		return Vector(x + v.x, y + v.y);
	}

	Vector operator - (Vector v)
	{
		return Vector(x - v.x, y - v.y);
	}

	Vector operator * (double l)
	{
		return Vector(x * l, y * l);
	}
};

bool check(double t2, int t, Vector v1, Vector v2, int u, Vector p1, Vector p2)
{
	if (t2 <= t) return ((p2 - (p1 + (v1 * t2))).len() / t2 <= u);
	else return ((p2 - (p1 + (v1 * t) + (v2 * (t2 - t)))).len() / t2 <= u);
}

int main()
{
	Vector p1, p2, v1, v2;
	int u, t;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> u >> t >> v1.x >> v1.y >> v2.x >> v2.y;

	double l = 1000000000, r = 0;

	for (int i = 0; i < 400; ++i)
	{
		double mid = (l + r) / 2;
		if (check(mid, t, v1, v2, u, p1, p2)) l = mid;
		else r = mid;
	}

	cout.precision(25);
	cout << l;

	return 0;
}