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
#include <functional>
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

template<typename Char, typename Index>
void buildKMPTable(const Char p[/*m*/], int m, Index fail[/*m+1*/]) {
	fail[0] = -1;
	for(int j = 0, t = -1; j < m; ) {
		while(t >= 0 && p[j] != p[t])
			t = fail[t];
		++ t, ++ j;
		fail[j] = j < m && p[j] == p[t] ? fail[t] : t;
	}
}

int main() {
	char *s = new char[100001], *t = new char[100001];
	scanf("%s", s);
	scanf("%s", t);
	int n = strlen(s), m = strlen(t);
	vector<int> fail(m+1);
	buildKMPTable(t, m, &fail[0]);
	vector<bool> found(n+1, false);
	for(int i = 0, k = 0; i < n; i ++) {
		while(k >= 0 && t[k] != s[i]) k = fail[k];
		if(++ k == m) {
			//s[i-m+1 .. i]
			found[i-m+1] = true;
			k = fail[k];
		}
	}
	vector<int> nextf(n+1, -1);
	for(int i = n-1; i >= 0; -- i)
		nextf[i] = found[i] ? i : nextf[i+1];
	vector<mint> dp(n+1, 0), dpadd(n+1, 0);
	mint add = 0;
	dp[0] = 1;
	rer(i, 0, n) {
		add += dpadd[i];
		dp[i] += add;
		if(i == n) break;
		mint x = dp[i];
		dp[i+1] += x;	//
		int j = nextf[i];
		if(j != -1)
			dpadd[j+m] += x;
	}
	mint ans = dp[n] - 1;
	printf("%d\n", ans.get());
	return 0;
}