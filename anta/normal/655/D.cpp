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

bool topologicalSort(const vector<vi> &g, vi &ord) {
	int n = g.size();
	vi deg(n);
	rep(i, n) each(j, g[i]) deg[*j] ++;
	ord.assign(n, -1);
	int t = 0;
	rep(i, n) if(deg[i] == 0) ord[t ++] = i;
	for(int h = 0; h < t; h ++) {
		int v = ord[h];
		each(j, g[v])
			if(-- deg[*j] == 0)
				ord[t ++] = *j;
	}
	return t == n;
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<int> u(m);
		vector<int> v(m);
		for(int i = 0; i < m; ++ i)
			scanf("%d%d", &u[i], &v[i]), -- u[i], -- v[i];
		int lo = 0, up = m + 1;
		while(up - lo > 0) {
			int mid = (lo + up) / 2;
			vector<vi> g(n);
			rep(i, mid)
				g[u[i]].push_back(v[i]);
			vi ord;
			topologicalSort(g, ord);
			bool allok = true;
			rep(i, n - 1) {
				bool ok = false;
				each(j, g[ord[i]])
					ok |= *j == ord[i + 1];
				allok &= ok;
			}
			if(allok)
				up = mid;
			else
				lo = mid + 1;
		}
		if(up == m + 1)
			puts("-1");
		else
			printf("%d\n", up);
	}
	return 0;
}