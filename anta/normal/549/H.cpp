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

int main() {
	int a, b, c, d;
	while(cin >> a >> b >> c >> d) {
		double l = 0, u = 1e10;
		rep(ii, 100) {
			double mid = (l + u) / 2;
			double xmi = 1e99, xma = -1e99, ymi = 1e99, yma = -1e99;
			rer(p, -1, 1) rer(q, -1, 1) {
				double x = (a + p * mid) * (d + q * mid);
				double y = (b + p * mid) * (c + q * mid);
				amin(xmi, x);
				amin(ymi, y);
				amax(xma, x);
				amax(yma, y);
			}
			if(ymi <= xma && xmi <= yma)
				u = mid;
			else
				l = mid;
		}
		printf("%.10f\n", l);
	}
	return 0;
}