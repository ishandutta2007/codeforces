#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double
typedef double ftype;
typedef complex<double> point;
#define x real
#define y imag
ftype inf = 1e18, eps = 1e-9;

ftype dot(point a, point b)
{
	return (conj(a) * b).x();
}

ftype cross(point a, point b)
{
	return (conj(a) * b).y();
}

ftype get(point a, point b, point c)
{
	point dir = c - b;
	return abs(cross(a - b, c - b)) / abs(c - b) / 2;
	
}

signed main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int x, y;
	point r[n];
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		r[i] = {x, y};
	}
	ftype ans = inf;
	for(int i = 0; i < n; i++)
		ans = min(ans, get(r[i], r[(i + 1) % n], r[(i + n - 1) % n]));
	cout << fixed << setprecision(9) << ans << endl;
	return 0;
}