#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define seta(a, b) memset(a, b, sizeof(a))

double const eps = 1e-5;
double const pi = 3.1415926535897932384626433;

struct point
{
	double x, y;
};

struct line
{
	double a, b, c;
};

void make_line(point p1, point p2, line &l)
{
	l.a = p2.x - p1.x;
	l.b = p2.y - p1.y;
	l.c = - ((p1.x + p2.x) * l.a + (p1.y + p2.y) * l.b) / 2;
}

void cross(line l1, line l2, point &p)
{
	p.x = (l1.b * l2.c - l1.c * l2.b) / (l1.a * l2.b - l1.b * l2.a);
	p.y = (l1.a * l2.c - l1.c * l2.a) / (l1.b * l2.a - l1.a * l2.b);
}

double dist(point p1, point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double tmp;
point p[3], pp;
line l1, l2;

bool may(int n)
{
	double thi = atan2(p[0].y - pp.y, p[0].x - pp.x);
	double angl = 2 * pi / n;
	int now = 0;
	forn(i, n)
	{
		double xx = pp.x + tmp * cos(thi + i * angl), yy = pp.y + tmp * sin(thi + i * angl);
		forn(j, 3)
			if (abs(xx - p[j].x) < eps && abs(yy - p[j].y) < eps) now++;
	}
	if (now == 3) return true;
	else return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

/*	cout << cos(pi / 6) << " " << sin(pi / 6) << endl;
	cout << cos(2 * pi / 6) << " " << sin(2 * pi / 6) << endl;
	cout << cos(3 * pi / 6) << " " << sin(3 * pi / 6) << endl;*/
	
	forn(i, 3)
		scanf("%lf%lf", &p[i].x, &p[i].y);
		
	make_line(p[0], p[1], l1);
//	printf("%.10lf %.10lf %.10lf\n", l1.a, l1.b, l1.c);
	make_line(p[1], p[2], l2);
//	printf("%.10lf %.10lf %.10lf\n", l2.a, l2.b, l2.c);
	cross(l1, l2, pp);
//	cout << pp.x << " " << pp.y << endl;
	
	tmp = dist(pp, p[0]);
	for (int k = 3; k <= 100; k++)
		if (may(k))
		{
			printf("%.10lf\n", k * tmp * tmp * sin(2 * pi / k) / 2);
			return 0;
		}
	while (true){}
	
	return 0;
}