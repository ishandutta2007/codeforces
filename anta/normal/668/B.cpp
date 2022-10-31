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
	int n; int q;
	while(~scanf("%d%d", &n, &q)) {
		vector<bool> swapseq;
		int rot = 0;
		rep(i, q) {
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int x;
				scanf("%d", &x);
				rot = ((rot - x) % n + n) % n;
			} else if(ty == 2) {
				swapseq.push_back(rot % 2 != 0);
				if(swapseq.size() >= 2 && swapseq.end()[-1] == swapseq.end()[-2])
					swapseq.resize(swapseq.size() - 2);
			} else abort();
		}
		vi ans(n);
		int t = swapseq.size() % n;
		rep(i, n) {
			int j = (i + (swapseq.empty() ? 0 : swapseq[0])) % 2 == 0 ? i + t : i - t;
			j = (j % n + n) % n;
			ans[j] = i + 1;
		}
		rotate(ans.begin(), ans.begin() + rot, ans.end());
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}