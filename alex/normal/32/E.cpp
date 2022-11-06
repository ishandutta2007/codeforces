#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < double, double >
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second

pii p1, p2;
pair < pii, pii > st, st2, z;

bool prin(pii p1, pii p2, pii p)
{
	if (p1.x > p2.x) swap(p1.x, p2.x);
	if (p1.y > p2.y) swap(p1.y, p2.y);
	if (p1.x < p.x + 1e-7 && p2.x > p.x - 1e-7 && p1.y < p.y + 1e-7 && p2.y > p.y - 1e-7) return true;
	else return false;
}

pii cross_lines(double a1, double b1, double c1, double a2, double b2, double c2)
{
	pii res;
	res.y = -(a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
	res.x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
	return res;
}

bool cross(pii v1, pii v2, pii u1, pii u2, int zn)
{
	double a1 = v1.y - v2.y;
	double b1 = v2.x - v1.x;
	double c1 = - v1.y * v2.x + v2.y * v1.x;

	double a2 = u1.y - u2.y;
	double b2 = u2.x - u1.x;
	double c2 = - u1.y * u2.x + u2.y * u1.x;

	if (fabs(a1 * b2 - a2 * b1) < 1e-7)
	{
		if (fabs(a1 * c2 - a2 * c1) > 1e-7) return false;
		if (prin(u1, u2, v1) && zn == 0) return true;
		return false;
	}

	pii tmp = cross_lines(a1, b1, c1, a2, b2, c2);
	if (prin(v1, v2, tmp) && prin(u1, u2, tmp)) return true;
	else return false;
}

void answer(char *ans)
{
	cout << ans << endl;
	exit(0);
}

int zn(pii p1, pii p2, pii p)
{
	double a = p1.y - p2.y;
	double b = p2.x - p1.x;
	double c = - p1.y * p2.x + p2.y * p1.x;
	if (a * p.x + b * p.y + c > 1e-5) return 1;
	if (a * p.x + b * p.y + c < -1e-5) return -1;
	return 0;
}

pii sim(pii p1, pii p2, pii p)
{
	double a = p1.y - p2.y;
	double b = p2.x - p1.x;
	double c = - p1.y * p2.x + p2.y * p1.x;

	double aa = -b;
	double bb = a;
	double cc = - aa * p.x - bb * p.y;

	pii tmp = cross_lines(a, b, c, aa, bb, cc);
	p.x = 2 * tmp.x - p.x;
	p.y = 2 * tmp.y - p.y;
	return p;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cin >> st.fs.x >> st.fs.y >> st.sc.x >> st.sc.y;
	cin >> z.fs.x >> z.fs.y >> z.sc.x >> z.sc.y;

	if (!cross(st.fs, st.sc, p1, p2, 0))
	{
		if (!cross(z.fs, z.sc, p1, p2, 1)) answer("YES");
		else answer("NO");
	}
	if (zn(z.fs, z.sc, p1) * zn(z.fs, z.sc, p2) <= 0) answer("NO");

	p2 = sim(z.fs, z.sc, p2);
	st2.fs = sim(z.fs, z.sc, st.fs);
	st2.sc = sim(z.fs, z.sc, st.sc);
	if (cross(z.fs, z.sc, p1, p2, 1)
		&& !cross(st.fs, st.sc, p1, p2, 0) && !cross(st2.fs, st2.sc, p1, p2, 0)) answer("YES");
	else answer("NO");

	return 0;
}