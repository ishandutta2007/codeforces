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
	int n;
	static char s[100][101];
	while(~scanf("%d", &n)) {
		rep(i, n) scanf("%s", s[i]);
		vector<int> a(n);
		rep(i, n) scanf("%d", &a[i]);
		vector<bool> used(n, false);
		vector<int> cnt(n, 0);
		while(1) {
			vi v;
			rep(i, n) if(!used[i]) {
				if(cnt[i] == a[i])
					v.push_back(i);
			}
			if(v.empty()) break;
			each(i, v) {
				used[*i] = true;
				rep(j, n) if(s[*i][j] == '1')
					++ cnt[j];
			}
		}
		bool ok = true;
		rep(i, n)
			ok &= cnt[i] != a[i];
		if(!ok) {
			puts("-1");
		}else {
			printf("%d\n", (int)count(all(used), true));
			rep(i, n) if(used[i])
				printf("%d ", i + 1);
			puts("");
		}
	}
	return 0;
}