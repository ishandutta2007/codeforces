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
		long long k;
		scanf("%lld", &k);
		vector<vector<int> > a(n, vector<int>(m));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j)
			scanf("%d", &a[i][j]);
		vector<pair<int, int>> values;
		rep(i, n) rep(j, m)
			values.emplace_back(a[i][j], i * m + j);
		vector<vector<bool>> available(n, vector<bool>(m));
		UnionFind uf;
		uf.init(n * m);
		int total = 0;
		vector<vi> ans;
		sort(all(values));
		reverse(all(values));
		for(pii p : values) {
			int i = p.second / m, j = p.second % m;
			available[i][j] = true;
			++ total;

			static const int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
			for(int d = 0; d < 4; ++ d) {
				int yy = i + dy[d], xx = j + dx[d];
				if(yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
				if(!available[yy][xx]) continue;
				uf.unionSet(i * m + j, yy * m + xx);
			}

			if(k % p.first == 0) {
				long long num = k / p.first;
				if(uf.size(i * m + j) >= num) {
					ans.assign(n, vi(m, 0));
					vector<bool> vis(n * m);
					vi q;
					q.push_back(i * m + j);
					vis[i * m + j] = true;
					for(int h = 0; h < num; ++ h) {
						assert(h < (int)q.size());
						int u = q[h];
						ans[u / m][u % m] = p.first;
						for(int d = 0; d < 4; ++ d) {
							int yy = u / m + dy[d], xx = u % m + dx[d];
							if(yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
							if(!available[yy][xx]) continue;
							int v = yy * m + xx;
							if(vis[v]) continue;
							vis[v] = true;
							q.push_back(v);
						}
					}
					break;
				}
			}
		}
		if(ans.empty()) {
			puts("NO");
		} else {
			puts("YES");
			rep(i, n) {
				rep(j, m) {
					if(j != 0) putchar(' ');
					printf("%d", ans[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}