#include <bits/stdc++.h>

using namespace std;

typedef complex<double> point;
typedef pair<point, point> linear;
#define X real()
#define Y imag()
#define k first
#define b second

point apply(linear f, point x)
{
	return f.k * x + f.b;
}

linear combine(linear f, linear g)
{
	return {f.k * g.k, f.k * g.b + f.b};
}

const int maxn = 3e5 + 42;

linear F[4 * maxn];

void upd(int p, linear f, int v = 1, int l = 0, int r = maxn)
{
	if(r - l == 1)
	{
		F[v] = combine(f, F[v]);
		return;
	}
	int m = (l + r) / 2;
	if(p < m)
		upd(p, f, 2 * v, l, m);
	else
		upd(p, f, 2 * v + 1, m, r);
	F[v] = combine(F[2 * v], F[2 * v + 1]);
}

linear get(int a, int b, int v = 1, int l = 0, int r = maxn)
{
	if(a <= l && r <= b)
		return F[v];
	if(r <= a || b <= l)
		return {1, 0};
	int m = (l + r) / 2;
	return combine(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(F, F + 4 * maxn, linear{1, 0});
	int n, m;
	cin >> n >> m;
	const double PI = 4 * atan(1);
	while(m--)
	{
		int t, p, c;
		cin >> t >> p >> c;
		linear f;
		double phi = c / 360. * 2 * PI;
		if(t == 1)
		{
			f.k = 1;
			f.b =  point(c) * get(p - 1, p).k * point(1, 0);
		}
		if(t == 2)
		{
			f.k = polar(1., -phi);
			f.b = (1. - f.k) * point(p - 1, 0);
		}
		upd(p - 1, f);
		point ans = apply(get(0, n), point(n, 0));
		cout << ans.X << ' ' << ans.Y << "\n";
	}
	return 0;
}