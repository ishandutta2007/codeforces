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
#include <limits>
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
vector<vi> tree;
vector<int> x;
vector<bool> vis;
vector<int> ans;

void dfs(int i) {
	vis[i] = true;
	each(j, g[i]) if(!vis[*j]) {
//		cerr << i+1 << " -> " << *j+1 << endl;
		tree[i].push_back(*j);
		dfs(*j);
	}
}
void construct(int i, int p) {
	each(j, tree[i]) {
		ans.push_back(i);
		construct(*j, i);
	}
	ans.push_back(i);
	if((1 + tree[i].size()) % 2 != x[i]) {
		if(p == -1) {
			ans.pop_back();
			return;
		}
		ans.push_back(p);
		ans.push_back(i);
		x[p] ^= 1;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	g.assign(n, vi());
	rep(i, m) {
		int u, v;
		scanf("%d%d", &u, &v), -- u, -- v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	x.assign(n, -1);
	rep(i, n) scanf("%d", &x[i]);
	vi tmpx = x;
	if(count(all(x), 1) == 0) {
		puts("0");
		return 0;
	}
	vis.assign(n, false);
	tree.assign(n, vi());
	rep(i, n) if(x[i] == 1) {
		dfs(i);
		construct(i, -1);
		break;
	}
	bool fail = false;
	rep(i, n) if(!vis[i] && x[i] == 1)
		fail = true;
	if(fail) {
		puts("-1");
		return 0;
	}
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i]+1);
		tmpx[ans[i]] ^= 1;
	}
	puts("");
	if(count(all(tmpx), 1) != 0) cerr << "err!" << endl;
	return 0;
}