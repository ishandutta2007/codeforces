#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = (ll)1e15;

const int N_ = 200005;

struct pth { 
	int l, w;
	pth(): l(0), w(0) { }
	pth(int l, int w): l(l), w(w) { }
	bool operator < (const pth &t) const { return w < t.w; }
};

typedef vector<pth> vpth;

namespace BIT { 
	int itree[N_], timestamp[N_], now;

	void clear() {
		++now;
	}

	void update (int x, int dt) {
		++x;
		while(x > 0 && x < N_) {
			if(timestamp[x] != now) {
				timestamp[x] = now;
				itree[x] = dt;
			}else {
				itree[x] += dt;
			}
			x += x & -x;
		}
	}

	int get (int x) {
		int ret = 0; ++x;
		while(x > 0) {
			if(timestamp[x] == now) ret += itree[x];
			x -= x & -x;
		}
		return ret;
	}
};

namespace Tree {
	struct Edge {
		int v, c;
		Edge (): v(0), c(0) { }
		Edge (int v, int c): v(v), c(c) { }
	} Gph[N_];

	int link[N_]; bool deleted[N_];
	int start_edge[N_];
	int edges;

	void addEdge (int u, int v, int c);
	int startEdge (int u);
	int nextEdge (int e);
	void changeEdge (int e, bool what);

	int Que[N_], Qf, Qr, Level[N_], Weight[N_], Parent[N_];
	int Visited[N_], TIME;
	void BFS (int root);

	int Childs[N_], Maxtree[N_];
	int findMiddle ();
	vpth getPaths (int w, vpth &ret);
};

int N, L, W;
ll result;

ll countPairs (vpth& paths) {
	sort( paths.begin(), paths.end() );

	ll ret = 0;
	
	BIT::clear();
	for(int i = (int)paths.size() - 1, j = 0; i >= 0; i--) {
		while(j < paths.size() && paths[i].w + paths[j].w <= W) {
			BIT::update (paths[j].l, 1);
			++j;
		}

		ret += BIT::get (L - paths[i].l);
		if(paths[i].l * 2 <= L && paths[i].w * 2 <= W) --ret;
	}

	return ret;
}

vpth solve (int root, int pw, bool first = false) {
	vpth rtpths, chpths; int mid;

	Tree::BFS (root);
	mid = Tree::findMiddle ();
	Tree::getPaths (pw, rtpths);

	chpths.push_back( pth(0, 0) );
	for(int edge = Tree::startEdge (mid); edge > 0; edge = Tree::nextEdge(edge)) {
		Tree::changeEdge (edge, false);
		vpth child_paths = solve (Tree::Gph[edge].v, Tree::Gph[edge].c);
		for(int i = 0; i < child_paths.size(); i++) chpths.push_back( child_paths[i] );
		Tree::changeEdge (edge, true);
	}

	result += countPairs (chpths);
	if(!first) result -= countPairs (rtpths);

	return rtpths;
}

int main() {
	int i, j, k;

	scanf("%d%d%d", &N, &L, &W);
	for(i = 2; i <= N; i++) {
		int v, c; scanf("%d%d", &v, &c);
		Tree::addEdge(i, v, c);
	}

	solve(1, 0, true);

	printf("%I64d\n", result / 2);
	return 0;
}

inline void Tree::addEdge (int u, int v, int c) {
	link[++edges] = start_edge[u];
	start_edge[u] = edges;
	Gph[edges] = Edge (v, c);

	link[++edges] = start_edge[v];
	start_edge[v] = edges;
	Gph[edges] = Edge (u, c);
}

inline int Tree::nextEdge (int e) {
	e = link[e];
	while(e > 0 && deleted[(e+1)/2]) e = link[e];
	return e;
}

inline int Tree::startEdge (int u) {
	int ret = start_edge[u];
	while(ret > 0 && deleted[(ret+1)/2]) ret = link[ret];
	return ret;
}

inline void Tree::changeEdge (int e, bool what) {
	deleted[(e+1)/2] = !what;
}

inline void Tree::BFS (int root) {
	Qf = 0; Que[Qr = 1] = root;
	Level[root] = 1; Weight[root] = 0; Parent[root] = -1;
	Visited[root] = ++TIME;

	while(Qf < Qr) {
		int u = Que[++Qf];
		Childs[u] = Maxtree[u] = 0;
		for(int edge = startEdge(u); edge > 0; edge = nextEdge(edge)) {
			Edge &e = Gph[edge];
			if(Visited[e.v] != TIME) {
				Level[e.v] = Level[u] + 1;
				Weight[e.v] = Weight[u] + e.c;
				Parent[e.v] = u; Que[++Qr] = e.v;
				Visited[e.v] = TIME;
			}
		}
	}
}

inline int Tree::findMiddle () {
	int i;

	for(i = Qr; i > 0; i--) {
		int u = Que[i], p = Parent[u];
		Maxtree[u] = max(Maxtree[u], Qr - Childs[u] - 1);
		if(Maxtree[u] <= Qr / 2) return u;
		if(p > 0) {
			Childs[p] += Childs[u] + 1;
			Maxtree[p] = max(Maxtree[p], Childs[u] + 1);
		}
	}

	return -1;
}

inline vpth Tree::getPaths(int w, vpth &ret) {
	for(int i = 1; i <= Qr; i++) {
		int u = Que[i];
		ret.push_back( pth(Level[u], Weight[u] + w) );
	}
	return ret;
}