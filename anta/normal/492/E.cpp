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

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

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
	
	GModInt inverse() const {
		long long a = x, b = Mod, u = 1, v = 0;
		while(b) {
			long long t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		return GModInt(u);
	}
	GModInt operator-() const { GModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
int GModInt::Mod = 0;
typedef GModInt mint;

int main() {
	int n, m, dx, dy;
	scanf("%d%d%d%d", &n, &m, &dx, &dy);
	mint::Mod = n;
	vector<int> x(m), y(m);
	rep(i, m)
		scanf("%d%d", &x[i], &y[i]);
	UnionFind uf; uf.init(m + n);
	//(y,x) + a(dy,dx)  (0,x')
	//-(y / dy)  a
	mint idy = mint(dy).inverse();
	rep(i, m) {
		mint a = -(idy * y[i]);
		mint xx = mint(x[i]) + a * dx;
		uf.unionSet(i, m + xx.get());
	}
	vector<int> cnt(m + n, 0);
	rep(i, m)
		++ cnt[uf.root(i)];
	int ans = 0, ansy = 0, ansx = 0;
	rep(i, m) {
		int t = cnt[uf.root(i)];
		if(ans < t)
			ans = t, ansy = y[i], ansx = x[i];
	}
//	cerr << "ans = " << ans << endl;
	printf("%d %d\n", ansx, ansy);
	return 0;
}