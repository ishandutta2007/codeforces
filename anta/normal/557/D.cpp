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
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		if(m == 0) {
			int t = 3;
			ll w = (ll)n * (n-1) * (n-2) / 6;
			cout << t << " " << w << endl;
			continue;
		}
		UnionFind uf, uf2;
		uf.init(n * 2);
		uf2.init(n);
		rep(i, m) {
			int a, b;
			scanf("%d%d", &a, &b), -- a, -- b;
			uf.unionSet(a, n + b);
			uf.unionSet(n + a, b);
			uf2.unionSet(a, b);
		}
		bool bip = true;
		rep(i, n)
			bip &= !uf.findSet(i, n + i);
		if(!bip) {
			int t = 0, w = 1;
			cout << t << " " << w << endl;
			continue;
		}
		vector<vi> ccs(n, vi(2, 0));
		rep(i, n) {
			int r = uf2.root(i);
			++ ccs[r][uf.findSet(r, i)];
		}
		int t = 1;
		ll w = 0;
		rep(i, n) if(uf2.root(i) == i) {
			cerr << ccs[i][0] << ", " << ccs[i][1] << endl;
			rep(k, 2) {
				int a = ccs[i][k];
				w += (ll)a * (a-1) / 2;
			}
		}
		if(w == 0) {
			t = 2;
			w = (ll)m * (n - 2);
		}
		cout << t << " " << w << endl;
	}
	return 0;
}