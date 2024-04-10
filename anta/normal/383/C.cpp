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
#include <list>
#include <cassert>
#include <limits>
#include <iterator>
#include <iomanip>
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

struct CentroidPathDecomposition {
	vector<int> colors, positions;
	vector<int> lengths, parents, branches;
	vector<int> parentnodes, depths;
	vector<int> sortednodes, offsets;

	void build(const vector<vi> &g, int root) {
		int n = g.size();

		colors.assign(n, -1); positions.assign(n, -1);
		lengths.clear(); parents.clear(); branches.clear();
		parentnodes.assign(n, -1); depths.assign(n, -1);

		vector<int> subtreesizes;
		measure(g, root, subtreesizes);

		struct State {
			int i, len, parent;
			State() { }
			State(int i_, int l, int p): i(i_), len(l), parent(p) { }
		};
		depths[root] = 0;
		vector<State> s;
		s.push_back(State(root, 0, -1));
		while(!s.empty()) {
			State t = s.back(); s.pop_back();
			int i = t.i, len = t.len;
			int color = lengths.size();
			if(t.parent != -2) {
				assert(parents.size() == color);
				parents.push_back(t.parent);
				branches.push_back(len);
				len = 0;
			}
			colors[i] = color;
			positions[i] = len;

			int maxsize = -1, maxj = -1;
			each(j, g[i]) if(colors[*j] == -1) {
				if(maxsize < subtreesizes[*j]) {
					maxsize = subtreesizes[*j];
					maxj = *j;
				}
				parentnodes[*j] = i;
				depths[*j] = depths[i] + 1;
			}
			if(maxj == -1) {
				lengths.push_back(len + 1);
			}else {
				each(j, g[i]) if(colors[*j] == -1 && *j != maxj)
					s.push_back(State(*j, len, color));
				s.push_back(State(maxj, len + 1, -2));
			}
		}

		sortNodes();
	}

	void sortNodes() {
		int n = colors.size(), m = lengths.size();
		sortednodes.resize(n, -1);
		offsets.resize(m + 1);
		rep(i, m) offsets[i+1] = offsets[i] + lengths[i];
		rep(i, n) sortednodes[offsets[colors[i]] + positions[i]] = i;
	}

	void get(int v, int &c, int &p) const {
		c = colors[v]; p = positions[v];
	}
	bool go_up(int &c, int &p) const {
		p = branches[c]; c = parents[c];
		return c != -1;
	}

	inline const int *nodesBegin(int c) const { return &sortednodes[0] + offsets[c]; }
	inline const int *nodesEnd(int c) const { return &sortednodes[0] + offsets[c+1]; }

private:
	void measure(const vector<vi> &g, int root, vector<int> &out_subtreesizes) const {
		out_subtreesizes.assign(g.size(), -1);
		vector<int> s;
		s.push_back(root);
		while(!s.empty()) {
			int i = s.back(); s.pop_back();
			if(out_subtreesizes[i] == -2) {
				int s = 1;
				each(j, g[i]) if(out_subtreesizes[*j] != -2)
					s += out_subtreesizes[*j];
				out_subtreesizes[i] = s;
			}else {
				s.push_back(i);
				each(j, g[i]) if(out_subtreesizes[*j] == -1)
					s.push_back(*j);
				out_subtreesizes[i] = -2;
			}
		}
	}
};

struct FenwickTree {
	typedef ll T;
	vector<T> v;
	FenwickTree() { }
	FenwickTree(int n): v(n, 0) {}
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i+1) v[i] += x;
	}
	T sum(int i) {	//[0, i)
		T r = 0;
		for(-- i; i >= 0; i = (i & (i+1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) {	//[left, right)
		return sum(right) - sum(left);
	}
};

int a[200000];

vector<vi> g;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	g.assign(n, vi());
	rep(i, n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x --, y --;
		g[x].pb(y);
		g[y].pb(x);
	}
	CentroidPathDecomposition cpd;
	cpd.build(g, 0);
	cpd.sortNodes();
	FenwickTree pathsums[2];
	rep(i, 2) pathsums[i] = FenwickTree(n + 1);

	rep(ii, m) {
		int t, x;
		scanf("%d%d", &t, &x);
		x --;
		if(t == 1) {
			int val;
			scanf("%d", &val);
			int c = cpd.colors[x];
			int eo = cpd.depths[x] % 2;
			pathsums[eo].add(cpd.offsets[c] + cpd.positions[x], val);
		}else {
			ll sum = 0;
			int c, p;
			cpd.get(x, c, p);
			while(c != -1) {
				int off = cpd.offsets[c];
				sum += pathsums[0].sum(off, off + p + 1);
				sum -= pathsums[1].sum(off, off + p + 1);
				cpd.go_up(c, p);
			}
			if(cpd.depths[x] % 2 == 1)
				sum *= -1;
//			cerr << a[x] << ", " << sum << endl;
			printf("%I64d\n", (ll)a[x] + sum);
		}
	}
	return 0;
}