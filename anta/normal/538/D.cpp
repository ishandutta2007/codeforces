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
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	char board[50][51], ans[99][100];
	int n;
	while(~scanf("%d", &n)) {
		rep(i, n) scanf("%s", board[i]);
		rep(i, n * 2 - 1) {
			rep(j, n * 2 - 1) ans[i][j] = '.';
			ans[i][n * 2 - 1] = 0;
		}
		ans[n-1][n-1] = 'o';
		rer(dy, -n+1, n-1) rer(dx, -n+1, n-1) if(dx != 0 || dy != 0) {
			bool ok = true;
			rep(i, n) rep(j, n) if(board[i][j] == 'o') {
				int yy = i + dy, xx = j + dx;
				if(yy < 0 || yy >= n || xx < 0 || xx >= n) continue;
				ok &= board[yy][xx] != '.';
			}
			if(ok) {
				ans[n-1+dy][n-1+dx] = 'x';
				rep(i, n) rep(j, n) if(board[i][j] == 'o') {
					int yy = i + dy, xx = j + dx;
					if(yy < 0 || yy >= n || xx < 0 || xx >= n) continue;
					if(board[yy][xx] == 'x')
						board[yy][xx] = '@';
				}
			}
		}
		bool ok = true;
		rep(i, n) rep(j, n)
			ok &= board[i][j] != 'x';
		if(!ok) {
			puts("NO");
		}else {
			puts("YES");
			rep(i, n * 2 - 1)
				puts(ans[i]);
		}
	}
	return 0;
}