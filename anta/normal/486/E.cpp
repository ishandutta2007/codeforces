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
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	vector<int> L(n), R(n);
	{	vector<int> dp(n, INF);
		for(int i = 0; i < n; ++ i) {
			int k = lower_bound(all(dp), a[i]) - dp.begin();
			L[i] = k + 1;
			dp[k] = a[i];
		}
	}
	{	vector<int> dp(n, INF);
		for(int i = n-1; i >= 0; -- i) {
			int k = lower_bound(all(dp), -a[i]) - dp.begin();
			R[i] = k + 1;
			dp[k] = -a[i];
		}
	}
	int lis = *max_element(all(L));
	vector<bool> v(n);
	rep(i, n)
		v[i] = L[i] + R[i] - 1 == lis;
	vector<int> cnt(n+1, 0);
	rep(i, n) if(v[i])
		++ cnt[L[i]];
	char *ans = new char[n+1];
	rep(i, n) {
		int x;
		if(!v[i])
			x = 1;
		else if(cnt[L[i]] > 1)
			x = 2;
		else
			x = 3;
		ans[i] = '0' + x;
	}
	ans[n] = 0;
	puts(ans);
	return 0;
}