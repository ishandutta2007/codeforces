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

const int N_ = 100500;

int N;
int H[N_], P[N_];
int rev_mph[N_]; int C;

struct state {
	int opt_pref;
	int opt_suff;
	int opt;
	int length;

	state(int length = 0, int opt_pref = 0, int opt_suff = 0, int opt = 0):
		opt_pref(opt_pref), opt_suff(opt_suff), opt(opt), length(length) {} 

	void print() {
		debug("%d %d %d %d\n",opt,opt_pref,opt_suff,length);
	}
};

state merge (state l, state r) {
	state ret;
	ret.opt_pref = (l.opt_pref < l.length) ? l.opt_pref : (l.length + r.opt_pref);
	ret.opt_suff = (r.opt_suff < r.length) ? r.opt_suff : (r.length + l.opt_suff);
	ret.opt = max(max(l.opt, r.opt), l.opt_suff + r.opt_pref);
	ret.length = l.length + r.length;
	return ret;
}

int positions[N_];

struct node {
	state s;
	node *left, *right;
	node(state s = state(), node *left = NULL, node *right = NULL):
		s(s), left(left), right(right) { }
};

node nodes[N_ * 20];

int num_nodes;

node* new_node(node *t = NULL) {
	num_nodes++;
	if(t != NULL) nodes[num_nodes] = *t;
	return nodes + num_nodes;
}

int *pos;
void ins (node *nd, int nl, int nr) {
	(nd->s).length = nr - nl + 1;
	
	if(nl == nr) {
		nd->s = state(1, 1, 1, 1);
		pos++;
		return;
	}

	int nm = (nl + nr) >> 1;

	if(nl <= *pos && *pos <= nm) {
		nd->left = new_node(nd->left);
		ins(nd->left, nl, nm);
	}

	if(nm+1 <= *pos && *pos <= nr) {
		nd->right = new_node(nd->right);
		ins(nd->right, nm+1, nr);
	}

	state sl = (nd->left  == NULL) ? state(nm-nl+1) : nd->left->s;
	state sr = (nd->right == NULL) ? state(nr-nm)   : nd->right->s;
	nd->s = merge(sl, sr);

}

int rec;
inline state get (node *nd, int nl, int nr, int ql, int qr) {
	++rec;
	if(ql > qr || ql > nr || qr < nl) return state();
	
	if(nd == NULL) {
		return state(qr - ql + 1);
	}

	if(nl == ql && nr == qr) {
		return nd->s;
	}

	int nm = (nl + nr) >> 1;
	return merge(
		get(nd->left, nl, nm, ql, min(qr, nm)), 
		get(nd->right, nm+1, nr, max(ql, nm+1), qr)
	);
}

int M;

node *root[N_];

int main() {
	scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		scanf("%d", H+i);
		P[i] = i;
	}

	stable_sort(P+1, P+N+1, [](const int &a, const int &b) {
		return H[a] > H[b];
	});

	root[0] = new_node();

	for(int i = 1; i <= N; ) {
		int j = i;
		while(j <= N && H[P[i]] == H[P[j]]) ++j;
		++C;
		rev_mph[C] = H[P[i]];
		root[C] = new_node(root[C-1]);

		int pn = 0;
		for(; i < j; i++) positions[pn++] = P[i];
		sort(positions, positions + pn);
		positions[pn] = -1;
		pos = positions;

		ins(root[C], 1, N);
	}

	scanf("%d", &M);

	while(M--) {
		int l, r, w; scanf("%d%d%d", &l, &r, &w);

		int low = 1, high = C, ans = 0;
		while(low <= high) { //     ,     
			int mid = (low + high) >> 1;
			rec= 0;
			state ret = get(root[mid], 1, N, l, r);
			//fprintf(stderr,"%d\n",rec);
			//assert(r - l + 1 == ret.length);
			if(ret.opt >= w) {
				ans = mid;
				high = mid - 1;
			}else {
				low = mid + 1;
			}
		}

		printf("%d\n", rev_mph[ans]);
	}

	return 0;
}