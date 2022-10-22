#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ftype;

struct Point
{
	ftype x, y;

	Point() {}
	Point (ftype x0, ftype y0) : x (x0), y (y0) {}

	void read() { cin >> x >> y; }

	Point operator+ (const Point& p) { return Point (x + p.x, y + p.y); }
	Point operator- (const Point& p) { return Point (x - p.x, y - p.y); }
	Point operator* (ftype t) { return Point (x * t, y * t); }

	ftype length() { return sqrtl (x * x + y * y); }
};

struct Circle
{
	Point center;
	ftype r;

	Circle() {}
	Circle (Point p, ftype R) : center (p), r (R) {}

	void read() { center.read(); cin >> r; }
};

Circle buildAppolonius (Point a, Point b, ftype k)
{
	ftype d = (a - b).length();

	ftype A = -2 * d * k * k / (k * k - 1), B = d * d * k * k / (k * k - 1);
	ftype radius = sqrtl (A * A / 4 - B);
	assert (A * A / 4 >= B);

	ftype distanceFromA = -A / 2;

	return Circle (a + (b - a) * (distanceFromA / d), radius);
}

vector <Point> getLineCircleIntersection (ftype A, ftype B, ftype C, ftype r)
{
	ftype d = -C / sqrtl (A * A + B * B);

	ftype px = -A * C / (A * A + B * B),
		  py = -B * C / (A * A + B * B);

	if (r * r < d * d)
		return vector <Point> ();

	ftype delta = sqrtl ((r * r - d * d) / (A * A + B * B));

	vector <Point> answer;
	answer.push_back (Point (px + delta * B, py - delta * A));
	answer.push_back (Point (px - delta * B, py + delta * A));
	return answer;
}

vector <Point> getCircleCircleIntersection (Circle a, Circle b)
{
	b.center = b.center - a.center;
	vector <Point> intersection = getLineCircleIntersection (-2 * b.center.x, -2 * b.center.y, b.center.x * b.center.x + b.center.y * b.center.y + a.r * a.r - b.r * b.r, a.r);
	for (unsigned i = 0; i < intersection.size(); i++)
		intersection[i] = intersection[i] + a.center;

	return intersection;
}

struct Line
{
	ftype A, B, C;
};

vector <Point> getLineLineIntersection (Line i, Line j)
{
	ftype x = (j.B * i.C - j.C * i.B) / (j.A * i.B - i.A * j.B);
	ftype y = (j.A * i.C - j.C * i.A) / (j.B * i.A - i.B * j.A);

	vector <Point> answer;
	answer.push_back (Point (x, y));
	return answer;
}

vector <Point> getLineCircleIntersection (Line a, Circle b)
{
	a.C += a.A * b.center.x + a.B * b.center.y;
	vector <Point> answer = getLineCircleIntersection (a.A, a.B, a.C, b.r);
	for (unsigned i = 0; i < answer.size(); i++)
		answer[i] = answer[i] + b.center;
	return answer;
}

struct Object
{
	bool isCircle;

	Circle ifCircle;
	Line ifLine;

	vector <Point> getIntersection (const Object& o)
	{
		if (isCircle && o.isCircle)
			return getCircleCircleIntersection (o.ifCircle, ifCircle);
		else if (isCircle && !o.isCircle)
			return getLineCircleIntersection (o.ifLine, ifCircle);
		else if (!isCircle && o.isCircle)
			return getLineCircleIntersection (ifLine, o.ifCircle);
		else
			return getLineLineIntersection (ifLine, o.ifLine);
	}
};

Object buildTask (Circle a, Circle b)
{
	if (a.r == b.r)
	{
		Object line;
		line.isCircle = false;
		Point M = b.center - a.center;
		Point m = a.center + M * 0.5;
		line.ifLine.A = M.x;
		line.ifLine.B = M.y;
		line.ifLine.C = -m.x * M.x - m.y * M.y;
		return line;
	}
	else
	{
		Object circle;
		circle.isCircle = true;
		circle.ifCircle = buildAppolonius (a.center, b.center, a.r / b.r);
		return circle;
	}
}

const ftype offset = 200, scale = 2;

void pcircle (FILE* f, Circle c, const char* fill = "black")
{
	fprintf (f, "<circle cx=\"%Lg\" cy=\"%Lg\" r=\"%Lg\" fill=\"%s\" stroke=\"black\"/>\n", offset + c.center.x * scale, offset + c.center.y * scale, c.r * scale, fill);
}

ftype getAngle (Circle c, Point p)
{
	ftype r = c.r, d = (p - c.center).length();
	return 2 * atan2 (r, d) / M_PI * 180.0;
}

bool feq (ftype a, ftype b)
{
	return fabsl (a - b) <= 1e-5;
}

void pline (FILE* f, Line c)
{
	long double xmax = 1000;
	long double xmin = -1000;

	if (!feq (c.B, 0))
		fprintf (f, "<line x1=\"%Lg\" y1=\"%Lg\" x2=\"%Lg\" y2=\"%Lg\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/>\n", offset + xmin * scale, offset + (-c.C - c.A * xmin) / c.B * scale, offset + xmax * scale, offset + (-c.C - c.A * xmax) / c.B * scale);
	else
		fprintf (f, "<line y1=\"%Lg\" x1=\"%Lg\" y2=\"%Lg\" x2=\"%Lg\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/>\n", offset + xmin * scale, offset + (-c.C - c.B * xmin) / c.A * scale, offset + xmax * scale, offset + (-c.C - c.B * xmax) / c.A * scale);
}

int main()
{
	Circle a, b, c;

	a.read();
	b.read();
	c.read();

	Object ab = buildTask (a, b), ac = buildTask (a, c);

	/*FILE* vis = fopen ("vis.svg", "w");
	fprintf (vis, "<xml><svg version=\"1.1\" width=\"1000\" height=\"1000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
	pcircle (vis, a);
	pcircle (vis, b);
	pcircle (vis, c);

	if (ab.isCircle)
		pcircle (vis, ab.ifCircle, "transparent");
	else
		pline (vis, ab.ifLine);

	if (ac.isCircle)
		pcircle (vis, ac.ifCircle, "transparent");
	else
		pline (vis, ac.ifLine);

	Object bc = buildTask (b, c);

	if (bc.isCircle)
		pcircle (vis, bc.ifCircle, "transparent");
	else
		pline (vis, bc.ifLine);*/

	vector <Point> answer = ab.getIntersection (ac);

	ftype bestAngle = -1;
	Point bestAnswer;

	for (unsigned i = 0; i < answer.size(); i++)
	{
		Point t = answer[i];
		//printf ("Angles: %Lg %Lg %Lg\n", getAngle (a, t), getAngle (b, t), getAngle (c, t));
		//pcircle (vis, Circle (t, 0.5 / scale * 10));
		if (!feq (getAngle (a, t), getAngle (b, t)) || !feq (getAngle (b, t), getAngle (c, t)))
			continue;

		ftype angle = getAngle (a, t);

		if (angle > bestAngle)
		{
			bestAngle = angle;
			bestAnswer = t;
		}
	}

	if (bestAngle < 0)
	{
		//fprintf (vis, "</svg></xml>");
		//fclose (vis);
		return 0;
	}

	cout << fixed << setprecision (5) << bestAnswer.x << " " << bestAnswer.y << endl;

	//Point t = bestAnswer;


	//pcircle (vis, Circle (t, 0.5));
	//pcircle (vis, buildTask (b, c).ifCircle, "transparent");
	//fprintf (vis, "</svg></xml>");
	//fclose (vis);

	return 0;
}