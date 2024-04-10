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
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 300500;

int N, W;

struct level {
	int a, b, bm;
	level (int a = 0, int b = 0): a(a), b(b), bm(-1) { }
};

level levels[N_];

priority_queue<pii, vector<pii>, greater<pii> > pq;

const int LEAF = 1<<19;
struct node {
	int c; ll s;
	node (int c = 0, ll s = 0): c(c), s(s) { }
	node operator+ (node p) {
		return node(c + p.c, s + p.s);
	}
};
node tree[LEAF + LEAF];

map<int, int> mpb; int COORDB;
int revb[N_];

void upd (int x, int v) {
	x += LEAF; 
	tree[x].c += v;
	tree[x].s = (ll)tree[x].c * revb[x - LEAF];
	while(x >>= 1) tree[x] = (tree[x+x] + tree[x+x+1]);
}

node get (int x) {
	node ret;
	for(x += LEAF; x > 0; x >>= 1) ret = ret + tree[x];
	return ret;
}

node get (int x, int y) {
	node ret;
	x += LEAF; y += LEAF;
	while(x <= y) {
		if(x & 1) ret = ret + tree[x];
		if(~y & 1) ret = ret + tree[y];
		x = (x + 1) >> 1;
		y = (y - 1) >> 1;
	}
	return ret;
}

int get_kth (int k) {
	int nd = 1;
	while(nd < LEAF) {
		int t = tree[nd+nd].c;
		if(k <= t) {
			nd = nd + nd;
		}else {
			k -= t;
			nd = nd + nd + 1;
		}
	}
	return nd-LEAF;
}

ll ans = (ll)1e18; int ans_ones;
char scenario[N_];

int main() {
	scanf("%d%d", &N, &W);
	for(int i = 1; i <= N; i++) {
		level &l = levels[i];
		scanf("%d%d", &l.a, &l.b);
		pq.push(pii(l.a, i));
		mpb[l.b]++;
	}
	{
		int sum = 0;
		for(auto &it: mpb) {
			sum += it.second;
			it.second = sum;
		}
	}

	for(int i = 1; i <= N; i++) {
		level &l = levels[i];
		l.bm = mpb[l.b]--;
		revb[l.bm] = l.b;
		upd(l.bm, +1);
	}

	ll suma = 0;
	for(int ones = 0; ones <= W; ) {
		//    
		if((W - ones) % 2 == 0) {
			int x = get_kth((W - ones) / 2);
			node q = get(1, x);
			if(q.c == (W - ones) / 2) {
				ll val = suma + q.s;
				if(ans > val) ans = val, ans_ones = ones;
			}
		}

		if(ones == W || pq.empty()) break;

		ones++;

		pii t = pq.top(); pq.pop();
		int c = t.first, p = t.second;

		if(p > 0) {
			suma += c;
			upd(levels[p].bm, -1);
			pq.push(pii(levels[p].b - levels[p].a, -p));
		}else {
			suma += c;
		}
	}

	// 
	for(int i = 0; i < LEAF+LEAF; i++) tree[i] = node();
	while(!pq.empty()) pq.pop();
	fill(scenario+1, scenario+N+1, '0');

	for(int i = 1; i <= N; i++) {
		level &l = levels[i];
		pq.push(pii(l.a, i));
		upd(l.bm, +1);
	}

	suma = 0;
	for(int ones = 0; ones <= W; ) {
		//    
		if(ones == ans_ones) {
			priority_queue<pii, vector<pii>, greater<pii> > pq2;
			for(int i = 1; i <= N; i++) if(scenario[i] == '0') pq2.push(pii(levels[i].b, i));

			int ch = (W - ones) / 2;
			while(ch--) {
				pii t = pq2.top(); pq2.pop();
				scenario[t.second] = '2';
			}

			printf("%lld\n%s\n",ans, scenario+1);
			return 0;
		}

		if(ones == W || pq.empty()) break;

		ones++;

		pii t = pq.top(); pq.pop();
		int c = t.first, p = t.second;
		level &l = levels[p];

		if(p > 0) {
			suma += c;
			upd(l.bm, -1);
			pq.push(pii(l.b - l.a, -p));
			scenario[p] = '1';
		}else {
			suma += c;
			scenario[-p] = '2';
		}
	}
    return 0;
}