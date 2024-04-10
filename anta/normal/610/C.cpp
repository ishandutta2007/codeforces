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

int table[1<<9][1<<9];

void rec(int N, int y, int x, int s) {
	if(N == 1) {
		table[y][x] = s;
	} else if(N % 2 == 0) {
		rec(N / 2, y, x, s);
		rec(N / 2, y + N / 2, x, s);
		rec(N / 2, y, x + N / 2, s);
		rec(N / 2, y + N / 2, x + N / 2, -s);
	} else {
		table[0][0] = 0;
	}
}

int main() {
	int k;
	while(~scanf("%d", &k)) {
		rec(1 << k, 0, 0, 1);
		rep(i, 1 << k) {
			rep(j, 1 << k)
				putchar(table[i][j] == 1 ? '+' : '*');
			puts("");
		}
	}
	return 0;
}