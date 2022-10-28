#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n;
double x[N], y[N], z[N];

double sqr(double x1, double x2)
{
	return (x1 - x2) * (x1 - x2);
}

double get(double cX, double cY, double cZ)
{
	double r = 0;
	for(int i = 1; i <= n; i++)
	{
		double d = sqr(x[i], cX) + sqr(y[i], cY) + sqr(z[i], cZ);
		r = max(r, d);
	}
	return r;
}

double X, Y, Z;

double ternaryZ(double x, double y, double lo, double hi)
{
	for(int i = 1; i <= 100; i++)
	{
		double z1 = (lo * 2 + hi) / 3;
		double z2 = (lo + hi * 2) / 3;
		double val1 = get(x, y, z1);
		double val2 = get(x, y, z2);
		if(val1 <= val2)
			hi = z2;
		else
			lo = z1;
	}
	Z = lo;
	return get(x, y, lo);
}

double ternaryY(double x, double lo, double hi)
{
	for(int i = 1; i <= 70; i++)
	{
		double y1 = (lo * 2 + hi) / 3;
		double y2 = (lo + hi * 2) / 3;
		double val1 = ternaryZ(x, y1, -1e4, 1e4);
		double val2 = ternaryZ(x, y2, -1e4, 1e4);
		if(val1 <= val2)
			hi = y2;
		else
			lo = y1;
	}
	Y = lo;
	return ternaryZ(x, lo, -1e4, 1e4);
}


double ternaryX(double lo, double hi)
{
	for(int i = 1; i <= 60; i++)
	{
		double x1 = (lo * 2 + hi) / 3;
		double x2 = (lo + hi * 2) / 3;
		double val1 = ternaryY(x1, -1e4, 1e4);
		double val2 = ternaryY(x2, -1e4, 1e4);
		if(val1 <= val2)
			hi = x2;
		else
			lo = x1;
	}
	X = lo;
	return lo;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i] >> z[i];
	ternaryX(-1e4, 1e4);
	cout << fixed << setprecision(6) << X << " " << Y << " " << Z; 
	return 0;
}