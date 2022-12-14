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

const int N_ = 5030;
const int MAXC = N_ * 2;

int N, Q;

struct Fenwick2D {
	int tree[MAXC+5][N_];
	int x_min;

	void upd (int r, int c, int d) {
		r -= x_min; r += 1; c += 1;
		assert(r >= 0 && c > 0);

		for(int i = r; i < MAXC; i += i & -i) {
			for(int j = c; j <= N+10; j += j & -j) {
				tree[i][j] += d;
			}
		}
	}

	void upd (int r1, int r2, int c1, int c2, int d) {
		// [r1, r2] x [c1, c2] update
		if(r1 > r2) return;
		assert(c1 <= c2);

		upd(r1, c1, +d);
		upd(r1, c2+1, -d);
		upd(r2+1, c1, -d);
		upd(r2+1, c2+1, +d);
	}

	int get (int r, int c) {
		r -= x_min; r += 1; c += 1;
		if(r == 0 || c == 0) return 0;

		int ret = 0;
		for(int i = r; i > 0; i -= i & -i) {
			for(int j = c; j > 0; j -= j & -j) {
				ret += tree[i][j];
			}
		}
		return ret;
	}

	void init() {
		memset(tree, 0, sizeof tree);
	}
};

Fenwick2D fenwick;

const int Q_ = 100500;
tuple<int, int, int, int, int> queries[Q_];
int ans[Q_];

int main() {
	scanf("%d%d", &N, &Q);

	fenwick.init();
	for(int i = 1; i <= Q; i++) {
		int t, dir = -1, x, y, len = -1; scanf("%d", &t);
		if(t == 1) {
			scanf("%d%d%d%d", &dir, &x, &y, &len);
			if(dir == 1) {
				fenwick.upd(1, x-1, y, y+len, -1);
			}else if(dir == 2) {
				fenwick.upd(1, x-1, y-len, y, -1);
			}else if(dir == 3) {
				fenwick.upd(x+1, N, y, y+len, -1);
			}else if(dir == 4) {
				fenwick.upd(x+1, N, y-len, y, -1);
			}
		}else {
			scanf("%d%d", &x, &y);
			ans[i] += fenwick.get(x, y);
		}
		queries[i] = tie(t, dir, x, y, len);
	}
/*
			if(dir == 1) {
				tree_diag[0].upd(1, x+y+len, y, y+len, +1);
				tree_rect.upd(1, x-1, y, y+len, -1);
			}else if(dir == 2) {
				tree_diag[1].upd(1-N, x-y+len, y-len, y, +1);
				tree_rect.upd(1, x-1, y-len, y, -1);
			}else if(dir == 3) {
				tree_diag[2].upd(1-N, y-x+len, y, y+len, +1);
				tree_rect.upd(x+1, N, y, y+len, -1);
			}else if(dir == 4) {
				tree_diag[3].upd(-N-N, -x-y+len, y-len, y, +1);
				tree_rect.upd(x+1, N, y-len, y, -1);
			}
		}else {
			int x, y; scanf("%d%d", &x, &y);
			int ans = 0;
			printf("%d\n", ans);
		}*/

	for(int cur_dir = 1; cur_dir <= 4; cur_dir++) {
		fenwick.x_min = (cur_dir == 2 || cur_dir == 3) ? (1-N) : ((cur_dir == 4) ? (-N-N) : 0);
		fenwick.init();
		for(int i = 1; i <= Q; i++) {
			int t, dir, x, y, len; tie(t, dir, x, y, len) = queries[i];
			if(t == 1) {
				if(cur_dir != dir) continue;
				if(dir == 1) {
					fenwick.upd(1, x+y+len, y, y+len, +1);
				}else if(dir == 2) {
					fenwick.upd(1-N, x-y+len, y-len, y, +1);
				}else if(dir == 3) {
					fenwick.upd(1-N, y-x+len, y, y+len, +1);
				}else if(dir == 4) {
					fenwick.upd(-N-N, -x-y+len, y-len, y, +1);
				}
			}else {
				if(cur_dir == 1) ans[i] += fenwick.get(x+y, y);
				if(cur_dir == 2) ans[i] += fenwick.get(x-y, y);
				if(cur_dir == 3) ans[i] += fenwick.get(y-x, y);
				if(cur_dir == 4) ans[i] += fenwick.get(-x-y, y);
			}
		}
	}
	
	for(int i = 1; i <= Q; i++) {
		int t, dir, x, y, len; tie(t, dir, x, y, len) = queries[i];
		if(t == 2) printf("%d\n", ans[i]);
	}
	return 0;
}