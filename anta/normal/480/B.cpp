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

int main() {
	int n, l, x, y;
	scanf("%d%d%d%d", &n, &l, &x, &y);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	set<int> s(all(a));
	bool xok = false, yok = false;
	rep(i, n) {
		xok |= s.count(a[i] - x) || s.count(a[i] + x);
		yok |= s.count(a[i] - y) || s.count(a[i] + y);
	}
	if(xok && yok) {
		puts("0");
	}else if(!xok && yok) {
		puts("1");
		printf("%d\n", x);
	}else if(xok && !yok) {
		puts("1");
		printf("%d\n", y);
	}else {
		rep(i, n) {
			rep(xy, 2) rep(sign, 2) {
				int p = a[i] + (xy == 0 ? x : y) * (sign == 0 ? +1 : -1);
				if(!(0 <= p && p <= l)) continue;
				bool xx = xok, yy = yok;
				xx |= s.count(p - x) || s.count(p + x);
				yy |= s.count(p - y) || s.count(p + y);
				if(xx && yy) {
					puts("1");
					printf("%d\n", p);
					goto next;
				}
			}
		}
		if(0) {
next:;
		}else {
			puts("2");
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}