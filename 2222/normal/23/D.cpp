#include <iostream>
#include <complex>
#include <cstdio>

using namespace std;

typedef complex<double> point;

#define x	real()
#define y	imag()

double det(point a, point b) { return (conj(a) * b).y; }

bool solve(point a, point b, point c) {
	point	A = (a - b) * point(0, 1), 
			B = (a - c) * point(0, 1), 
			C = a - 0.5 * (b + c),
			D = 0.5 * (a + b) + A * (det(C, B) / det(A, B)),
			E = a + a - D,
			F = c + c - E,
			G = b + b - D;
	if (det(E - D, F - E) < 1e-7 ||
		det(F - E, G - F) < 1e-7 ||
		det(G - F, D - G) < 1e-7 ||
		det(D - G, E - D) < 1e-7) return false;
	printf("YES\n%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf\n", F.x, F.y, E.x, E.y, D.x, D.y, G.x, G.y);
	return true;
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	int T;
	for (cin >> T; T --> 0; ) {
		point a, b, c;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;		
		if (fabs(det(a - c, b - c)) < 1e-7 || 
			!solve(c, a, b) &&
			!solve(c, b, a) &&
			!solve(a, b, c) &&
			!solve(a, c, b) &&
			!solve(b, a, c) &&
			!solve(b, c, a))
				puts("NO\n");
	}
	return 0;
}