#include <stdio.h> 
#include <time.h>
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
#include <limits.h>  

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

struct worker {
	int l, v, r, x;
	worker (int l = 0, int v = 0, int r = 0, int x = 0): l(l), v(v), r(r), x(x) { }
	bool operator< (const worker &s) const { return l < s.l; }
};

struct node {
	int k, t, p;
	node(int k = 0, int t = 0, int p = 0): k(k), t(t), p(p) { }
};

const int N_ = 100505;
const int MAXX = 300000;

int N;
worker D[N_];

int res = -1987654321;

priority_queue<pii, vector<pii>, greater<pii> > PQ;

node Tree[1048577];

void spread (int nd) {
	int ch1 = nd+nd, ch2 = nd+nd+1;
	Tree[ch1].k += Tree[nd].k;
	Tree[ch1].t += Tree[nd].k;
	Tree[ch2].k += Tree[nd].k;
	Tree[ch2].t += Tree[nd].k;
	Tree[nd].k = 0;
}

void update (int nd, int nl, int nr, int x, int y, int d) {
	node &here = Tree[nd];
	if(here.p == 0) Tree[nd].p = nl;
	if(nl == x && nr == y) {
		here.k += d;
		here.t += d;
	}else {
		int nmid = (nl + nr) >> 1;
		if(here.k != 0) spread(nd);

		if(x <= nmid) update(nd+nd,       nl, nmid,             x, min(y, nmid), d);
		if(nmid < y)  update(nd+nd+1, nmid+1,   nr, max(x, nmid+1),           y, d);

		int q = 0;
		if(Tree[nd+nd].t < Tree[nd+nd+1].t) q = 1;
		here.t = Tree[nd+nd+q].t;
		here.p = Tree[nd+nd+q].p;
	}
}

void add (int w, int d) {
	update(1, 1, 524288, D[w].v, D[w].r, d);
}

int solve() {
	int ret = 0;

	while(!PQ.empty()) PQ.pop();

	for(int x = 1, i = 1; x <= MAXX; x++) {

		while(i <= N && D[i].l <= x) {
			PQ.push( pii(D[i].v, i) );
			add(i++, 1);
		}

		while(!PQ.empty() && PQ.top().first < x) {
			add(PQ.top().second, -1);
			PQ.pop();
		}

		if(Tree[1].t == res) {
			printf("%d\n", res);
			while(!PQ.empty()) {
				int w = PQ.top().second; PQ.pop();
				if(D[w].v <= Tree[1].p && Tree[1].p <= D[w].r) printf("%d ", D[w].x);
			}
			exit(0);
		}

		ret = max(ret, Tree[1].t);
	}
	return ret;
}

int main() {
	int i, j, k;
	
	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d%d%d", &D[i].l, &D[i].v, &D[i].r), D[i].x = i;
	sort(D+1, D+N+1);

	res = solve();
	solve();

	return 0;
}