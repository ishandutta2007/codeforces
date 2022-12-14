#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N, Q;

const int LEAF = 1 << 20;

const int Q_ = 200500;
int X[Q_], Y[Q_], D[Q_], XS[Q_], YS[Q_];

set<int> S;
map<int, int> R;

int treeX[LEAF + LEAF];
int treeY[LEAF + LEAF];

void upd(int *tree, int x, int y, int v) {
	x += LEAF; y += LEAF;
	while (x <= y) {
		if ((x & 1) == 1) tree[x] = max(tree[x], v);
		if ((y & 1) == 0) tree[y] = max(tree[y], v);
		x = (x + 1) >> 1;
		y = (y - 1) >> 1;
	}
}

int get(int *tree, int x) {
	int ret = tree[x += LEAF];
	while (x >>= 1) ret = max(tree[x], ret);
	return ret;
}

bool chkX[LEAF], chkY[LEAF];

int main() {
#ifndef ONLINE_JUDGE
	freopen("555C.in", "r", stdin);
	freopen("555C.out", "w", stdout);
#endif

	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= Q; i++) {
		int x, y; char d[3];
		scanf("%d%d%s", &x, &y, d);
		X[i] = x; Y[i] = y; D[i] = d[0];
		S.insert(x); S.insert(x + 1);
		S.insert(y); S.insert(y + 1);
	}

	int c = 0;
	for (auto x : S) R[x] = ++c;
	
	for (int i = 1; i <= Q; i++) {
		int x = X[i], y = Y[i], d = D[i];
		int xr = R[x], yr = R[y];

		int ret = 0;

		if (d == 'L') {
			if (!chkY[yr]) {
				chkY[yr] = true;
				int p = get(treeY, yr);
				upd(treeX, R[p + 1], xr, y);
				ret = x - p;
			}
		}
		else if (d == 'U') {
			if (!chkX[xr]) {
				chkX[xr] = true;
				int p = get(treeX, xr);
				upd(treeY, R[p + 1], yr, x);
				ret = y - p;
			}
		}

		printf("%d\n", ret);
	}



	return 0;
}