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
	typedef int T; typedef ll T2;	//T2{a*b | a:T, b:T}^Cv
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

int main() {
	char v[500][501];
	int N;
	while(~scanf("%d", &N) && N != 0) {
		rep(i, N)
			scanf("%s", v[i]);
		vector<vi> cnt(N + 1, vi(N + 1));
		rep(i, N) rep(j, N)
			cnt[i][j] = v[i][j] - '0';
		vector<vi> sum1(N + 1, vi(N + 1));
		rep(i, N + 1) for(int j = N - 1; j >= 0; -- j)
			sum1[i][j] = cnt[i][j] - sum1[i][j + 1];
		vector<vi> point(N + 1, vi(N + 1));
		for(int i = N - 1; i >= 0; -- i) rep(j, N + 1)
			point[i][j] = sum1[i][j] - point[i + 1][j];
		vector<P> points;
		rep(i, N + 1) rep(j, N + 1) if(point[i][j] > 0)
			points.emplace_back(j, N - i);
		vector<P> ch = convex_hull(points);
		reverse(ch.begin(), ch.end());
		rotate(ch.begin(), min_element(ch.begin(), ch.end()), ch.end());
		printf("%d\n", (int)ch.size());
		rep(i, ch.size())
			printf("%d %d\n", ch[i].x, ch[i].y);
	}
	return 0;
}