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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int a; int b;
	while(~scanf("%d%d%d", &n, &a, &b)) {
		vector<vi> ans(a, vi(b, 0));
		int t = (n + 1) / 2, u = n / 2;
		rep(i, a) rep(j, b) {
			if((i + j) % 2 == 0) {
				if(t > 0)
					ans[i][j] = (t --) * 2 - 1;
			} else {
				if(u > 0)
					ans[i][j] = (u --) * 2;
			}
		}
		if(t > 0 || u > 0) {
			puts("-1");
		} else {
			rep(i, a) {
				rep(j, b) {
					if(j != 0) putchar(' ');
					printf("%d", ans[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}