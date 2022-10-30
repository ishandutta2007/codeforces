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
	const int X = 1000000;
	vector<bool> b(X+1, false);
	rep(i, n) {
		int a;
		scanf("%d", &a);
		b[a] = true;
	}
	vector<int> left(X+1);
	left[0] = -1;
	for(int i = 1; i <= X; ++ i)
		left[i] = b[i] ? i : left[i-1];
	int ans = 0;
	for(int x = 1; x <= X; ++ x) if(b[x]) {
		int p = 0;
		for(int y = x * 2 - 1; ; y += x) {
			int l = left[min(y, X)];
			int t = y - x + 1;
			if(t <= l)
				amax(p, l - t);
			if(X <= y) break;
		}
		amax(ans, p);
	}
	printf("%d\n", ans);
	return 0;
}