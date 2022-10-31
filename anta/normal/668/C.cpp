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

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<double> ma(n + 2), mi(n + 2);
		rep(i, n)
			scanf("%lf", &ma[i + 1]);
		rep(i, n)
			scanf("%lf", &mi[i + 1]);
		//P[a <  i && b <  i] = P[a < i] P[b < i]
		//P[a >= i && b >= i] = (1 - P[a < i]) (1 - P[b < i])
		//                    = 1 - P[b < i] - P[a < i] + P[a < i] P[b < i]
		//P[a < i] + P[b < i]
		//P[a = i] + P[b = i]
		//P[a <= i && b <= i] = P[a < i] P[b < i] + P[a < i] P[b = i] + P[a = i] P[b < i] + P[a = i] P[b = i]
		vector<double> lt(n + 2), ge(n + 2);
		rer(i, 0, n)
			lt[i + 1] = lt[i] + ma[i];
		for(int i = n; i >= 0; -- i)
			ge[i] = ge[i + 1] + mi[i];
		vector<double> sumlt(n + 2);
		rer(i, 0, n + 1)
			sumlt[i] = 1 - (ge[i] - lt[i]);
		vector<double> sum2(n + 2);
		rer(i, 0, n)
			sum2[i] = sumlt[i + 1] - sumlt[i];
		vector<double> p1(n + 1), p2(n + 1);
		double suma = 0, sumb = 0;
		rer(i, 1, n) {
			double a = sumb, b = suma;
			double t = ma[i];
			double u = sum2[i];
			//ax + by + xy = t, x + y = u
			double x = 1. / 2 * abs(sqrt(max(0., a*a - 2 * a*b + 2 * a*u + b*b + 2 * b*u - 4 * t + u*u)) + a - b + u);
			double y = u - x;
			p1[i] = x, p2[i] = y;
			suma += p1[i], sumb += p2[i];
		}
		rer(i, 1, n) {
			if(i != 1) putchar(' ');
			printf("%.10f", p1[i]);
		}
		puts("");
		rer(i, 1, n) {
			if(i != 1) putchar(' ');
			printf("%.10f", p2[i]);
		}
		puts("");
	}
	return 0;
}