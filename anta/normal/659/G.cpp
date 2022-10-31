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

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;

vi h;

int calcL(int i) {
	assert(i + 1 < (int)h.size());
	return h[i] - (h[i] < h[i + 1] ? 1 : h[i] - h[i + 1] + 1);
}
int calcR(int i) {
	assert(i > 0);
	return h[i] - (h[i] < h[i - 1] ? 1 : h[i] - h[i - 1] + 1);
}
int calcLR(int i) {
	if(i == 0)
		return calcL(i);
	else if(i + 1 == h.size())
		return calcR(i);
	else
		return min(calcL(i), calcR(i));
}

mint rec(int i, int j) {
	if(i == j)
		return mint();
	int mid = i + (j - i) / 2;
	mint r;

	//mid only
	r += h[mid] - 1;

	//left only
	mint sumL, sumR;
	if(i < mid) {
		mint prod = 1, mul = calcR(mid);
		for(int k = mid - 1; k >= i; -- k) {
			mint cnt = prod * calcL(k);
			sumL += cnt;
			r += cnt * mul;
			prod *= calcLR(k);
		}
	}
	//right only
	if(mid < j - 1) {
		mint prod = 1, mul = calcL(mid);
		for(int k = mid + 1; k < j; ++ k) {
			mint cnt = prod * calcR(k);
			sumR += cnt;
			r += cnt * mul;
			prod *= calcLR(k);
		}
	}
	//left and right
	if(i < mid && mid < j - 1) {
		mint mul = calcLR(mid);
		r += sumL * sumR * mul;
	}

	r += rec(i, mid);
	r += rec(mid + 1, j);
	return r;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		h.resize(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &h[i]);
		mint ans = rec(0, n);
		printf("%d\n", ans.get());
	}
	return 0;
}