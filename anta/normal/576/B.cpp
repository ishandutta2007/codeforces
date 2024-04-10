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
	while(~scanf("%d", &n)) {
		vi p(n);
		rep(i, n) scanf("%d", &p[i]), -- p[i];
		vector<bool> vis(n);
		vector<vi> cycles;
		rep(i, n) if(!vis[i]) {
			int j = i;
			vi cycle;
			while(!vis[j]) {
				vis[j] = true;
				cycle.push_back(j);
				j = p[j];
			}
			cycles.push_back(cycle);
		}
		int center = -1;
		each(i, cycles) if(i->size() == 1) {
			center = (*i)[0];
			break;
		}
		vpii edges;
		if(center != -1) {
			rep(i, n) if(i != center)
				edges.push_back(mp(center, i));
		}else {
			vi twin;
			each(i, cycles) if(i->size() == 2) {
				twin = *i;
				break;
			}
			bool ok = !twin.empty();
			each(i, cycles)
				ok &= i->size() % 2 == 0;
			if(!ok) {
				puts("NO");
				continue;
			}
			each(i, cycles) {
				if(i->size() == 2 && *i == twin) {
					edges.push_back(mp(twin[0], twin[1]));
				}else {
					rep(j, i->size()) {
						int v = (*i)[j];
						edges.push_back(mp(twin[j % 2], v));
					}
				}
			}
		}
		puts("YES");
		each(i, edges)
			printf("%d %d\n", i->first + 1, i->second + 1);
	}
	return 0;
}