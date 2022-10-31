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

struct MaximumFlow {
	typedef int Index;
	typedef int Flow;
	static const Flow InfCapacity = INF;
	struct Edge {
		Index to;
		Flow capacity;
		Index rev;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	void addB(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = capacity;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	//g
	Flow maximumFlow(int s, int t) {
		int n = g.size();
		vector<Index> level(n);
		Flow total = 0; bool update;
		do {
			update = false;
			fill(level.begin(), level.end(), -1); level[s] = 0;
			queue<Index> q; q.push(s);
			for(Index d = n; !q.empty() && level[q.front()] < d; ) {
				int u = q.front(); q.pop();
				if(u == t) d = level[u];
				each(e, g[u]) if(e->capacity > 0 && level[e->to] == -1)
					q.push(e->to), level[e->to] = level[u] + 1;
			}
			vector<Index> iter(n);
			for(Index i = 0; i < n; i ++) iter[i] = (int)g[i].size() - 1;
			while(1) {
				Flow f = augment(level, iter, s, t, InfCapacity);
				if(f == 0) break;
				total += f; update = true;
			}
		}while(update);
		return total;
	}
	Flow augment(vector<Index> &level, vector<Index> &iter, Index u, Index t, Flow f) {
		if(u == t || f == 0) return f;
		Index lv = level[u];
		if(lv == -1) return 0;
		level[u] = -1;
		for(; iter[u] >= 0; -- iter[u]) {
			Edge &e = g[u][iter[u]];
			if(level[e.to] <= lv) continue;
			Flow l = augment(level, iter, e.to, t, min(f, e.capacity));
			if(l == 0) continue;
			e.capacity -= l; g[e.to][e.rev].capacity += l;
			level[u] = lv;
			return l;
		}
		return 0;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<pii,int> > edges;
	rep(i, n-1) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c), a --, b --;
		edges.push_back(mp(mp(a, b), c));
	}
	vector<int> x(n);
	rep(i, n)
		scanf("%d", &x[i]);
	int l = 0, u = 10000;
	while(u - l > 0) {
		int mid = (l + u + 1) / 2;
		UnionFind uf; uf.init(n);
		rep(i, n-1) if(edges[i].second < mid)
			uf.unionSet(edges[i].first.first, edges[i].first.second);
		//component
		//(n^2)
		//
		vector<vi> components(n);
		rep(i, n)
			components[uf.root(i)].pb(i);
		vector<int> componentList;
		rep(i, n) if(!components[i].empty())
			componentList.push_back(i);
		int C = componentList.size();
		int B = max(1, (int)pow(C, .5)), Buckets = (C + B - 1) / B;
		int s = C + Buckets + C, t = s + 1;
		MaximumFlow mf; mf.init(t + 1);
		rep(i, C) {
			int cs = components[componentList[i]].size();
			mf.add(s, i, cs);
			rep(j, Buckets) {
				int L = j * B, R = min(C, (j+1) * B);
				if(i < L || R <= i) {
					mf.add(i, C + j, cs);
				}else {
					reu(k, L, R) if(i != k)
						mf.add(i, C + Buckets + k, cs);
				}
			}
		}
		rep(j, Buckets) {
			int L = j * B, R = min(C, (j+1) * B);
			reu(k, L, R)
				mf.add(C + j, C + Buckets + k, INF);
		}
		rep(i, C) {
			int cap = 0;
			each(j, components[componentList[i]])
				cap += x[*j];
			mf.add(C + Buckets + i, t, cap);
		}
		int f = mf.maximumFlow(s, t);
//		cerr << mid << ": " << componentList.size() << ", "<< f << endl;
		if(f == n)
			l = mid;
		else
			u = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}