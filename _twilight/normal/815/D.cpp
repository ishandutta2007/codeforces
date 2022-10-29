#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 5e5 + 5;

typedef class Point {
	public:
		int x, y;

		Point() {	}
		Point(int x, int y) : x(x), y(y) {	}
} Point;

int n, X, Y, Z;
int xs[N], ys[N], zs[N];
Point xy[N], xz[N], yz[N], yx[N], zx[N], zy[N];

ll ans = 0;
vector<Point> solve1(Point* S, int R, int coef) {
	vector<Point> rt;
	ll tmp = 0;
	rt.emplace_back(R + 1, 0);
	sort(S + 1, S + n + 1, [&] (const Point& a, const Point& b) {
			return (a.x ^ b.x) ? (a.x > b.x) : (a.y > b.y);	
		});
	for (int i = 1; i <= n; i++) {
		if (S[i].y > rt.back().y) {
			tmp += (rt.back().x - S[i].x) * 1ll * rt.back().y;
			rt.push_back(S[i]);
		}
	}
	tmp += rt.back().x * 1ll * rt.back().y;
	if (coef)
		ans += tmp * coef;
	reverse(rt.begin(), rt.end());
	return rt;
}

ll solve2(const vector<Point>& S1, const vector<Point>& S2, int R) {
	int p1 = 0, p2 = 0;
	ll ret = 0;
	for (int i = 1; i <= R; i++) {
		while (i > S1[p1].x)
			p1++;
		while (i > S2[p2].x)
			p2++;
		ret += S1[p1].y * 1ll * S2[p2].y;
	}
	return ret;
}

int Yr[N], Zr[N];
ll solve3(const vector<Point>& S1, const vector<Point>& S2, const vector<Point>& S3, const vector<Point>& S4) {
	ll S = 0, ret = 0;
	int yr = Y, zr = Z;
	for (int i = 1, p = 0; i <= Y; i++) {
		while (i > S3[p].x)
			p++;
		Yr[i] = S3[p].y;
	}
	for (int i = 1, p = 0; i <= Z; i++) {
		while (i > S4[p].x)
			p++;
		Zr[i] = S4[p].y;
		S += Zr[i];
	}
	for (int i = 1, p1 = 0, p2 = 0; i <= X; i++) {
		while (i > S1[p1].x)
			p1++;
		while (i > S2[p2].x)
			p2++;
		while (yr > S1[p1].y)
			S -= min(Yr[yr--], zr);
		while (zr > S2[p2].y)
			S -= min(Zr[zr--], yr);
		ret += S;
	}
	return ret;
}

int main() {
	scanf("%d%d%d%d", &n, &X, &Y, &Z);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", xs + i, ys + i, zs + i);
		xy[i] = Point(xs[i], ys[i]);
		xz[i] = Point(xs[i], zs[i]);
		yx[i] = Point(ys[i], xs[i]);
		yz[i] = Point(ys[i], zs[i]);
		zx[i] = Point(zs[i], xs[i]);
		zy[i] = Point(zs[i], ys[i]);
	}
	vector<Point> vxy = solve1(xy, X, Z);
	vector<Point> vyx = solve1(yx, Y, 0);
	vector<Point> vxz = solve1(xz, X, Y);
	vector<Point> vzx = solve1(zx, Z, 0);
	vector<Point> vyz = solve1(yz, Y, X);
	vector<Point> vzy = solve1(zy, Z, 0);
	ans -= solve2(vxy, vxz, X);
	ans -= solve2(vyx, vyz, Y);
	ans -= solve2(vzx, vzy, Z);
	ans += solve3(vxy, vxz, vyz, vzy);
	cout << 1ll * X * Y * Z - ans << '\n';
	return 0;
}