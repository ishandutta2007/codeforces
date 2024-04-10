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
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }


struct SaturationInt {
	typedef long long T; typedef double Float;
	static T Max;
	T x;
	static inline T sat(T x) { return x > Max ? Max : x; }
	SaturationInt() { }
	SaturationInt(T x_): x(sat(x_)) { }
	T get() const { return x; }

	SaturationInt operator+(const SaturationInt &that) const {
		return SaturationInt(x + that.x);
	}
	SaturationInt operator*(const SaturationInt &that) const {
		return SaturationInt((Float)x * that.x > Max ? Max : x * that.x);
	}
	SaturationInt &operator+=(const SaturationInt &that) { return *this = *this + that; }
	SaturationInt &operator*=(const SaturationInt &that) { return *this = *this * that; }

	SaturationInt operator^(long long k) const {
		long long r = 1, a = x;
		while(k) {
			if(k & 1) r *= a;
			if(k >>= 1) {
				if((Float)a * a * r > Max) return SaturationInt(Max);
				a *= a;
			}
		}
		return SaturationInt(r);
	}
};
SaturationInt::T SaturationInt::Max = INFL;
typedef SaturationInt sint;

int n;
vector<int> ans;
sint memo[51];
sint rec(int i) {
	sint &r = memo[i];
	if(r.x != -1) return r;
	if(i == n) return r = 1;
	r = 0;
	if(ans[i] == -1 || ans[i] == i)
		r += rec(i+1);
	if(i+2 <= n) {
		if((ans[i] == -1 || ans[i] == i+1) && (ans[i+1] == -1 || ans[i+1] == i))
			r += rec(i+2);
	}
	return r;
}

int main() {
	long long l;
	while(cin >> n >> l) {
		-- l;
		ans.assign(n, -1);
		vector<bool> vis(n, false);
		rep(i, n) {
			rep(j, n) if(!vis[j]) {
				ans[i] = j;
				mset(memo, -1);
				sint s = rec(0);
				if(s.get() <= l) {
					l -= s.get();
				}else {
					vis[j] = true;
					break;
				}
			}
		}
		rep(i, n) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}