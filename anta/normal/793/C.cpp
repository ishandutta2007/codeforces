#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct Ratio {
	int num, den;
	Ratio() : num(0), den(1) {}
	Ratio(int x, int y) : num(x), den(y) { if (den < 0 || (den == 0 && num < 0)) num = -num, den = -den; }
	bool operator<(const Ratio &that) const { return (ll)num * that.den < (ll)that.num * den; }
	bool operator==(const Ratio &that) const { return (ll)num * that.den == (ll)that.num * den; }
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		int x1; int y1; int x2; int y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int w = x2 - x1, h = y2 - y1;
		Ratio L(0, 1), U(1, 0);
		rep(i, n) {
			int x0; int y0; int vx; int vy;
			scanf("%d%d%d%d", &x0, &y0, &vx, &vy);
			x0 -= x1, y0 -= y1;
			rep(xy, 2) {
				//0 < x + v t < w
				//-x / v < t < (w - x) / v
				Ratio a(-x0, vx), b(w - x0, vx);
				if (vx > 0) {
					amax(L, a);
					amin(U, b);
				} else if (vx < 0) {
					amax(L, b);
					amin(U, a);
				} else {
					if (!(0 < x0 && x0 < w))
						amin(U, Ratio(0, 1));
				}
				swap(x0, y0);
				swap(vx, vy);
				swap(w, h);
			}
		}
		if (!(L < U)) {
			puts("-1");
		} else {
			double ans = L.num * 1. / L.den;
			printf("%.10f\n", ans);
		}
	}
	return 0;
}