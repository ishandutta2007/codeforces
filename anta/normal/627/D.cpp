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
		for(int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if(t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}

int main() {
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		vector<vi> children(n);
		vector<int> childid(n, -1);
		rep(i, n) each(j, g[i]) if(*j != t_parent[i]) {
			childid[*j] = children[i].size();
			children[i].push_back(*j);
		}
		vector<int> subtsize(n, 1);
		for(int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}
		int l = 0, u = *max_element(all(a));
		while(u - l > 0) {
			int mid = (l + u + 1) / 2;
			vector<bool> isok(n);
			rep(i, n)
				isok[i] = a[i] >= mid;
			vector<int> subt(n);
			for(int ix = (int)t_ord.size() - 1; ix >= 0; -- ix) {
				int i = t_ord[ix], p = t_parent[i];
				if(!isok[i]) {
					subt[i] = 0;
				} else {
					int sum = 1, mx = 0;
					for(int j : children[i]) {
						if(subt[j] == subtsize[j])
							sum += subt[j];
						else
							amax(mx, subt[j]);
					}
					subt[i] = sum + mx;
				}
			}
			vector<int> fullsum(n);
			vector<vi> leftmax(n), rightmax(n);
			vi v;
			rep(i, n) {
				int num = children[i].size();
				leftmax[i].assign(num + 1, 0);
				rightmax[i].assign(num + 1, 0);
				v.assign(num, 0);
				rep(ci, children[i].size()) {
					int j = children[i][ci];
					if(subt[j] == subtsize[j])
						fullsum[i] += subt[j];
					else
						v[ci] = subt[j];
				}
				for(int ci = 0; ci < num; ++ ci) {
					leftmax[i][ci + 1] = max(leftmax[i][ci], v[ci]);
				}
				for(int ci = num - 1; ci >= 0; -- ci) {
					rightmax[i][ci] = max(rightmax[i][ci + 1], v[ci]);
				}
			}
			vector<int> par(n);
			for(int ix = 1; ix < (int)t_ord.size(); ++ ix) {
				int i = t_ord[ix], p = t_parent[i];
				if(!isok[p]) {
					par[i] = 0;
				} else {
					int sum = 1, mx = 0;
					if(par[p] == n - subtsize[p])
						sum += par[p];
					else
						amax(mx, par[p]);
					int ci = childid[i];
					sum += fullsum[p] - (subt[i] == subtsize[i] ? subt[i] : 0);
					amax(mx, leftmax[p][ci]);
					amax(mx, rightmax[p][ci + 1]);
					par[i] = sum + mx;
				}
			}
			int maxnum = 0;
			rep(i, n) if(isok[i]) {
				int sum = 1, mx = 0;
				if(par[i] == n - subtsize[i])
					sum += par[i];
				else
					amax(mx, par[i]);
				for(int j : children[i]) {
					if(subt[j] == subtsize[j])
						sum += subt[j];
					else
						amax(mx, subt[j]);
				}
				int num = sum + mx;
				amax(maxnum, num);
			}
			if(maxnum >= k)
				l = mid;
			else
				u = mid - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}