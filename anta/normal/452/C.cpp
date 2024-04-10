#define _CRT_SECURE_NO_WARNINGS
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<typename T> T log1p(T x) {	//log1pglibc
	T u = 1.0 + x;
	if(u == 1.0) return x;
	else return log(u) * (x / (u - 1.0));
}
template<typename T> T logaddexp(T x, T y) {
	T z = x - y;
	if(z > 0.0) return x + log1p(exp(-z));
	else if(z == z) return y + log1p(exp(z));
	else return x + y;
}
template<typename T> T logsubexp(T x, T y) {
	T z = y - x;
	if(z <= 0.0) return x + log1p(-exp(z));
	else if(z == z) return -numeric_limits<T>::infinity();	//0
	else return x + y;
}
struct LogDomain {
	typedef long double T;
	T x;
	T get() const { return exp(x); }
	LogDomain(): x(-numeric_limits<T>::infinity()) { }
	LogDomain(T x_): x(log(x_)) { }
	static LogDomain fromlog(T x_) { LogDomain t; t.x = x_; return t; }
	LogDomain &operator*=(const LogDomain &that) { x += that.x; return *this; }
	LogDomain operator*(const LogDomain &that) const { return fromlog(x + that.x); }
	LogDomain &operator/=(const LogDomain &that) { x -= that.x; return *this; }
	LogDomain operator/(const LogDomain &that) const { return fromlog(x - that.x); }
	LogDomain operator^(const T &that) const { return fromlog(that == 0 ? T(0) : x * that); }
	LogDomain &operator+=(const LogDomain &that) { x = logaddexp(x, that.x); return *this; }
	LogDomain operator+(const LogDomain &that) const { return fromlog(logaddexp(x, that.x)); }
	LogDomain &operator-=(const LogDomain &that) { x = logsubexp(x, that.x); return *this; }
	LogDomain operator-(const LogDomain &that) const { return fromlog(logsubexp(x, that.x)); }
};
ostream &operator<<(ostream &o, LogDomain x) { return o << (double)x.get(); }

vector<LogDomain> fact;
void compute_fact(int n) {
	fact.assign(n+1, LogDomain());
	fact[0] = 1;
	rer(i, 1, n) fact[i] = fact[i-1] * i;
}
LogDomain comb(int n, int r) {
	return n < r ? 0 : fact[n] / fact[n-r] / fact[r];
}


int main() {
	//na a / n
	// = Sum_i (a_i / n)^2 = (Sum_i a_i^2) / n^2
	//
	int n, m;
	scanf("%d%d", &n, &m);
	compute_fact(n * m);
	double ans = 0;
	rer(a, 0, min(n, m)) {
		//()a
		//(C(m, a) * C(nm-m, n-a)) / C(nm, n)
		double p = (comb(m, a) * comb(n * m - m, n - a) / comb(n * m, n)).get();
		ans += p * (a * a * 1. / (n * n)) * n;
	}
	printf("%.10f\n", ans);
	return 0;
}