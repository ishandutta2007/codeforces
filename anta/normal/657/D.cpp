#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <fstream>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<typename T>T gcd(T x, T y) { return y == 0 ? x : gcd(y, x%y); }

struct Ratio {
	typedef ll T;
	T x, y;
	Ratio() : x(0), y(1) {}
	Ratio(T x_) : x(x_), y(1) {}
	Ratio(T x_, T y_) : x(x_), y(y_) { normalize(); }

	void normalize() {
		T g = gcd(abs(x), abs(y));
		if(g == 0) return;
		x /= g; y /= g;
		if(y < 0) x = -x, y = -y;
		if(x == 0) y = 1;
	}
	bool operator==(const Ratio& q) const { return x == q.x && y == q.y; }
	bool operator!=(const Ratio& q) const { return x != q.x || y != q.y; }
	bool operator<(const Ratio& q) const { return x*q.y < y*q.x; }
	bool operator<=(const Ratio& q) const { return x*q.y <= y*q.x; }
	bool operator>(const Ratio& q) const { return x*q.y > y*q.x; }
	bool operator>=(const Ratio& q) const { return x*q.y >= y*q.x; }
};
ostream& operator<<(ostream &o, const Ratio& p) { o << p.x << "/" << p.y; return o; }

struct DynamicRMQ {
	typedef double Val;
	int n;
	vector<Val> d;
	void init(int nmin) {
		for(n = 1; n < nmin; n *= 2);
		d.assign(n * 2, 1e99);
	}
	void update(int i, Val x) {
		d[n + i] = x;
		for(int k = (n + i) / 2; k > 0; k >>= 1)
			d[k] = min(d[k * 2], d[k * 2 + 1]);
	}
	Val get(int i) const { return d[n + i]; }
	//[l, r)
	Val query(int l, int r) const {
		Val m = 1e99;
		for(; l && l + (l&-l) <= r; l += l&-l)
			m = min(m, d[(n + l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			m = min(m, d[(n + r) / (r&-r) - 1]);
		return m;
	}
};
int main() {
	int n;
	while(~scanf("%d", &n)) {
		vpii problems(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &problems[i].first);
		long long T = 0;
		for(int i = 0; i < n; ++ i) {
			scanf("%d", &problems[i].second);
			T += problems[i].second;
		}
		sort(all(problems));
		vector<pair<Ratio, int>> ord(n);
		rep(i, n)
			ord[i] = mp(Ratio(problems[i].first, problems[i].second), i);
		sort(all(ord)); reverse(all(ord));
		vector<double> minTime(n, -1);
		double l = 0, u = 1;
		rep(ii, 64) {
			double mid = (l + u) / 2;
			long long totalTime = 0;
			DynamicRMQ rmq;
			rmq.init(n);
			bool ok = true;
			for(int L = 0; L < n; ) {
				//p_i < p_j
				//p_i * (1 - c * x_i / T) > p_j * (1 - c * x_j / T)
				//c > (p_j - p_i) / (p_j * x_j / T - p_i * x_i / T)
				int R = L;
				long long startTime = totalTime;
				for(; R < n && ord[L].first == ord[R].first; ++ R) {
					int j = ord[R].second;
					minTime[j] = (startTime + problems[j].second) * 1. / T;
					int pi = problems[j].first;
					rmq.update(j, (mid * pi * minTime[j] - pi));
					totalTime += problems[j].second;
				}
				reu(k, L, R) {
					int j = ord[k].second;
					int pj = problems[j].first;
					double xj = totalTime * 1. / T;
					ok &= mid * pj * xj - pj <= rmq.query(0, lower_bound(all(problems), mp(pj, -1)) - problems.begin());
				}
				L = R;
			}
			if(ok)
				l = mid;
			else
				u = mid;
		}
		printf("%.10f\n", (l + u) / 2);
	}
	return 0;
}