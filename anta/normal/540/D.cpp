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

int kk;
double memo[101][101][101];
double rec(int x[3]) {
	double &r = memo[x[0]][x[1]][x[2]];
	if(r == r) return r;
	r = 0;
	int sum = x[0] + x[1] + x[2];
	rep(i, 3) if(x[i] == sum)
		return r = i == kk ? 1 : 0;
	double pairs = 1. / (x[0] * x[1] + x[1] * x[2] + x[2] * x[0]);
	rep(i, 3) if(x[i] > 0 && x[(i+1)%3] > 0) {
		double p = (x[i] * x[(i+1)%3]) * pairs;
		-- x[(i+1)%3];
		r += p * rec(x);
		++ x[(i+1)%3];
	}
	return r;
}

int main() {
	int r, s, p;
	cin >> r >> s >> p;
	int x[3] = { r, s, p };
	rep(k, 3) {
		if(k != 0) putchar(' ');
		kk = k;
		mset(memo, -1);
		double a = rec(x);
		printf("%.10f", a);
	}
	puts("");
	return 0;
}