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
#include <bitset>
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

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt(): x(0) { }
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

int main() {
	int n, h;
	scanf("%d%d", &n, &h);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) a[i] = h - a[i];
	vector<int> diff(n+1);
	rep(i, n+1) diff[i] = (i == n ? 0 : a[i]) - (i == 0 ? 0 : a[i-1]);
//	rep(i, n+1) cerr << diff[i] << ", "; cerr << endl;

	vector<mint> dp[2];
	dp[0].assign(n+2, 0);
	dp[0][0] = 1;
	rep(i, n+1) {
		dp[i+1&1].assign(n+2, 0);
		rer(j, 0, i) {
			mint x = dp[i&1][j];
			if(x.get() == 0) continue;
//			cerr << i << ", " << j << ": " << x.get() << endl;
			if(diff[i] == 0) {
				if(j > 0)
					dp[i+1&1][j] += x * j;
				dp[i+1&1][j] += x;
			}else if(diff[i] == +1) {
				if(i < n)
					dp[i+1&1][j+1] += x;
			}else if(diff[i] == -1) {
				if(i > 0 && j > 0)
					dp[i+1&1][j-1] += x * j;
			}
		}
	}
	mint ans = dp[(n+1)&1][0];
	printf("%d\n", ans.get());
	return 0;
}