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

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<vpii> rows(n), cols(m);
		vector<vi> orga(n, vi(m));
		for(int i = 0; i < n; ++ i) {
			for(int j = 0; j < m; ++ j) {
				int a;
				scanf("%d", &a);
				rows[i].emplace_back(a, i * m + j);
				cols[j].emplace_back(a, i * m + j);
				orga[i][j] = a;
			}
		}
		UnionFind uf; uf.init(n * m);
		rep(i, n) {
			sort(all(rows[i]));
			for(int j = 0; j < m; ) {
				int k = j;
				for(; k < m && rows[i][j].first == rows[i][k].first; ++ k)
					uf.unionSet(rows[i][j].second, rows[i][k].second);
				j = k;
			}
		}
		rep(j, m) {
			sort(all(cols[j]));
			for(int i = 0; i < n; ) {
				int k = i;
				for(; k < n && cols[j][i].first == cols[j][k].first; ++ k)
					uf.unionSet(cols[j][i].second, cols[j][k].second);
				i = k;
			}
		}
		vector<int> head(n * m, -1), next(n * m, -1);
		rep(t, n * m) {
			int g = uf.root(t);
			next[t] = head[g];
			head[g] = t;
		}
		vector<int> oknum(n * m, 0);
		vi ys(n, 0), xs(m, 0);
		vector<int> q, nq;
		auto addGroup = [&](int g) {
			for(int u = head[g]; u != -1; u = next[u])
				nq.push_back(u);
		};
		auto processRow = [&](int i, int a) {
			const auto &v = rows[i];
			int &y = ys[i];
			if(y == m || (y > 0 && v[y - 1].first != a)) return;
			for(a = v[y].first; y < m && v[y].first == a; ++ y) {
				int g = uf.root(v[y].second);
				++ oknum[g];
				if(oknum[g] == uf.size(g) * 2)
					addGroup(g);
			}
		};
		auto processCol = [&](int j, int a) {
			const auto &w = cols[j];
			int &x = xs[j];
			if(x == n || (x > 0 && w[x - 1].first != a)) return;
			for(a = w[x].first; x < n && w[x].first == a; ++ x) {
				int g = uf.root(w[x].second);
				++ oknum[g];
				if(oknum[g] == uf.size(g) * 2)
					addGroup(g);
			}
		};
		rep(i, n)
			processRow(i, rows[i][0].first);
		rep(j, m)
			processCol(j, cols[j][0].first);
		vector<vi> ans(n, vi(m, -1));
		int num = 1;
		for(; !nq.empty(); ++ num) {
			q.swap(nq); nq.clear();
			for(int t : q) {
				ans[t / m][t % m] = num;
				int a = orga[t / m][t % m];
				processRow(t / m, a);
				processCol(t % m, a);
			}
		}
		rep(i, n) {
			for(int j = 0; j < m; ++ j) {
				if(j != 0) putchar(' ');
				printf("%d", ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}