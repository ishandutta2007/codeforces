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
#include <limits.h>//
#include <time.h>
#include <functional>
#include <numeric>
 ////
using namespace std;
typedef long long ll;
typedef unsigned long long llu;//////
typedef double lf;////
typedef unsigned int uint;
typedef long double llf;//
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int N, M;

struct node {
	int a;
	lf x, y;
	node(int a = 0, lf x = 0, lf y = 0): a(a), x(x), y(y) { }
};

const int LEAF = 524288;
node tree[LEAF + LEAF];
int L[LEAF];
/*
(cos  -sin) (x)   (x')
(sin   cos) (y) = (y')
// http://j1w2k3.tistory.com/651
*///

const double DEG_TO_RAD = acos(-1) / 180.;
lf mycos[360], mysin[360];//


node merge (node p, node q) {
	node ret;
	ret.x = p.x + (mycos[p.a] * q.x - mysin[p.a] * q.y);
	ret.y = p.y + (mysin[p.a] * q.x + mycos[p.a] * q.y);
	ret.a = (p.a + q.a) % 360;
	return ret;
}//

void upd (int x, node v) {
	tree[x += LEAF] = v;
	while(x >>= 1) tree[x] = merge(tree[x+x], tree[x+x+1]);
}

int main() {
	for(int a = 0; a < 360; a++) {//
		mycos[a] = cos(a * DEG_TO_RAD);//
		mysin[a] = sin(a * DEG_TO_RAD);
	}

	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		L[i] = 1;//
		upd(i, node(0, 1.0, 0.0));
	}

	while(M--) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		node &cur = tree[y + LEAF];
		if(x == 1) {
			L[y] += z;
		}else {
			cur.a = (cur.a - z + 360) % 360;//
		}//
		cur.x = L[y] * mycos[cur.a];
		cur.y = L[y] * mysin[cur.a];
		upd(y, cur);//

		printf("%.10lf %.10lf\n", tree[1].x, tree[1].y);
	}

    return 0;
}