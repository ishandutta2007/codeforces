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
#include <unordered_map>
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

template<typename T, size_t WW>
void rotate_left_square(T a[][WW], int n) {
	int n1 = n / 2, n2 = n - n1;
	rep(j, n1) rep(i, n2) {
		//a[j][i], a[n-1-i][j], a[n-1-j][n-1-i], a[i][n-1-j]
		T t = a[i][n-1-j];
		a[i][n-1-j] = a[n-1-j][n-1-i];
		a[n-1-j][n-1-i] = a[n-1-i][j];
		a[n-1-i][j] = a[j][i];
		a[j][i] = t;
	}
}
template<typename T, size_t WW>
void rotate_left(T a[][WW], int H, int W) {
	rotate_left_square(a, max(H, W));
	int pad = max(0, H - W);
	if(pad > 0) {
		for(int i = 0; i < W; i ++)
			memcpy(a[i], a[i+pad], H * sizeof(**a));
	}
}

char s[400][400];
int n, m;

struct Cumsum {
	typedef char Val;
	static const int ValBase = '0';
	typedef short Sum;
	Sum sum[400][400];
	int dy, dx;
	int n, m;
	Cumsum(int dy_, int dx_): dy(dy_), dx(dx_), n(0), m(0) { }
	void init(Val a[400][400], int n_, int m_) {
		n = n_, m = m_;
		rep(i, n) rep(j, m) {
			int yy = i - dy, xx = j - dx;
			Sum t = a[i][j] - ValBase;
			if(0 <= yy && yy < n && 0 <= xx && xx < m)
				t += sum[yy][xx];
			sum[i][j] = t;
		}
	}
	Sum get(int y1, int x1, int y2, int x2) {
		Sum res = sum[y2][x2];
		int yy = y1 - dy, xx = x1 - dx;
		if(0 <= yy && yy < n && 0 <= xx && xx < m)
			res -= sum[yy][xx];
		return res;
	}
} sumh(0, 1), sumv(1, 0), sumd1(1, 1), sumd2(1, -1);

int main() {
	scanf("%d%d", &n, &m);
	rep(i, n)
		scanf("%s", s[i]);
	int ans = 0;
	rep(rot, 4) {
//		rep(i, n) { rep(j, m) cerr << s[i][j]; cerr << endl; }

		sumh.init(s, n, m);
		sumv.init(s, n, m);
		sumd1.init(s, n, m);
		sumd2.init(s, n, m);

		//
		rep(i, n) {
			int maxk = min(m, i * 2);
			for(int k = 2; k <= maxk; k += 2) rep(j, m - k) {
				//(y1,x1)--(y2,x2)
				int y1 = i, x1 = j;
				int y2 = i, x2 = j + k;
				int y3 = i - k / 2, x3 = j + k / 2;
				bool ok = true;
				ok &= sumh.get(y1, x1, y2, x2) == 0;
				ok &= sumd1.get(y3, x3, y2, x2) == 0;
				ok &= sumd2.get(y3, x3, y1, x1) == 0;
				ans += ok;
//				if(ok) cerr << y1 << ", " << x1 << ", "<< y2 << ", " << x2 << ", " << y3 << ", " << x3 << endl;
			}
		}
//		cerr << ";" << endl;
//		cerr << ans << endl;
		//
		rep(i, n) {
			int maxk = min(i, m);
			for(int k = 1; k <= maxk; k += 1) rep(j, m - k) {
				//(y1,x1)--(y2,x2)
				int y1 = i, x1 = j;
				int y2 = i, x2 = j + k;
				int y3 = i - k, x3 = j;
				bool ok = true;
				ok &= sumh.get(y1, x1, y2, x2) == 0;
				ok &= sumv.get(y3, x3, y1, x1) == 0;
				ok &= sumd1.get(y3, x3, y2, x2) == 0;
				ans += ok;
//				if(ok) cerr << y1 << ", " << x1 << ", "<< y2 << ", " << x2 << ", " << y3 << ", " << x3 << endl;
			}
		}
//		cerr << ans << endl;

		rotate_left(s, n, m);
		swap(n, m);
	}
	printf("%d\n", ans);
	return 0;
}