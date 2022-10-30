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
	char *s = new char[5002];
	scanf("%s", s);
	int n = strlen(s);
	vector<vector<int> > lcp(n+1, vector<int>(n+1, 0));
	for(int i = n-1; i >= 0; -- i) for(int j = n-1; j >= 0; -- j)
		lcp[i][j] = s[i] != s[j] ? 0 : lcp[i+1][j+1] + 1;
	vector<vector<mint> > dp(n+1, vector<mint>(n+1, 0));
	vector<vector<int> > dpb(n+1, vector<int>(n+1, INF));
	vector<vector<mint> > dpadd(n+1, vector<mint>(n+2, 0));
	vector<vector<int> > dpaddb(n+1, vector<int>(n+2, INF));
	rer(j, 1, n) {
		dp[0][j] = 1;
		dpb[0][j] = 1;
	}
	rer(i, 0, n) {
		mint sum = 0;
		int sumb = INF;
		rep(j, i+1) {
			sum += dpadd[i][j];
			amin(sumb, dpaddb[i][j]);
		}
		rer(j, i+1, n) {
			sum += dpadd[i][j];
			amin(sumb, dpaddb[i][j]);
			dp[i][j] += sum;
			amin(dpb[i][j], sumb);
			mint x = dp[i][j];
			int b = dpb[i][j];
			if(b == INF) continue;
			if(s[j] == '0') continue;
			int t = j - i, l = lcp[i][j];
			if(j + t > n) continue;
			if(l >= t || s[i + l] < s[j + l]) {
				dp[j][j + t] += x;
				amin(dpb[j][j + t], b + 1);
			}
			dpadd[j][j + t + 1] += x;
			amin(dpaddb[j][j + t + 1], b + 1);
		}
	}
	mint ans = 0;
	int minleni = -1; long long minlen = INFL;
	long long suf = 0, pow2 = 1, Lim = (ll)1e16;
	for(int i = n-1; i >= 0; -- i) {
		if(pow2 < Lim) {
			suf += pow2 * (s[i] - '0');
			pow2 *= 2;
		}else {
			suf = INFL;
		}
		ans += dp[i][n];
		if(dpb[i][n] != INF) {
			//TODO!!!!!
			long long len = suf == INFL ? INFL : suf + dpb[i][n];
			if(minleni == -1 || len < minlen) {
				minleni = i;
				minlen = len;
			}
		}
	}
	printf("%d\n", ans.get());
	mint len = 0;
	reu(i, minleni, n)
		len = len * 2 + (s[i] - '0');
	len += dpb[minleni][n];
//	cerr << "minlen: " << minlen << endl;
	printf("%d\n", len.get());
	return 0;
}