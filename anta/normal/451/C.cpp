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

bool solve2(long long n3, long long a, long long b, long long c) {
	if(a < 0 || b < 0 || c < 0) return false;
	long long total = a + b + c, rem = 3 * n3 - total;
	//rema,b,cn3
	if(a > n3 || b > n3 || c > n3) return false;
	long long aa = n3 - a, bb = n3 - b, cc = n3 - c;
	if(aa + bb + cc != rem) cerr << "ERR 2" << endl;
	return aa + bb + cc == rem;
}

bool solve(long long n3, long long k, long long a, long long b) {
	//    x + (x+a) + (x+b) = k
	//<-> x = (k - a - b) / 3
	long long kab = k - a - b;
	if(kab % 3 != 0) return false;
	long long x = kab / 3;
	if(3 * n3 - (3*x + a + b) != 3*n3 - k) cerr << "ERR" << endl;
	return solve2(n3, x, x+a, x+b);
}

int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		long long n, k, d1, d2;
		scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
		const char *no = "no";
		if(n % 3 != 0) {
			puts(no);
			continue;
		}
		long long n3 = n / 3;
		bool ans = false;
		ans |= solve(n3, k, +d1, +d1+d2);
		ans |= solve(n3, k, -d1, -d1+d2);
		ans |= solve(n3, k, +d1, +d1-d2);
		ans |= solve(n3, k, -d1, -d1-d2);
		puts(ans ? "yes" : "no");
	}
	return 0;
}