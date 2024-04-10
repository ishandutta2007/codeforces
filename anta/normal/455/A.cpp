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

template<typename T>
vector<pair<T,int> > runLength(const T a[], int n) {
	vector<pair<T,int> > r;
	if(n <= 0) return r;
	int cnt = 0;
	for(int i = 0; i <= n; i ++) {
		if(i == n || (i != 0 && a[i] != a[i-1])) {
			r.push_back(make_pair(a[i-1], cnt));
			cnt = 0;
		}
		cnt ++;
	}
	return r;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	sort(all(a));
	vpii as = runLength(&a[0], n);
	int m = as.size();
	//DPdp[i] = as[i]
	vector<long long> dp(m+1, -1);
	dp[0] = 0;
	rep(i, m) {
		long long x = dp[i];
		if(x == -1) continue;
		int t = as[i].first;
		long long s = (long long)t * as[i].second;
		int ni = i == m-1 || as[i+1].first != t+1 ? i+1 : i+2;
		//t
		amax(dp[ni], x + s);
		//t
		amax(dp[i+1], x);
	}
	long long ans = dp[m];
	cout << ans << endl;
	return 0;
}