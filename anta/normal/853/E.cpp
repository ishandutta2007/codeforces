#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

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
	if (t > 0) return 1;
	if (t < 0) return -1;
	if ((P::T2)ax*bx + (P::T2)ay*by < 0) return +2;
	if ((P::T2)ax*ax + (P::T2)ay*ay < (P::T2)bx*bx + (P::T2)by*by) return -2;
	return 0;
}

vector<P> convex_hull(vector<P> ps) {
	if ((int)ps.size() <= 1) return ps;
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	vector<P> ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) // upper-hull
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}


struct FenwickTree {
	typedef ll T;
	vector<T> v;
	void init(int n) { v.assign(n, T()); }
	void add(int i, T x) {
		for (; i < (int)v.size(); i |= i + 1) v[i] += x;
	}
	T sum(int i) const {	//[0, i)
		T r = T();
		for (-- i; i >= 0; i = (i & (i + 1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) const {	//[left, right)
		return sum(right) - sum(left);
	}
};

#define all(o) (o).begin(), (o).end()

template<typename T, typename V>
void twoDimensionalSumQuery(vector<pair<pair<T, T>, V> > points, vector<pair<pair<T, T>, pair<V, int> > > queries, vector<V> &ans) {
	int n = points.size(), m = queries.size();
	vector<T> positions;
	rep(i, n) positions.push_back(points[i].first.second);
	sort(all(positions));
	positions.erase(unique(all(positions)), positions.end());
	int p = positions.size();
	FenwickTree t; t.init(p);
	sort(all(points)); sort(all(queries));
	int left = 0;
	rep(i, m) {
		T x = queries[i].first.first;
		while (left < n && points[left].first.first < x) {
			int j = lower_bound(all(positions), points[left].first.second) - positions.begin();
			t.add(j, points[left].second);
			left ++;
		}
		int y = lower_bound(all(positions), queries[i].first.second) - positions.begin();
		ans[queries[i].second.second] += t.sum(y) * queries[i].second.first;
	}
}

bool contains(const vector<P>& o, const P& p) {
	bool in = false;
	for (int i = 0; i < (int)o.size(); ++i) {
		P a = o[i] - p, b = o[(i + 1) % o.size()] - p;
		if (a.y > b.y) swap(a, b);
		if (a.y <= 0 && 0 < b.y)
			if (cross(a, b) < 0) in = !in;
		if (cross(a, b) == 0 && dot(a, b) <= 0) return true;	//point on edge
	}
	return in;
}

template<typename T, typename U>
inline auto floordiv(T x, U y) -> decltype(x / y) {
	auto q = x / y, r = x % y;
	return q - ((r != 0) & ((r<0) ^ (y<0)));
}
int main() {
	int K; int N; int Q;
	while (~scanf("%d%d%d", &K, &N, &Q)) {
		vector<P> poly = { P(0, 0) };
		rep(i, K) {
			int wx; int wy;
			scanf("%d%d", &wx, &wy);
			P w(wx, wy);
			vector<P> ps;
			for (auto p : poly) {
				ps.push_back(p + w);
				ps.push_back(p - w);
			}
			poly = convex_hull(ps);
		}
		if (poly.size() <= 2)continue;
		vector<pair<P, int>> points(N);
		rep(i, N) {
			int x; int y; int a;
			scanf("%d%d%d", &x, &y, &a);
			points[i] = { P(x,y),a };
		}
		vector<vector<pair<pair<ll, ll>, ll>>> qPoints(poly.size());
		rep(i, poly.size()) {
			auto from = poly[i], to = poly[(i + 1) % poly.size()];
			if (from.x == to.x) continue;
			int dx = abs(from.x - to.x), dy = to.y - from.y;
			int xL = from.x, xR = to.x, yL = from.y, yR = to.y;
			if (xL > xR) {
				dy = -dy;
				swap(xL, xR);
				swap(yL, yR);
			}
			for (auto pa : points) {
				auto p = pa.first;
				ll val = (ll)p.y * dx - (ll)p.x * dy;
				qPoints[i].emplace_back(make_pair(p.x, val), pa.second);
			}
		}
		int maxX = -INF;
		for (auto p : poly)
			amax(maxX, p.x);
		vector<vector<pair<pair<ll, ll>, pair<ll, int>>>> qQueries(poly.size());
		vector<pair<P, int>> naivequeries(Q);
		rep(qi, Q) {
			int ex; int ey; int t;
			scanf("%d%d%d", &ex, &ey, &t);
			P e(ex, ey);
			rep(i, poly.size()) {
				auto from = poly[i], to = poly[(i + 1) % poly.size()];
				if (from.x == to.x) continue;
				int dx = abs(from.x - to.x), dy = to.y - from.y;
				int sign = from.x > to.x ? 1 : -1;
				int xL = from.x, xR = to.x, yL = from.y, yR = to.y;
				if (xL > xR) {
					dy = -dy;
					swap(xL, xR);
					swap(yL, yR);
				}
				bool isMaxX = xR == maxX;
				xL = xL * t + ex;
				xR = xR * t + ex;
				yL = yL * t + ey;
				if (isMaxX) ++ xR;
				ll bound = (ll)yL * dx - (ll)xL * dy;
				if (sign == 1) ++ bound;
				qQueries[i].emplace_back(make_pair(xR, bound), make_pair(+sign, qi));
				qQueries[i].emplace_back(make_pair(xL, bound), make_pair(-sign, qi));
			}
			naivequeries[qi] = { e,t };
		}
		vector<ll> ans(Q, 0LL);
		rep(i, poly.size())
			twoDimensionalSumQuery(qPoints[i], qQueries[i], ans);
		for (int i = 0; i < (int)ans.size(); ++ i) {
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}