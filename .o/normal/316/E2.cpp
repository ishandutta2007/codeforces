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
const int TN_ = LEAF + LEAF + 10;
const int MOD = 1000000000;  

inline int MD(ll a){ while(a >= MOD) a -= MOD; return a; } 
inline int PLUS (ll a, ll b) { int T = MD(a) + MD(b); if(T >= MOD) T -= MOD; return T; } 
inline int MUL (ll a, ll b) { return ((ll)MD(a) * MD(b)) % MOD; }  

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
	
	inline void mergeNodeA (int nd, int len) {
		if(nd <= LEAF) {
			s0[nd] = PLUS( s0[nd + nd], fib(s0[nd + nd + 1], s1[nd + nd + 1], len / 2) );
			s1[nd] = PLUS( s1[nd + nd], fib(s0[nd + nd + 1], s1[nd + nd + 1], len / 2 + 1) );
		}else {
			s0[nd] = s1[nd] = PLUS(A[nd - LEAF], pl[nd]);
		}
	}
	
	inline void mergeNodeB (int nd, int len) {
		if(nd <= LEAF) {
			s0[nd] = PLUS( s0[nd], MUL( pl[nd], SFib[len - 1] ) );
			s1[nd] = PLUS( s1[nd], MUL( pl[nd], SFib[len] - 1 ) );
		}else {
			s0[nd] = s1[nd] = PLUS(A[nd - LEAF], pl[nd]);
		}
	}

	inline void mergeNode (int nd, int nl, int nr) {
		int len = nr - nl + 1;
		if(nd <= LEAF) {
			mergeNodeA (nd, len);
			mergeNodeB (nd, len);
		}else {
			s0[nd] = s1[nd] = PLUS(A[nl], pl[nd]);
		}
	}

	inline void spreadNode (int nd, int nl, int nr) {
		int nm = (nl + nr) >> 1, len = nr - nl + 1;

		if(nd > LEAF) return;

		pl[nd+nd] = PLUS(pl[nd+nd], pl[nd]);
		mergeNodeB (nd+nd, len >> 1);

		pl[nd+nd+1] = PLUS(pl[nd+nd+1], pl[nd]);
		mergeNodeB (nd+nd+1, len >> 1);

		pl[nd] = 0;
		//mergeNode(nd, nl, nr);
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
		
		mergeNodeA (nd, nr - nl + 1);
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

		mergeNodeA (nd, nr - nl + 1);
	}

	int added; ll ret;

	void getSum (int nd, int nl, int nr, int l, int r) {
		int nm = (nl + nr) >> 1, len = nr - nl + 1;
		
		if(l > r || nl > nr || nd >= TN_) return;
		spreadNode(nd, nl, nr);
		
		if(l <= nl && nr <= r) {
			ret = PLUS(ret, fib(s0[nd], s1[nd], added));
			added += len;
			return;
		}

		getSum(nd+nd, nl, nm, l, min(nm, r));
		getSum(nd+nd+1, nm + 1, nr, max(nm + 1, l), r);
		mergeNodeA(nd, nr - nl + 1);
	}

	inline ll sum (int l, int r) {
		added = 0; ret = 0;
		getSum(1, 1, LEAF+1, l, r);
		return ret;
	}

	void add (int nd, int nl, int nr, int l, int r, int &d) {
		int nm = (nl + nr) >> 1, len = nr - nl + 1;

		if(l > r || nl > nr || nd >= TN_) return;
		
		if(l <= nl && nr <= r) {
			pl[nd] = PLUS(pl[nd], d);
			mergeNodeB(nd, len);
			return;
		}

		spreadNode(nd, nl, nr);
		add (nd+nd, nl, nm, l, min(nm, r), d);
		add (nd+nd+1, nm + 1, nr, max(nm + 1, l), r, d);
		mergeNodeB(nd, len);
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
			Query::modify(1, 1, LEAF+1, x, v); //
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