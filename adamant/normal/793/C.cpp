#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

double check(int r, int v, int a, int b, int mod)
{
	double A, B;
	if(v == 0)
	{
		if(a < r && r < b)
			A = 0, B = 1e9;
		else
			A = -1, B = -1;
	}
	else
	{
		A = 1. * (a - r) / v;
		B = 1. * (b - r) / v;
	}
	if(mod)
		return max(A, B);
	else
		return min(A, B);
}

const double eps = 1e-12;

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	double mn = 0, mx = 1e12;
	int x1, y1, x2, y2;
	if(x1 == x2 || y1 == y2)
	{
		cout << -1 << endl;
		return 0;
	}
	cin >> x1 >> y1 >> x2 >> y2;
	for(int i = 0; i < n; i++)
	{
		int rx, ry, vx, vy;
		cin >> rx >> ry >> vx >> vy;
		mn = max(mn, check(rx, vx, x1, x2, 0));
		mn = max(mn, check(ry, vy, y1, y2, 0));
		mx = min(mx, check(rx, vx, x1, x2, 1));
		mx = min(mx, check(ry, vy, y1, y2, 1));
	}
	if(mx - mn <= eps)
		cout << -1 << endl;
	else
		cout << fixed << setprecision(8) << mn << endl;
	return 0;
}