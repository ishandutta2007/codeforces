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
	int n, w;
	scanf("%d%d", &n, &w);
	vector<int> a(n), b(w);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, w) scanf("%d", &b[i]);
	if(w == 1) {
		printf("%d\n", n);
		return 0;
	}
	vector<int> c(n-1), d(w-1);
	rep(i, n-1) c[i] = a[i+1] - a[i];
	rep(i, w-1) d[i] = b[i+1] - b[i];
	vector<int> fail(w);
	fail[0] = -1;
	for(int i = 1, j = -1; i <= w - 1; i ++) {
		while(j >= 0 && d[j] != d[i-1]) j = fail[j];
		fail[i] = ++ j;
	}
	int ans = 0;
	for(int i = 0, k = 0; i < n - 1; i ++) {
		while(k >= 0 && d[k] != c[i]) k = fail[k];
		if(++ k == w - 1) {
			ans ++;	//s[i-m+1 .. i]
			k = fail[k];
		}
	}
	printf("%d\n", ans);
	return 0;
}