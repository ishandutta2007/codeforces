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
//	while(1) {
//	string A; int An = rand() % 10 + 3, C = rand() % 3 + 2;
//	rep(k, An) A += (char)(rand() % C + 'a');
//	cerr << "A = " << A << endl;
	int n;
	while(~scanf("%d", &n)) {
//	n = A.size() - 2;
	int V = 128 * 128;
	vector<vi> g(V);
	rep(i, n) {
		char s[4];
		scanf("%s", s);
//		s[0] = A[i], s[1] = A[i+1], s[2] = A[i+2];
		g[s[0] * 128 + s[1]].push_back(s[1] * 128 + s[2]);
	}
	vector<int> ds(V, 0);
	rep(i, V) each(j, g[i]) {
		++ ds[i];
		-- ds[*j];
	}
	int s = -1;
	rep(i, V) {
		if(ds[i] == 1)
			s = i;
	}
	if(s == -1) {
		rep(i, V) if(!g[i].empty())
			s = i;
	}
	int m = 0, deg = 0, non0 = 0;
	rep(i, V) {
		m += g[i].size();
		deg += ds[i];
		if(ds[i] != 0) ++ non0;
	}
	bool ok = false;
	vi trail;
	vector<int> p(V, 0);
	if(non0 == 0 || non0 == 2 && deg == 0 && ds[s] == 1) {
		vi stk;
		for(stk.push_back(s); !stk.empty(); ) {
			int v = stk.back(); stk.pop_back();
			for(; p[v] < (int)g[v].size(); v = g[v][p[v] ++])
				stk.push_back(v);
			trail.push_back(v);
		}
		reverse(all(trail));
	}
	if(trail.size() != n + 1) {
		puts("NO");
	}else {
		puts("YES");
		rep(i, n+1) {
			char a = (char)(trail[i] / 128);
			putchar(a);
		}
		putchar((char)(trail.back() % 128));
		puts("");
	}
	}
	return 0;
}