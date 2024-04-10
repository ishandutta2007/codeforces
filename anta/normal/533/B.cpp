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

vi a;
vector<long long> memo;

inline ll add(ll x, ll y) {
	return x == -INFL || y == -INFL ? -INFL : x + y;
}

//j = 0 p
long long rec(int i, int j, bool p) {
	int s = stateidx[i][j];
	if(s == -1) return rec(i, j+1, p);
	long long &r = memo[s * 2 + (int)p];
	if(r != -1) return r;
	if(j == g[i].size())
		return r = !p ? 0 : -INFL;
	r = -INFL;
	int c = g[i][j];
	rep(cp, 2) {
		//c
		amax(r, add(
			rec(c, 0, cp != 0),
			rec(i, j+1, p != (cp != 0))));
	}
	//c
	amax(r, add(a[c], add(
		rec(c, 0, false),
		rec(i, j+1, !p))));
	return r;
}

int main() {
	int n;
	scanf("%d", &n);
	g.assign(n, vi());
	a.resize(n);
	rep(i, n) {
		int p;
		scanf("%d%d", &p, &a[i]);
		if(p != -1) g[p-1].push_back(i);
	}
	tree_getstateindices(0);
	memo.assign(nstates * 2, -1);
	long long ans = -INFL;
	rep(cp, 2) {
		amax(ans, rec(0, 0, cp == 0));
	}
	amax(ans, add(a[0], rec(0, 0, false)));
	cout << ans << endl;
	return 0;
}