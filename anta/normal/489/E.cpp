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

int main() {
	int n, l;
	scanf("%d%d", &n, &l);
	vector<int> x(n), b(n);
	rep(i, n) scanf("%d%d", &x[i], &b[i]);
	const int X = 2000000;
	vector<double> sqrts(X+1);
	rer(i, 0, X) sqrts[i] = sqrt(i * 1.);
	double lo = 0, up = sqrts[abs(x[n-1] - l)] / b[n-1] + 1;
	vector<int> lastprev;
	rep(ii, 100) {
		double mid = (lo + up) / 2;
		//_j |r_j-l| /  b_j <= mid
		//_j (|r_j-l| - mid b_j) <= 0
		vector<double> dp(n);
		vector<int> prev(n, -1);
		rep(i, n) dp[i] = sqrts[abs(x[i] - l)] - mid * b[i];
		rep(i, n) {
			double t = dp[i];
			reu(j, i+1, n) {
				double u = t + sqrts[abs(x[j] - x[i] - l)] - mid * b[j];
				if(dp[j] > u) {
					dp[j] = u;
					prev[j] = i;
				}
			}
		}
		if(dp[n-1] <= 0)
			up = mid, lastprev = prev;
		else
			lo = mid;
	}
	vector<int> ans;
	int i = n-1;
	while(i != -1) {
		ans.push_back(i);
		i = lastprev[i];
	}
	reverse(all(ans));
	rep(i, ans.size()) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	puts("");
//	cerr << "ans: "<< lo << endl;
	return 0;
}