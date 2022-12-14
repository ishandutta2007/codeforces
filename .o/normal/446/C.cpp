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

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 300105;
const ll MOD = (int)(1e9) + 9;

const int L = 524288;

int N, Q;
int S[N_];
ll F[N_], SF[N_], F1[N_], F0[N_];
ll tree[L+L+1];
ll tf1[L+L+1], tf2[L+L+1];

ll fib (ll f1, ll f2, int n) {
	f1 %= MOD; f2 %= MOD;
	if(n == 1) return f1;
	if(n == 2) return f2;
	return (f1 * F[n-2] + f2 * F[n-1]) % MOD;
}

ll fibsum (ll f1, ll f2, int n) {
	if(n <= 0) return 0;
	if(n == 1) return f1 % MOD;
	if(n == 2) return (f1 + f2) % MOD;
	if(f1 == 0 && f2 == 0) return 0;
	if(f1 == 0) return fibsum(f2, f2, n-1);
	if(f2 == 0) return (fibsum(0, f1, n-1) + f1) % MOD; // 5 0 5 5 10 15 25 .
	f1 %= MOD; f2 %= MOD;
	return (f1 * F[n] + f2 * (F[n+1]-1+MOD)) % MOD;
}

void spread (int nd, int len) {
	if(nd >= L) return;
	ll lp = fibsum(tf1[nd], tf2[nd], len >> 1);
	ll rp = fibsum(tf1[nd], tf2[nd], len);
	tree[nd+nd] += lp; tree[nd+nd] %= MOD;
	tree[nd+nd+1] += rp - lp + MOD; tree[nd+nd+1] %= MOD;
	tf1[nd+nd] += tf1[nd]; tf1[nd+nd] %= MOD;
	tf2[nd+nd] += tf2[nd]; tf2[nd+nd] %= MOD;
	tf1[nd+nd+1] += fib(tf1[nd], tf2[nd], len/2 + 1); tf1[nd+nd+1] %= MOD;
	tf2[nd+nd+1] += fib(tf1[nd], tf2[nd], len/2 + 2); tf2[nd+nd+1] %= MOD;
	tf1[nd] = tf2[nd] = 0;
}

void update (int nd, int nl, int nr, int x, int y, int qx, int qy) {
	int nm = (nl + nr) >> 1;
	if(x <= nl && nr <= y) {
		tf1[nd] += F[nl-qx+1]; tf1[nd] %= MOD;
		tf2[nd] += F[nl-qx+2]; tf2[nd] %= MOD;
		tree[nd] += SF[nr-qx+1] - SF[nl-qx];
		tree[nd] += MOD;
		tree[nd] %= MOD;
		return;
	}
	spread(nd, nr-nl+1);
	if(x <= nm) update(nd+nd, nl, nm, x, min(nm, y), qx, qy);
	if(y  > nm) update(nd+nd+1, nm+1, nr, max(nm+1, x), y, qx, qy);
	tree[nd] = (tree[nd+nd] + tree[nd+nd+1]) % MOD;
}

ll get (int nd, int nl, int nr, int x, int y) {
	if(x <= nl && nr <= y) return tree[nd];
	int nm = (nl + nr) >> 1;
	ll ret = 0;
	spread(nd, nr-nl+1);
	if(x <= nm) ret += get(nd+nd, nl, nm, x, min(nm, y));
	if(y  > nm) ret += get(nd+nd+1, nm+1, nr, max(nm+1, x), y);
	return ret % MOD;
}

int main() {
	
	scanf("%d", &N);
	scanf("%d", &Q);
	for(int i = 1; i <= N; i++) {
		scanf("%d", S+i); S[i] += S[i-1]; S[i] %= MOD;
	}

	F0[0] = 1;
	F1[1] = 1;

	for(int i = 1; i < N_; i++) {
		if(i >= 3) F[i] = (F[i-1] + F[i-2]) % MOD; else F[i] = 1;
		if(i >= 2) F1[i] = (F1[i-1] + F1[i-2]) % MOD, F0[i] = (F0[i-1] + F0[i-2]) % MOD;
		SF[i] = (SF[i-1] + F[i]) % MOD;
	}
	
	while(Q--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if(t == 1) {
			update(1, 1, L, l, r, l, r);
		}else {
			ll ans = (S[r] - S[l-1] + MOD) % MOD;
			ans += get(1, 1, L, l, r);
			ans %= MOD;
			printf("%I64d\n", ans);
		}
	}

	return 0;
}