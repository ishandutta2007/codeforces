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
#include <bitset>
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
	char *s = new char[2001], *p = new char[501];
	scanf("%s", s);
	scanf("%s", p);
	int n = strlen(s), m = strlen(p);
	vector<vector<int> > dpmin(n+1, vector<int>(n+1, INF));
	vector<vector<int> > dpmax(n+1, vector<int>(n+1, -1));
	dpmin[0][0] = 0;
	dpmax[0][0] = 0;
	rep(i, n) {
		rep(j, i+1) {
			int x = dpmin[i][j];
			if(x == INF) continue;
			char c = p[j % m];
			if(s[i] == c)
				amin(dpmin[i+1][j+1], x);
			amin(dpmin[i+1][j], x + (j % m == 0 ? 0 : 1));
		}
		rep(j, i+1) {
			int x = dpmax[i][j];
			if(x == -1) continue;
			char c = p[j % m];
			if(s[i] == c)
				amax(dpmax[i+1][j+1], x);
			amax(dpmax[i+1][j], x + 1);
		}
	}
	vector<int> ans(n+1, 0);
	rep(j, n+1) if(j % m == 0)
		rer(k, dpmin[n][j], dpmax[n][j])
			amax(ans[k], j / m);
	rep(i, n+1) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}