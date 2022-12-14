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

const int N_ = 100005;
const int LEAF = 131071;
int N, Q;
int A[N_], B[N_];

int Tree[N_ + LEAF];
int QX[N_], QY[N_];

void update (int l, int r, int v) {
	l += LEAF; r += LEAF;
	while(l <= r) {
		if((l & 1) == 1) Tree[l] = max(Tree[l], v);
		if((r & 1) == 0) Tree[r] = max(Tree[r], v);
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
}

int get (int x) {
	int ret = 0; x += LEAF;
	while(x > 0) {
		ret = max(ret, Tree[x]);
		x >>= 1;
	}
	return ret;
}

int main() {
	int i;

	scanf("%d%d", &N, &Q);
	for(i = 1; i <= N; i++) scanf("%d", A+i);
	for(i = 1; i <= N; i++) scanf("%d", B+i);

	for(i = 1; i <= Q; i++) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int x, y, k; scanf("%d%d%d", &x, &y, &k);
			update(y, y+k-1, i); 
			QX[i] = y; QY[i] = x;
		}else if(t == 2){
			int x; scanf("%d", &x);
			int q = get(x);
			if(q == 0) printf("%d\n", B[x]);
			else printf("%d\n", A[x - QX[q] + QY[q]]);
		}
	}
	return 0;
}