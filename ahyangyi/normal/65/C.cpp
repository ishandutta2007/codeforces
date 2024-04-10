#include <stdio.h>
#include <math.h>

const double eps = 1e-12;

int n;
double x[10001], y[10001], z[10001], t[10001];
double vp, vs;
double px, py, pz;

double dist (int i, int j)
{
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]));
}

void getRoot (double a, double b, double c, double t0, double* t1, double* t2)
{
	if (-1e-6 < a && a < 1e-6)
	{
		if (-eps < b && b < eps)
		{
			if (-eps < c && c < eps)
			{
				*t1 = *t2 = t0;
			}
			else
			{
				*t1 = *t2 = 1e100;
			}
		}
		else
			*t1 = *t2 = - c / b;
	}
	else
	{
		double delta = b*b - 4*a*c;
		
		if (delta > -eps)
		{
			if (delta < eps) delta = 0;

			*t1 = (-b + sqrt(delta)) / (2 * a);
			*t2 = (-b - sqrt(delta)) / (2 * a);

//			printf ("%lf %lf\n", *t1, *t2);
		}
		else
		{
			*t1 = *t2 = 1e100;
		}
	}
}

bool DEBUG = false;

int main ()
{
	scanf ("%d", &n);

//	if (n == 9990) DEBUG = true;

	for (int i = 0; i <= n; i ++)
		scanf ("%lf%lf%lf", x + i, y + i, z + i);
	
	scanf ("%lf%lf%lf%lf%lf", &vs, &vp, &px, &py, &pz);

//	printf ("%lf %lf %lf %lf %lf\n", vs, vp, px, py, pz);

	t[0] = 0;
	for (int i = 1; i <= n; i ++)
		t[i] = t[i - 1] + dist(i - 1, i) / vp;

	for (int i = 0; i < n; i ++)
	{
		/*
		pos = X[i] + (X[i + 1] - X[i]) * (T - t[i]) * vp / dist(i, i + 1)

		|pos - pxyz| = vs * T
		*/
		double xt, xx, yt, yy, zt, zz;

		xx = x[i] + (x[i + 1] - x[i]) * (-t[i]) * vp / dist(i, i + 1) - px;
		yy = y[i] + (y[i + 1] - y[i]) * (-t[i]) * vp / dist(i, i + 1) - py;
		zz = z[i] + (z[i + 1] - z[i]) * (-t[i]) * vp / dist(i, i + 1) - pz;
		xt = (x[i + 1] - x[i]) * vp / dist(i, i + 1);
		yt = (y[i + 1] - y[i]) * vp / dist(i, i + 1);
		zt = (z[i + 1] - z[i]) * vp / dist(i, i + 1);

		if (DEBUG && 1.7320508 < t[i + 1])
		{
			printf ("%.3lf %.3lf %.3lf\n", x[i], y[i], z[i]);
			printf ("%.4lf %.4lf: %.4lf %.4lf %.4lf %.4lf %.4lf %.4lf\n", t[i], t[i + 1], xx, xt, yy, yt, zz, zt);
		}

		double a, b, c;

		a = xt * xt + yt * yt + zt * zt - vs * vs;
		b = 2 * (xt * xx + yt * yy + zt * zz);
		c = xx * xx + yy * yy + zz * zz;
		/*
		|xx + xt * t, yy + yt * t, zz + zt * t|
		= 
		xt^2 + yt^2 + zt^2    t^2
		2xxxt + 2yyyt + 
		*/

		if (DEBUG && 1.7320508 < t[i + 1])
			printf ("%.14lf %lf %lf -- %lf\n", a, b, c, b*b-4*a*c);

		double t1, t2;

		getRoot(a,b,c, t[i], &t1, &t2);

		if (DEBUG && 1.7320508 < t[i + 1])
			printf ("%lf %lf\n", t1, t2);

		if (t1 > t2)
		{
			double tt = t1; t1 = t2; t2 = tt;
		}

		if (t[i] - eps < t1 && t1 < t[i + 1] + eps)
		{
			printf ("YES\n");
			printf ("%.10lf\n%.10lf %.10lf %.10lf\n", t1, xx + t1 * xt + px, yy + t1 * yt + py, zz + t1 * zt + pz);
			return 0;
		}
		if (t[i] - eps < t2 && t2 < t[i + 1] + eps)
		{
			printf ("YES\n");
			printf ("%.10lf\n%.10lf %.10lf %.10lf\n", t2, xx + t2 * xt + px, yy + t2 * yt + py, zz + t2 * zt + pz);
			return 0;
		}
	}

	printf ("NO\n");

	return 0;
}