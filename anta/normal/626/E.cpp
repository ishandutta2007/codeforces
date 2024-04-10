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
	double toDouble() { return double(x) / y; }
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
	Ratio& operator+=(const Ratio& q) {
		T g = gcd(y, q.y); x = q.y / g*x + y / g*q.x, y = y / g*q.y; normalize();
		return *this;
	}
	Ratio& operator-=(const Ratio& q) {
		T g = gcd(y, q.y); x = q.y / g*x - y / g*q.x, y = y / g*q.y; normalize();
		return *this;
	}
	Ratio& operator*=(const Ratio& q) {
		x = x*q.x, y = y*q.y; normalize();
		return *this;
	}
	Ratio& operator/=(const Ratio& q) {
		x = x*q.y, y = y*q.x; normalize();
		return *this;
	}
	Ratio operator+(const Ratio& q) const { return Ratio(*this) += q; }
	Ratio operator-(const Ratio& q) const { return Ratio(*this) -= q; }
	Ratio operator*(const Ratio& q) const { return Ratio(*this) *= q; }
	Ratio operator/(const Ratio& q) const { return Ratio(*this) /= q; }
	Ratio operator-() const { return Ratio(-x, y); }
};
ostream& operator<<(ostream &o, const Ratio& p) { o << p.x << "/" << p.y; return o; }

unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
//	while(1) {
//		n = rand() % 10 + 3;
		vector<int> x(n);
		for(int i = 0; i < n; ++ i) {
			scanf("%d", &x[i]);
//			x[i] = xor128() % 1000000 + 1;
		}
		//max. sum / (1+num*2)
		//sum - ans (1+num*2) >= 0
		sort(all(x));
		vector<ll> sum(n + 1);
		rep(i, n) sum[i + 1] = sum[i] + x[i];
		pair<Ratio, pii> ans(Ratio(), mp(0, 0));
		rep(i, n) {
			long double l = 0, u = 1e6;
			int li = -1;
			rep(ii, 100) {
				long double mid = (l + u) / 2;
				int t = min(i, n - 1 - i);
				int L = 0, U = t;
				while(U - L > 0) {
					int M = (L + U + 1) / 2;
					if(x[i - M] + x[n - M] >= mid * 2)
						L = M;
					else
						U = M - 1;
				}
				ll p = x[i];
				p += sum[i] - sum[i - L];
				p += sum[n] - sum[n - L];
				long double q = p - (2 * L + 1) * mid;
				if(q >= 0)
					l = mid, li = L;
				else
					u = mid;
			}
			for(int j = max(0, li - 10); j <= min({ i, n - 1 - i, li + 10 }); ++ j) {
				ll num = x[i];
				num += sum[i] - sum[i - j];
				num += sum[n] - sum[n - j];
				amax(ans, mp(Ratio(num, 2 * j + 1) - x[i], mp(i, j)));
			}
		}
		/*
		vector<pair<Ratio, pair<pii,int> > > v;
		rep(mid1, n) reu(mid2, mid1, n) {
			Ratio med = Ratio(x[mid1] + x[mid2], 2);
			Ratio num = med; int den = 1;
			rep(i, min(mid1, n - 1 - mid2)) {
				num += x[mid1 - 1 - i];
				num += x[n - 1 - i];
				den += 2;
				v.emplace_back(num / den - med, mp(mp(mid1, mid2), i + 1));
			}
		}
		v.emplace_back(mp(0, mp(mp(0, 0), 0)));
		sort(all(v)); reverse(all(v));
		if(v.front().first != ans.first || abs(v.front().second.first.first - v.front().second.first.second) > 0) {
			cerr << "ans = " << ans.first << endl;
			rep(i, n) cerr << x[i] << " "; cerr << endl;
			each(i, v) cerr << i->first << ": " << x[i->second.first.first] << ", " << x[i->second.first.second] << ", " << i->second.second << endl;
			cerr << endl;
		}*/

		vi ansv;
		ansv.push_back(x[ans.second.first]);
		rep(i, ans.second.second) {
			ansv.push_back(x[ans.second.first - i - 1]);
			ansv.push_back(x[n - 1 - i]);
		}
		sort(all(ansv));
		printf("%d\n", (int)ansv.size());
		for(int i = 0; i < (int)ansv.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ansv[i]);
		}
		puts("");
	}
	return 0;
}