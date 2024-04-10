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

long long L, R;
int memo[65][2][2];

int rec(int i, bool gtl, bool ltr) {
	int &r = memo[i+1][gtl][ltr];
	if(r != -1) return r;
	if(i == -1) return r = 0;
	r = -INF;
	int bl = L >> i & 1, br = R >> i & 1;
	rep(b, 2) {
		if(!gtl && b < bl) continue;
		if(!ltr && br < b) continue;
		int t = rec(i-1, gtl || bl < b, ltr || b < br);
		if(t != -INF)
			amax(r, t + b);
	}
	return r;
}
long long rec_hukugen(int i, bool gtl, bool ltr) {
	if(i == -1) return 0;
	int r = rec(i, gtl, ltr);
	int bl = L >> i & 1, br = R >> i & 1;
	rep(b, 2) {
		if(!gtl && b < bl) continue;
		if(!ltr && br < b) continue;
		int t = rec(i-1, gtl || bl < b, ltr || b < br);
		if(t != -INF) {
			if(r == t + b) {
				return ((ll)b << i) | rec_hukugen(i-1, gtl || bl < b, ltr || b < br);
			}
		}
	}
	return -1;
}


int main() {
	int n;
	scanf("%d", &n);
	rep(ii, n) {
		cin >> L >> R;
		mset(memo, -1);
		rec(62, false, false);
		ll ans = rec_hukugen(62, false, false);
		cout << ans << endl;
	}
	return 0;
}