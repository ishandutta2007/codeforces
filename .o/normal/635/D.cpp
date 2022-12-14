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

int N, K, A, B, Q;

const int LEAF = 131072 * 2;

struct segmentTree {
	ll bound;
	ll tree[LEAF + LEAF];

	void upd (int x, ll v) {
		tree[x += LEAF] = min(v, bound);
		while(x >>= 1) tree[x] = tree[x+x] + tree[x+x+1];
	}

	ll get (int x, int y) {
		ll ret = 0;
		x += LEAF; y += LEAF;
		while(x <= y) {
			if( x & 1) ret += tree[x];
			if(~y & 1) ret += tree[y];
			x = (x+1) >> 1;
			y = (y-1) >> 1;
		}
		return ret;
	}
} sega, segb;

const int N_ = 200500;
ll numOrders[N_];

int main() {
	scanf("%d%d%d%d%d", &N, &K, &A, &B, &Q);
	sega.bound = A;
	segb.bound = B;

	for(int q = 1; q <= Q; q++) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int d, a; scanf("%d%d", &d, &a);
			numOrders[d] += a;
			sega.upd(d, numOrders[d]);
			segb.upd(d, numOrders[d]);
		}else {
			int p; scanf("%d", &p);
			ll ret = segb.get(1, p-1) + sega.get(p+K, N);
			printf("%lld\n", ret);
		}
	}

    return 0;
}