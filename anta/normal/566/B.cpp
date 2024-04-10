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
	while(1) {
		if(!~scanf("%d", &n)) break;

//		n = rand() % 5 + 1; vi randperm(n * 8); rep(i, n * 8) randperm[i] = i / 8; random_shuffle(all(randperm));

		vector<vector<pair<int,pii> > > g(n);
		vector<pair<int,pii> > edges(4 * n);
		rep(i, 4 * n) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c), -- a, -- b, -- c;
//			a = i / 4, b = randperm[i * 2 + 0], c = randperm[i * 2 + 1];
			g[a].push_back(mp(i, mp(b, c)));
			edges[i] = mp(a, mp(b, c));
		}
		vi ans;
		vi cnt(n, 8);
		vi iter(n, 0);
		vi stk;
		rep(i, n) stk.push_back(i);
		rep(kk, 4 * n) {
			int a = -1;
			while(!stk.empty()) {
				int i = stk.back(); stk.pop_back();
				if(cnt[i] < 9 && iter[i] < 4) {
					a = i;
					break;
				}
			}
			if(a == -1) { ans.clear(); break; }
			int k = iter[a] ++;
			int b = g[a][k].second.first;
			int c = g[a][k].second.second;
			ans.push_back(g[a][k].first);
			++ cnt[a], -- cnt[b], -- cnt[c];
			if(cnt[a] < 9 && iter[a] < 4) stk.push_back(a);
			if(cnt[b] < 9 && iter[b] < 4) stk.push_back(b);
			if(cnt[c] < 9 && iter[c] < 4) stk.push_back(c);
		}
		if(ans.empty()) {
			puts("NO");
		}else {
			puts("YES");
			reverse(all(ans));
			rep(i, 4 * n) {
				if(i != 0) putchar(' ');
				printf("%d", ans[i] + 1);
			}
			puts("");

			cnt.assign(n, 4);
			each(i, ans) {
				if(-- cnt[edges[*i].first] < 0) cerr << "err 1" << endl, abort();
				if(++ cnt[edges[*i].second.first] > 9) cerr << "err 2" << endl, abort();
				if(++ cnt[edges[*i].second.second] > 9) cerr << "err 3" << endl, abort();
			}
			if(count(all(cnt), 8) != n) cerr << "err 4" << endl, abort();
		}
	}
	return 0;
}