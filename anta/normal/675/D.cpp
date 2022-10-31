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
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vpii ai(n);
		rep(i, n)
			ai[i] = mp(a[i], i);
		sort(all(ai));
		vector<int> pos(n);
		rep(i, n)
			pos[ai[i].second] = i;
		vector<int> ans(n - 1);
		map<int,pair<int,int>> ch;
		ch[pos[0]] = mp(-1, -1);
		reu(i, 1, n) {
			auto Lit = ch.lower_bound(pos[i]);
			bool Lok = false, Rok = false;
			if(Lit != ch.begin()) {
				-- Lit;
				Lok = Lit->second.first == -1;
			}
			auto Rit = ch.upper_bound(pos[i]);
			if(Rit != ch.end()) {
				Rok = Rit->second.second == -1;
			}
			if(Lok) {
				ans[i - 1] = ai[Lit->first].first;
				Lit->second.first = i;
			} else {
				ans[i - 1] = ai[Rit->first].first;
				Rit->second.second = i;
			}
			ch.insert(mp(pos[i], mp(-1, -1)));
		}
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}