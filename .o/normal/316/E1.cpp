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

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
const int INF = 987654321; 
const ll LINF = 1e15;  

const int N_ = 262145; 
const int LEAF = 262143; 
const int TN_ = LEAF + N_;
const int MOD = 1000000000;  

int MD(ll a){ a %= MOD; return (a + (ll)MOD * 10000) % MOD; } 
int PLUS (ll a, ll b) { return (MD(a) + MD(b)) % MOD; } 
int MUL (ll a, ll b) { return ((ll)MD(a) * MD(b)) % MOD; }  

int N, M, A[LEAF+5];
ll Fib[N_] = {1, 1}, SFib[N_] = {1, 2};

ll fib (ll f0, ll f1, ll n) {
	if(n == 0) return f0;
	if(n == 1) return f1;
	return PLUS( MUL(f0, Fib[n - 2]), MUL(f1, Fib[n - 1]) );
}

void precalc() {
	for(int i = 2; i < N_; i++) {
		Fib[i] = PLUS(Fib[i - 1], Fib[i - 2]);
		SFib[i] = PLUS(SFib[i - 1], Fib[i]);
	}
}

namespace Query {
	ll s0[TN_], s1[TN_], pl[TN_];

	void mergeNode (int nd, int nl, int nr) {
		int len = nr - nl + 1;
		if(nd <= LEAF) {
			s0[nd] = PLUS( s0[nd + nd], fib(s0[nd + nd + 1], s1[nd + nd + 1], len / 2) );
			s0[nd] = PLUS( s0[nd], MUL( pl[nd], SFib[len - 1] ) );
			s1[nd] = PLUS( s1[nd + nd], fib(s0[nd + nd + 1], s1[nd + nd + 1], len / 2 + 1) );
			s1[nd] = PLUS( s1[nd], MUL( pl[nd], SFib[len] - 1 ) );
		}else {
			s0[nd] = s1[nd] = PLUS(A[nl], pl[nd]);
		}
	}

	void spreadNode (int nd, int nl, int nr) {
		int nm = (nl + nr) >> 1, len = nr - nl + 1;

		if(nd > LEAF) return;

		pl[nd + nd] = PLUS(pl[nd + nd], pl[nd]);
		mergeNode(nd + nd, nl, nm);

		pl[nd + nd + 1] = PLUS(pl[nd + nd + 1], pl[nd]);
		mergeNode(nd + nd + 1, nm + 1, nr);

		pl[nd] = 0;
		mergeNode(nd, nl, nr);
	}

	void build (int nd, int nl, int nr) {
		if(nd >= TN_ || nl > nr) return;

		if(nl == nr) {
			s0[nd] = s1[nd] = A[nl];
			return;
		}

		int mid = (nl + nr) >> 1;
		build (nd * 2, nl, mid);
		build (nd * 2 + 1, mid + 1, nr);
		
		mergeNode (nd, nl, nr);
	}

	void modify (int nd, int nl, int nr, int &x, int &v) {
		int nm = (nl + nr) >> 1;
		
		if(nl > nr || nd >= TN_) return;

		if(nl == nr) {
			s0[nd] = s1[nd] = A[x] =v;
			pl[nd] = 0;
			return;
		}

		spreadNode(nd, nl, nr);

		if(nl <= x && x <= nm) { 
			modify (nd+nd, nl, nm, x, v);
		}else if(nm < x && x <= nr) {
			modify (nd+nd+1, nm+1, nr, x, v);
		}else {
			const int MODIFY_ERROR = 0;
			assert(MODIFY_ERROR);
		}

		mergeNode (nd, nl, nr);
	}

	int added; ll ret;

	void getSum (int nd, int nl, int nr, int l, int r) {
		int nm = (nl + nr) >> 1, len = nr - nl + 1;
		
		if(l > r || nl > nr || nd >= TN_) return;
		
		if(l <= nl && nr <= r) {
			ret = PLUS(ret, fib(s0[nd], s1[nd], added));
			added += len;
			return;
		}

		spreadNode(nd, nl, nr);
		getSum(nd+nd, nl, nm, l, min(nm, r));
		getSum(nd+nd+1, nm + 1, nr, max(nm + 1, l), r);
		mergeNode(nd, nl, nr);
	}

	ll sum (int l, int r) {
		added = 0; ret = 0;
		getSum(1, 1, LEAF+1, l, r);
		return ret;
	}

	void add (int nd, int nl, int nr, int l, int r, int &d) {
		int nm = (nl + nr) >> 1, len = nr - nl + 1;

		if(l > r || nl > nr || nd >= TN_) return;
		
		if(l <= nl && nr <= r) {
			pl[nd] = PLUS(pl[nd], d);
			mergeNode(nd, nl, nr);
			return;
		}

		spreadNode(nd, nl, nr);
		add (nd+nd, nl, nm, l, min(nm, r), d);
		add (nd+nd+1, nm + 1, nr, max(nm + 1, l), r, d);
		mergeNode(nd, nl, nr);
	}
};

int main() {
	int i, j, k;
	
	precalc();

	scanf("%d%d", &N, &M);
	for(i = 1; i <= N; i++) scanf("%d", A+i);

	Query::build (1, 1, LEAF+1);
	
	while(M--) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int x, v; scanf("%d%d", &x, &v);
			Query::modify(1, 1, LEAF+1, x, v);
		}else if(t == 2) {
			int l, r; scanf("%d%d", &l, &r);
			printf("%I64d\n", Query::sum(l, r) % MOD);
		}else if(t == 3) {
			int l, r, d; scanf("%d%d%d", &l, &r, &d);
			Query::add (1, 1, LEAF+1, l, r, d);
		}
	}
	return 0;
}