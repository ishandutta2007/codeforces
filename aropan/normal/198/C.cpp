#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

//const long double M_PI = 3.14159265358979323846;
const long double EPS = 1e-10;
const long double INF = 1e+30;

template <typename T> T sqr(T x) { return x * x; }

long double xp, yp, vp, R;
long double ll, rr, x, y, v, r;

vector < pair <long double, long double> > fs, sc;


long double make(long double x, long double y, vector < pair <long double, long double> > &v)
{
	v.clear();
	
	long double l = sqrt(sqr(x) + sqr(y));
	long double h = sqrt(sqr(l) - sqr(r));
	
	long double ang = acos(h / l);
	
	for (int i = -1; i <= 1; i += 2)
	{
		long double
			X = x + cos(ang * i) * (0 - x) - sin(ang * i) * (0 - y),
			Y = y + sin(ang * i) * (0 - x) + cos(ang * i) * (0 - y);
		long double
			dx = X - x,
			dy = Y - y;
		dx = dx / l * h;
		dy = dy / l * h;
		v.push_back(make_pair(x + dx, y + dy));
		//printf("%.3lf %.3lf\n", x + dx, y + dy);
	}
	//printf("%.3lf\n\n", h);
	return h;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	cin >> xp >> yp >> vp;
	cin >> x >> y >> v >> r;
	
	R = sqrt(sqr(xp) + sqr(yp));
	
	ll = 0;
	rr = 1e+10;
	for (int iter = 1000000; iter >= 0; iter--)
	{
		long double
			t = (ll + rr) / 2;
			
//		t = 9;
		
		long double angle = t / (2 * M_PI * R / vp) * 2 * M_PI;
		//angle = M_PI / 3;
		
		long double
			x1 = cos(angle) * xp - sin(angle) * yp,
			y1 = sin(angle) * xp + cos(angle) * yp,
			x2 = x,
			y2 = y;
//		printf("%.10lf %.10lf %.10lf\n", (double)x1, (double)y1, (double)sqrt(sqr(x1) + sqr(y1)));
//		return 0;
			
		long double
			A = y2 - y1,
			B = x1 - x2,
			C = -(x1 * A + y1 * B);
		long double
			l = sqrt(sqr(x1 - x2) + sqr(y1 - y2));
			
		long double		
			h = fabs((A * 0 + B * 0 + C) / sqrt(sqr(A) + sqr(B)));
			
		swap(B, A);
		B = -B;
		
		if ((A * x1 + B * y1) * (A * x2 + B * y2) > 0)
		{
			h = min(
				sqrt(sqr(x1) + sqr(y1)),
				sqrt(sqr(x2) + sqr(y2))
			);
		}
		
		//printf("%.3lf %.3lf %.3lf \n\n", h, x1, y1);
			
		if (h < r)
		{
			l = 0;
			l += make(x1, y1, fs);
			l += make(x2, y2, sc);
			
			long double d = INF;
			for (int i = 0; i < (int)fs.size(); i++)
				for (int j = 0; j < (int)sc.size(); j++)
					d = min(d, sqrt(sqr(fs[i].first - sc[j].first) + sqr(fs[i].second - sc[j].second)));
			l += asin(d / 2 / r) * 2 * r;
			//printf("%.3lf %.3lf\n", sqrt(sqr(x1 - x2) + sqr(y1 - y2)), d);
			//printf("%.3lf\n", asin(d / 2 / r) * 180 / M_PI);
		}
		
//		printf("%.3lf\n", l);
		
		if (l < t * v + EPS)
			rr = t;
		else
			ll = t;
			
		//break;
//		printf("%.9lf %.9lf\n", (long double)ll, (long double)rr);
	}
	printf("%.9lf\n", (double)rr);
	return 0;
}