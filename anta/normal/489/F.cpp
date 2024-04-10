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

struct GModInt {
	static int Mod;
	int x;
	GModInt(): x(0) { }
	GModInt(signed sig) { if((x = sig % Mod + Mod) >= Mod) x -= Mod; }
	GModInt(signed long long sig) { if((x = sig % Mod + Mod) >= Mod) x -= Mod; }
	int get() const { return x; }
	
	GModInt &operator+=(GModInt that) { if((x += that.x) >= Mod) x -= Mod; return *this; }
	GModInt &operator-=(GModInt that) { if((x += Mod - that.x) >= Mod) x -= Mod; return *this; }
	GModInt &operator*=(GModInt that) { x = (unsigned long long)x * that.x % Mod; return *this; }
	GModInt &operator/=(GModInt that) { return *this *= that.inverse(); }
	
	GModInt operator+(GModInt that) const { return GModInt(*this) += that; }
	GModInt operator-(GModInt that) const { return GModInt(*this) -= that; }
	GModInt operator*(GModInt that) const { return GModInt(*this) *= that; }
	GModInt operator/(GModInt that) const { return GModInt(*this) /= that; }
	
	//Mod
	GModInt inverse() const {
		long long a = x, b = Mod, u = 1, v = 0;
		while(b) {
			long long t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		return GModInt(u);
	}
	
	bool operator==(GModInt that) const { return x == that.x; }
	bool operator!=(GModInt that) const { return x != that.x; }
	GModInt operator-() const { GModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
int GModInt::Mod = 0;
typedef GModInt mint;

int main() {
	/*
	rep(i, 1 << 9) {
		int a[9];
		rep(j, 9) a[j] = i >> j & 1;
		bool ok = true;
		rep(r, 3) ok &= a[r*3+0] + a[r*3+1] + a[r*3+2] == 2;
		rep(c, 3) ok &= a[0*3+c] + a[1*3+c] + a[2*3+c] == 2;
		if(ok) {
			rep(y, 3) {
				rep(x, 3) cerr << a[y*3+x];
				cerr << endl;
			}
			cerr << endl;
		}
	}
	*/
	int n, m, mod;
	scanf("%d%d%d", &n, &m, &mod);
	mint::Mod = mod;
	vector<char*> a(m);
	rep(i, m) a[i] = new char[n+1];
	rep(i, m) scanf("%s", a[i]);
	vector<int> colcnt(n, 0);
	rep(i, m) {
		int rowcnt = 0;
		rep(j, n) {
			int d = a[i][j] - '0';
			colcnt[j] += d;
			rowcnt += d;
		}
		if(rowcnt != 2) {
			puts("0");
			return 0;
		}
	}
	int cnt0 = count(all(colcnt), 0);
	int cnt1 = count(all(colcnt), 1);
	int cnt2 = count(all(colcnt), 2);
	if(cnt0 + cnt1 + cnt2 != n) {
		puts("0");
		return 0;
	}
	vector<vector<mint> > dp(n+1, vector<mint>(n+1, mint()));
	dp[cnt0][cnt1] = 1;
	reu(i, m, n) {
		for(int c0 = 0; c0 <= n; ++ c0) {
			for(int c1 = 0; c1 <= n-c0; ++ c1) {
				mint x = dp[c0][c1];
				dp[c0][c1] = 0;
				if(x.get() == 0) continue;
//				cerr << i << ", " << c0 << ", " << c1 << ": " << x.get() << endl;
				if(c0 >= 2) dp[c0-2][c1+2] += x * (c0 * (c0-1) / 2);
				if(c0 >= 1 && c1 >= 1) dp[c0-1][c1] += x * c0 * c1;
				if(c1 >= 2) dp[c0][c1-2] += x * (c1 * (c1-1) / 2);
			}
		}
	}
	mint ans = dp[0][0];
	printf("%d\n", ans.get());
	return 0;
}