#define _CRT_SECURE_NO_WARNINGS
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

vector<vi> g;
vector<int> parent;
vector<vi> stateidx;
vi t_ord;

int nstates = 0;

void tree_getstateindices(int root) {
	int n = g.size();
	parent.assign(n, -1);
	stateidx.assign(n, vi());
	t_ord.clear();
	nstates = 0;

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		stateidx[i].assign(g[i].size() + 1, -1);
		rep(j, g[i].size()) {
			int c = g[i][j];
			if(parent[c] == -1 && c != root) {
				stk.push_back(c);
				stateidx[i][j] = nstates ++;
			}else {
				stateidx[i][j] = -1;
				parent[i] = c;
			}
		}
		stateidx[i][g[i].size()] = nstates ++;
	}
}

inline int getstateindex(int i, int j) {
	int s = stateidx[i][j];
	return s != -1 ? s : stateidx[i][j+1];
}

vi subtreesize;
int measure_tree(int i) {
	int r = 1;
	for(int j = g[i].size(); j >= 0; j --) if(stateidx[i][j] != -1) {
		if(j != g[i].size()) r += measure_tree(g[i][j]);
		subtreesize[stateidx[i][j]] = r;
	}
	return r;
}


int memo[800][403][2];
int K;
int rec(int i, int j, int k, bool ok) {
	int s = stateidx[i][j];
	if(s == -1) return rec(i, j+1, k, ok);
	int &r = memo[s][k+1][ok];
	if(r != -1) return r;
	if(k > subtreesize[s]) return r = INF;
	if(j == g[i].size()) return r = ok && (k == -1 || k == 1) ? 0 : INF;
	int c = g[i][j];
	r = INF;
	rep(cex, 2) {
		if(k == -1) {
			//
			amin(r, rec(c, 0, -1, !cex) + rec(i, j+1, -1, ok || cex));
			//
			amin(r, 1 + rec(c, 0, -1, !cex) + rec(i, j+1, -1, ok || cex));
			amin(r, 1 + rec(c, 0, K, true) + rec(i, j+1, -1, ok || cex));
		}else {
			//
			int leftsize = subtreesize[getstateindex(c, 0)], rightsize = subtreesize[getstateindex(i, j+1)];
			int maxl = min(k-1, leftsize), minl = max(1, k - rightsize);
			for(int l = minl; l <= maxl; l ++) {
				amin(r, rec(c, 0, l, !cex) + rec(i, j+1, k-l, ok || cex));
			}
			//
			amin(r, 1 + rec(c, 0, -1, !cex) + rec(i, j+1, k, ok || cex));
		}
	}
	return r;
}

vector<vi> edgeid; vector<int> ans;
void rec2(int i, int j, int k, bool ok) {
	int s = stateidx[i][j];
	if(s == -1) return rec2(i, j+1, k, ok);
	int r = memo[s][k+1][ok];
	if(j == g[i].size()) return;
	int c = g[i][j];
	rep(cex, 2) {
		if(k == -1) {
			//
			if(rec(c, 0, -1, !cex) + rec(i, j+1, -1, ok || cex) == r)
				return rec2(c, 0, -1, !cex), rec2(i, j+1, -1, ok || cex);
			//
			if(1 + rec(c, 0, -1, !cex) + rec(i, j+1, -1, ok || cex) == r)
				return ans.pb(edgeid[i][j]), rec2(c, 0, -1, !cex), rec2(i, j+1, -1, ok || cex);
			if(1 + rec(c, 0, K, true) + rec(i, j+1, -1, ok || cex) == r)
				return ans.pb(edgeid[i][j]), rec2(c, 0, K, true), rec2(i, j+1, -1, ok || cex);
		}else {
			//
			int leftsize = subtreesize[getstateindex(c, 0)], rightsize = subtreesize[getstateindex(i, j+1)];
			int maxl = min(k-1, leftsize), minl = max(1, k - rightsize);
			for(int l = minl; l <= maxl; l ++) {
				if(rec(c, 0, l, !cex) + rec(i, j+1, k-l, ok || cex) == r)
					return rec2(c, 0, l, !cex), rec2(i, j+1, k-l, ok || cex);
			}
			//
			if(1 + rec(c, 0, -1, !cex) + rec(i, j+1, k, ok || cex) == r)
				return ans.pb(edgeid[i][j]), rec2(c, 0, -1, !cex), rec2(i, j+1, k, ok || cex);
		}
	}
	cerr << "Error!!!!" << endl;
}




int main() {
	int n;
	scanf("%d%d", &n, &K);
	g.assign(n, vi());
	edgeid.assign(n, vi());
	rep(i, n-1) {
		int a, b;
		scanf("%d%d", &a, &b), a --, b --;
		g[a].pb(b);
		g[b].pb(a);
		edgeid[a].pb(i);
		edgeid[b].pb(i);
	}
	tree_getstateindices(0);
	subtreesize.assign(nstates, 0);
	measure_tree(0);
	mset(memo, -1);
	int r = INF;
	amin(r, rec(0, 0, -1, false));
	amin(r, rec(0, 0, K, true));
	ans.clear();
	if(rec(0, 0, -1, false) == r)
		rec2(0, 0, -1, false);
	else
		rec2(0, 0, K, true);
	printf("%d\n", r);
	rep(i, ans.size()) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	puts("");
	return 0;
}