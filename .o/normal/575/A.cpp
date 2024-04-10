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

const int N_ = 50050, M_ = 50050;

ll K, P;
int N, S[N_];
int M; pli W[M_];

struct matrix {
	ll val[2][2];
	matrix(){ memset(val, 0, sizeof val); }
	ll* operator[] (int v){ return val[v]; }

	matrix operator* (matrix m) {
		matrix ret;
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) {
			for(int k = 0; k < 2; k++) ret[i][j] = (ret[i][j] + val[i][k] * m[k][j]) % P;
		}
		return ret;
	}
};

const int LEAF = 131072;
matrix I;
matrix tree[LEAF + LEAF + 5];

matrix power (matrix base, ll rep) {
	matrix ret = I;
	while(rep > 0) {
		if(rep & 1) ret = ret * base;
		base = base * base;
		rep >>= 1;
	}
	return ret;
}

matrix allprod;

matrix getprod (ll l, ll r) {
	if(l > r) return I;

	matrix retl = I, retr = I;

	// l, r 
	{
		ll c = l / N * N; l -= c; r -= c;

		ll rb = r / N - 1;
		if(rb >= 1) {
			return getprod(l, N-1) * power(allprod, rb) * getprod(0, r % N);
		}
	}

	l += LEAF; r += LEAF;
	while(l <= r) {
		if((l & 1) == 1) retl = retl * tree[l];
		if((r & 1) == 0) retr = tree[r] * retr;
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return retl * retr;
}

map<ll, int> mpS;
int getS(ll p) {
	auto it = (mpS.find(p));
	if(it != mpS.end()) return it->second;
	return S[p % N] % P;
}

int main() {
	scanf("%lld%lld", &K, &P);
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", S+i), S[i] %= P;
	scanf("%d", &M);
	for(int i = 0; i < M; i++) {
		scanf("%lld%d", &W[i].first, &W[i].second);
		W[i].second %= P;
		mpS[W[i].first] = W[i].second;
	}

	W[M++] = pli(K, S[K % N]);
	sort(W, W+M);

	if(P == 1) return 0 & puts("0");
	if(K == 0) return 0 & printf("%lld\n", 0 % P);
	if(K == 1) return 0 & printf("%lld\n", 1 % P);

	I[0][0] = I[1][1] = 1;

	for(int i = 0; i <= LEAF+LEAF; i++) tree[i] = I;
	for(int i = 0; i < N+N; i++) {
		matrix &m = tree[i+LEAF];
		m[0][0] = 0;
		m[0][1] = S[i % N];
		m[1][0] = 1;
		m[1][1] = S[(i+1) % N];
	}

	for(int i = LEAF-1; i > 0; i--) {
		tree[i] = tree[i+i] * tree[i+i+1];
	}

	allprod = getprod(0, N-1);

	matrix curm = I;
	ll curk = 0;

	for(int i = 0; i < M; i++) {
		ll k = W[i].first; int s = W[i].second;
		// curk -> k
		if(curk <= k-2) {
			{
				matrix t;
				t[0][0] = 0; t[0][1] = getS(curk);
				t[1][0] = 1; t[1][1] = getS(curk+1);
				curm = curm * t;
				++curk;
			}
			curm = curm * getprod(curk, k-2);
		}

		{
			matrix t;
			t[0][0] = 0; t[0][1] = getS(k-1);
			t[1][0] = 1; t[1][1] = s;
			curm = curm * t;
		}

		curk = k;
		if(curk == K) break;
	}
	printf("%lld\n", curm[1][0] % P);



    return 0;
}