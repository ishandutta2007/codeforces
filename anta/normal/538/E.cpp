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

vector<int> t_parent;
vi t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for(int j = (int)g[i].size()-1; j >= 0; j --) {
			int c = g[i][j];
			if(t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}

int main() {
	int n;
	while(1) {
		if(!~scanf("%d", &n)) break;
//		n = 7;
		vector<vi> g(n);
		rep(i, n-1) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
//			u=i+1,v=rand()%(i+1);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		vector<int> leafnum(n, 0), leafidx(n, -1); int m = 0;
		rep(i, n) if(n == 1 || (i != 0 && g[i].size() == 1)) {
			leafnum[i] = 1;
			leafidx[i] = m ++;
		}
		for(int ix = n-1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			leafnum[p] += leafnum[i];
		}
		vector<bool> level(n);
		level[0] = false;
		for(int ix = 1; ix < n; ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			level[i] = !level[p];
		}
		vector<int> mi(n, INF), ma(n, -INF);
		for(int ix = n-1; ix >= 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			int s = leafnum[i];
			if(s == 1) {
				mi[i] = ma[i] = 0;
			}else if(!level[i]) {
				int l = 0;
				each(j, g[i]) if(*j != p)
					l += mi[*j] + 1;
				amin(mi[i], l - 1);
				each(j, g[i]) if(*j != p)
					amax(ma[i], s - leafnum[*j] + ma[*j]);
			}else {
				int r = 0;
				each(j, g[i]) if(*j != p)
					r += leafnum[*j] - ma[*j];
				amax(ma[i], s - r);
				each(j, g[i]) if(*j != p)
					amin(mi[i], mi[*j]);
			}
		}
		/*
		vi perm(m);
		rep(i, m) perm[i] = i;
		vi dp(n);
		int naivema = -1, naivemi = INF;
		do {
			for(int ix = n-1; ix >= 0; -- ix) {
				int i = t_ord[ix], p = t_parent[i];
				if(leafidx[i] != -1) {
					dp[i] = perm[leafidx[i]];
				}else if(!level[i]) {
					dp[i] = -1;
					each(j, g[i]) if(*j != p)
						amax(dp[i], dp[*j]);
				}else {
					dp[i] = INF;
					each(j, g[i]) if(*j != p)
						amin(dp[i], dp[*j]);
				}
			}
			amax(naivema, dp[0]);
			amin(naivemi, dp[0]);
		}while(next_permutation(all(perm)));
		if(ma[0] != naivema || mi[0] != naivemi) {
			reu(i ,1, n)
				cerr <<t_parent[i]+1 << " " << i+1 << endl;
			cerr << "err" << endl;
		}
		*/
		printf("%d %d\n", ma[0] + 1, mi[0] + 1);
	}
	return 0;
}