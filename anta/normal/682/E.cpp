#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct P {
	typedef int T; typedef ll T2;	//T2{a*b | a:T, b:T}
	T x, y;
	P(T x_, T y_) : x(x_), y(y_) {}
	P() : x(0), y(0) {}
};
inline bool operator==(const P& a, const P& b) { return a.x == b.x && a.y == b.y; }
inline bool operator<(const P& a, const P& b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
inline P operator+(const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }
inline P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
inline P operator-=(P& a, const P& b) { a.x -= b.x, a.y -= b.y; return a; }
inline P::T2 cross(const P& a, const P& b) { return (P::T2)a.x*b.y - (P::T2)a.y*b.x; }
inline P::T2 dot(const P& a, const P& b) { return (P::T2)a.x*b.x + (P::T2)a.y*b.y; }
inline P::T2 norm(const P& a) { return (P::T2)a.x*a.x + (P::T2)a.y*a.y; }
ostream& operator<<(ostream& out, const P& x) { out << "(" << x.x << ", " << x.y << ")"; return out; }

inline int ccw(const P& a, const P& b, const P& c) {
	int ax = b.x - a.x, ay = b.y - a.y, bx = c.x - a.x, by = c.y - a.y;
	P::T2 t = (P::T2)ax*by - (P::T2)ay*bx;
	if(t > 0) return 1;
	if(t < 0) return -1;
	if((P::T2)ax*bx + (P::T2)ay*by < 0) return +2;
	if((P::T2)ax*ax + (P::T2)ay*ay < (P::T2)bx*bx + (P::T2)by*by) return -2;
	return 0;
}

vector<P> convex_hull(vector<P> ps) {
	if((int)ps.size() <= 1) return ps;
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	vector<P> ch(2 * n);
	for(int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
		while(k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) // upper-hull
		while(k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}

P::T2 triangleArea(const P &a, const P &b, const P &c) {
	return abs(cross(b - a, c - a));
}

vector<P> maximumAreaTriangle(const vector<P> &ch) {
	int n = (int)ch.size();
	if(n <= 2)
		return vector<P>();
	int A = 0, B = 1, C = 2;
	vector<P> res = { ch[A], ch[B], ch[C] };
	P::T2 best = triangleArea(ch[A], ch[B], ch[C]), cur = best, tmp;
	do {
		while(1) {
			while(cur <= (tmp = triangleArea(ch[A], ch[B], ch[(C + 1) % n])))
				(++ C) %= n, cur = tmp;
			if(cur <= (tmp = triangleArea(ch[A], ch[(B + 1) % n], ch[C]))) {
				(++ B) %= n, cur = tmp;
				continue;
			}
			break;
		}
		if(cur > best) {
			res[0] = ch[A], res[1] = ch[B], res[2] = ch[C];
			best = cur;
		}
		(++ A) %= n;
		if(A == B) (++ B) %= n;
		if(B == C) (++ C) %= n;
		cur = triangleArea(ch[A], ch[B], ch[C]);
	} while(A != 0);
	return res;
}

int main() {
	int n; long long S;
	while(~scanf("%d%lld", &n, &S)) {
		vector<P> points(n);
		rep(i, n) {
			int x; int y;
			scanf("%d%d", &x, &y);
			points[i] = P(x, y);
		}
		vector<P> ch = convex_hull(points);
		vector<P> tri = maximumAreaTriangle(ch);
		P a = tri[0] + tri[1] - tri[2];
		P b = tri[0] + tri[2] - tri[1];
		P c = tri[1] + tri[2] - tri[0];
		printf("%d %d\n", a.x, a.y);
		printf("%d %d\n", b.x, b.y);
		printf("%d %d\n", c.x, c.y);
	}
	return 0;
}