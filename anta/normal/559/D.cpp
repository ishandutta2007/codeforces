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

template<typename T>T gcd(T x, T y){if(y==0)return x;else return gcd(y,x%y);}
unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> x(n*2), y(n*2);
		rep(i, n) scanf("%d%d", &x[i], &y[i]);
		rep(i, n) x[n+i] = x[i], y[n+i] = y[i];
		vector<long double> nondegdp(4);
		nondegdp[0] = 1;
		rep(i, n) {
			for(int j = 3; j >= 0; -- j) {
				long double x = nondegdp[j];
				if(x < 1e-99) continue;
				nondegdp[j] = x / 2;
				nondegdp[min(3, j+1)] += x / 2;
			}
		}
		long double t = 0;
		rep(i, n) {
			long double p = 1. / 4, q = pow(2., -n);
			if(q < 1e-99) q = 0;
			reu(j, 1, n) {
				if(p < 1e-30) break;
				int w = x[i+j] - x[i], h = y[i+j] - y[i];
				int g = gcd(abs(w), abs(h));
				ll a = -(ll)(y[i] + y[i+j]) * w;
				t += (p - q) * (a - g);
				p *= 0.5;
			}
		}
//		cerr << "b = " << b << ", A = " << A << "; " << nondegdp[3] << endl;
		//A - b/2 + 1 = i
		double ans = t / 2 / nondegdp[3] + 1;
		printf("%.10f\n", ans);
	}
	return 0;
}